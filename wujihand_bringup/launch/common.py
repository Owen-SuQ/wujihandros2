"""Common launch utilities for WujiHand."""

import os

from ament_index_python.packages import get_package_share_directory
from launch.actions import DeclareLaunchArgument
from launch.substitutions import Command
from launch_ros.actions import Node


def get_robot_description_command(hand_name, hand_type):
    """Get Command substitution for robot_description.

    Uses separate xacro files for left/right hands with prefix support.

    Args:
        hand_name: LaunchConfiguration for hand namespace/prefix
        hand_type: LaunchConfiguration for hand type (left/right)

    Returns:
        Command substitution for xacro processing with prefix
    """
    wujihand_description_dir = get_package_share_directory("wujihand_description")
    # Use separate xacro files for left/right hands
    return Command(
        [
            "xacro ",
            wujihand_description_dir,
            "/urdf/",
            hand_type,
            ".urdf.xacro prefix:=",
            hand_name,
            "/",
        ]
    )


def get_robot_state_publisher_node(hand_name, hand_type):
    """Create robot_state_publisher node with URDF processing.

    Args:
        hand_name: LaunchConfiguration for hand namespace/prefix
        hand_type: LaunchConfiguration for hand type (left/right)

    Returns:
        Node action for robot_state_publisher
    """
    robot_description_content = get_robot_description_command(hand_name, hand_type)

    return Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        name="robot_state_publisher",
        namespace=hand_name,
        parameters=[{"robot_description": robot_description_content}],
        output="screen",
        emulate_tty=True,
    )


def get_common_launch_arguments():
    """Return common launch argument declarations.

    Returns:
        List of DeclareLaunchArgument actions
    """
    return [
        DeclareLaunchArgument(
            "hand_name",
            default_value="hand_0",
            description="Hand name used as namespace and URDF prefix",
        ),
        DeclareLaunchArgument(
            "hand_type",
            default_value="auto",
            description="Hand type: 'left', 'right', or 'auto' (detect from hardware)",
        ),
        DeclareLaunchArgument(
            "serial_number",
            default_value="",
            description="Serial number of the WujiHand device",
        ),
        DeclareLaunchArgument(
            "publish_rate",
            default_value="1000.0",
            description="Joint state publish rate in Hz",
        ),
        DeclareLaunchArgument(
            "filter_cutoff_freq",
            default_value="10.0",
            description="Low-pass filter cutoff frequency in Hz",
        ),
        DeclareLaunchArgument(
            "diagnostics_rate",
            default_value="10.0",
            description="Diagnostics publish rate in Hz",
        ),
    ]
