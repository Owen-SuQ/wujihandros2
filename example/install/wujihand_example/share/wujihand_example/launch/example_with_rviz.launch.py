"""
Launch WujiHand example with RViz visualization.

This launch file starts:
1. robot_state_publisher - publishes TF from URDF
2. wujihand_example - wave motion demo
3. rviz2 - visualization

Prerequisites:
- wujihand_driver must be running: ros2 run wujihand_driver wujihand_driver_node
"""

import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    # Get URDF path (use right hand URDF)
    urdf_path = os.path.join(
        get_package_share_directory("wujihand_description"),
        "urdf",
        "right-ros.urdf",
    )

    # Read URDF content
    with open(urdf_path, "r") as f:
        robot_description = f.read()

    # Robot state publisher
    robot_state_publisher = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        name="robot_state_publisher",
        parameters=[{"robot_description": robot_description}],
    )

    # WujiHand example node
    example_node = Node(
        package="wujihand_example",
        executable="wujihand_example",
        name="wujihand_example",
        output="screen",
    )

    # RViz config path
    rviz_config = os.path.join(
        get_package_share_directory("wujihand_description"),
        "rviz",
        "robot_display.rviz",
    )

    # RViz
    rviz_node = Node(
        package="rviz2",
        executable="rviz2",
        name="rviz2",
        arguments=["-d", rviz_config] if os.path.exists(rviz_config) else [],
    )

    return LaunchDescription(
        [
            robot_state_publisher,
            example_node,
            rviz_node,
        ]
    )
