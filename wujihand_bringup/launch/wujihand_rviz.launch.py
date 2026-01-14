"""Launch WujiHand driver with RViz for visualization.

Supports single or multiple hands with auto-detection.

Usage:
    # Auto-detect all connected devices
    ros2 launch wujihand_bringup wujihand_rviz.launch.py

    # Single hand with serial number
    ros2 launch wujihand_bringup wujihand_rviz.launch.py hands:=347B38773433

    # Two hands with custom names
    ros2 launch wujihand_bringup wujihand_rviz.launch.py hands:=left:SN1,right:SN2
"""

import os
import sys

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import OpaqueFunction, TimerAction
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

# Add launch directory to path for local imports
sys.path.insert(0, os.path.dirname(__file__))
from common import (
    get_multi_hand_launch_arguments,
    parse_hands_config,
    spawn_robot_state_publisher_for_hand,
)


def create_driver_node(hand_name, serial_number, publish_rate, filter_cutoff_freq, diagnostics_rate):
    """Create a wujihand_driver node for a specific hand."""
    joint_prefix = f"{hand_name}/"
    return Node(
        package="wujihand_driver",
        executable="wujihand_driver_node",
        name="wujihand_driver",
        namespace=hand_name,
        parameters=[
            {
                "serial_number": serial_number,
                "joint_prefix": joint_prefix,
                "publish_rate": float(publish_rate),
                "filter_cutoff_freq": float(filter_cutoff_freq),
                "diagnostics_rate": float(diagnostics_rate),
            }
        ],
        output="screen",
        emulate_tty=True,
    )


def launch_setup(context):
    """Setup launch based on hands configuration."""
    hands_config = LaunchConfiguration("hands").perform(context)
    publish_rate = LaunchConfiguration("publish_rate").perform(context)
    filter_cutoff_freq = LaunchConfiguration("filter_cutoff_freq").perform(context)
    diagnostics_rate = LaunchConfiguration("diagnostics_rate").perform(context)

    # Parse hands configuration
    hands = parse_hands_config(hands_config)

    if not hands:
        from launch import logging
        logger = logging.get_logger(__name__)
        logger.error("No hands configured or detected. Please connect a device or specify hands parameter.")
        return []

    wujihand_description_dir = get_package_share_directory("wujihand_description")
    rviz_config = os.path.join(wujihand_description_dir, "rviz", "robot_display.rviz")

    actions = []

    # Create driver nodes for all hands
    for hand_name, serial_number in hands:
        actions.append(
            create_driver_node(
                hand_name, serial_number, publish_rate, filter_cutoff_freq, diagnostics_rate
            )
        )

    # Auto-detect handedness and spawn robot_state_publisher for each hand
    for hand_name, _ in hands:
        actions.append(
            TimerAction(
                period=2.0,
                actions=[OpaqueFunction(function=spawn_robot_state_publisher_for_hand(hand_name))],
            )
        )

    # RViz node (only one instance needed, uses first hand's namespace)
    first_hand_name = hands[0][0] if hands else "hand_0"
    actions.append(
        Node(
            package="rviz2",
            executable="rviz2",
            name="rviz2",
            namespace=first_hand_name,
            arguments=["-d", rviz_config],
            output="screen",
            emulate_tty=True,
        )
    )

    return actions


def generate_launch_description():
    return LaunchDescription(
        get_multi_hand_launch_arguments()
        + [
            OpaqueFunction(function=launch_setup),
        ]
    )
