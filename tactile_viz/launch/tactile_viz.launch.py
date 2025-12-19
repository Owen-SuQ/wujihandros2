"""
Launch file for tactile visualization

Starts:
- tactile_viz_node: Reads tactile data and publishes MarkerArray
- rviz2: 3D visualization with pre-configured display
"""

import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    # Get package share directory
    pkg_share = get_package_share_directory('tactile_viz')

    # Paths to config files
    config_file = os.path.join(pkg_share, 'config', 'point_positions.yaml')
    rviz_config = os.path.join(pkg_share, 'rviz', 'tactile_display.rviz')

    # Declare launch arguments
    use_rviz_arg = DeclareLaunchArgument(
        'use_rviz',
        default_value='true',
        description='Whether to launch RViz'
    )

    # Tactile visualization node
    tactile_viz_node = Node(
        package='tactile_viz',
        executable='tactile_viz_node',
        name='tactile_viz_node',
        output='screen',
        parameters=[config_file],
    )

    # RViz node
    rviz_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        output='screen',
        arguments=['-d', rviz_config],
        condition=IfCondition(LaunchConfiguration('use_rviz'))
    )

    return LaunchDescription([
        use_rviz_arg,
        tactile_viz_node,
        rviz_node,
    ])
