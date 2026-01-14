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

    # Legacy single-hand mode (backward compatible)
    ros2 launch wujihand_bringup wujihand.launch.py hand_name:=hand_0 serial_number:=SN1
"""

import os
import sys

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction
from launch.substitutions import LaunchConfiguration, PythonExpression
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue

# Add launch directory to path for local imports
sys.path.insert(0, os.path.dirname(__file__))
from common import get_multi_hand_launch_arguments, parse_hands_config


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

    # Create driver nodes for all hands
    nodes = []
    for hand_name, serial_number in hands:
        nodes.append(
            create_driver_node(
                hand_name, serial_number, publish_rate, filter_cutoff_freq, diagnostics_rate
            )
        )

    return nodes


def generate_launch_description():
    return LaunchDescription(
        get_multi_hand_launch_arguments()
        + [
            OpaqueFunction(function=launch_setup),
        ]
    )
