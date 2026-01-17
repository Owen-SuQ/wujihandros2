"""Launch WujiHand driver with support for single or multiple hands.

Usage:
    # Auto-detect all connected devices
    ros2 launch wujihand_bringup wujihand.launch.py

    # Single hand with serial number
    ros2 launch wujihand_bringup wujihand.launch.py hands:=347B38773433

    # Single hand with custom name
    ros2 launch wujihand_bringup wujihand.launch.py hands:=left_hand:347B38773433

    # Two hands
    ros2 launch wujihand_bringup wujihand.launch.py hands:=hand_0:SN1,hand_1:SN2

    # With RViz visualization
    ros2 launch wujihand_bringup wujihand.launch.py rviz:=true

    # With Foxglove Bridge
    ros2 launch wujihand_bringup wujihand.launch.py foxglove:=true

    # Legacy single-hand mode (backward compatible)
    ros2 launch wujihand_bringup wujihand.launch.py hand_name:=hand_0 serial_number:=SN1
"""

import os
import sys

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction, TimerAction
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


def spawn_rviz_for_hand(hand_name):
    """Create a closure to spawn RViz for a specific hand."""

    def _spawn(context):
        rviz_enabled = LaunchConfiguration("rviz").perform(context)
        if rviz_enabled.lower() not in ["true", "1", "yes"]:
            return []

        wuji_hand_description_dir = get_package_share_directory("wuji_hand_description")
        rviz_config = os.path.join(
            wuji_hand_description_dir, "rviz", "robot_display.rviz"
        )

        return [
            Node(
                package="rviz2",
                executable="rviz2",
                name="rviz2",
                namespace=hand_name,
                arguments=["-d", rviz_config],
                output="screen",
            )
        ]

    return _spawn


def create_foxglove_bridge_for_hand(hand_name):
    """Create a closure to spawn Foxglove Bridge for a specific hand."""

    def _spawn(context):
        foxglove_enabled = LaunchConfiguration("foxglove").perform(context)
        if foxglove_enabled.lower() not in ["true", "1", "yes"]:
            return []

        return [
            Node(
                package="foxglove_bridge",
                executable="foxglove_bridge",
                name="foxglove_bridge",
                namespace=hand_name,
                output="screen",
            )
        ]

    return _spawn


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

    actions = []

    for hand_name, serial_number in hands:
        # Create driver node
        actions.append(
            create_driver_node(
                hand_name, serial_number, publish_rate, filter_cutoff_freq, diagnostics_rate
            )
        )

        # Create robot_state_publisher spawner with delay
        actions.append(
            TimerAction(
                period=2.0,
                actions=[OpaqueFunction(function=spawn_robot_state_publisher_for_hand(hand_name))],
            )
        )

        # Create RViz spawner with delay (if enabled)
        actions.append(
            TimerAction(
                period=3.0,
                actions=[OpaqueFunction(function=spawn_rviz_for_hand(hand_name))],
            )
        )

        # Create Foxglove Bridge spawner (if enabled)
        actions.append(
            TimerAction(
                period=2.5,
                actions=[OpaqueFunction(function=create_foxglove_bridge_for_hand(hand_name))],
            )
        )

    return actions


def generate_launch_description():
    return LaunchDescription(
        get_multi_hand_launch_arguments()
        + [
            DeclareLaunchArgument(
                "rviz",
                default_value="false",
                description="Whether to launch RViz for visualization",
            ),
            DeclareLaunchArgument(
                "foxglove",
                default_value="false",
                description="Whether to launch Foxglove Bridge for web visualization",
            ),
            OpaqueFunction(function=launch_setup),
        ]
    )
