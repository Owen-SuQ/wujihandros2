"""
Launch file for tactile filter demo

Starts the filter_demo_node to collect tactile data and compare filtering effects.
After collection, use the plot_filter_effect.py script to visualize results.

Usage:
    ros2 launch tactile_viz filter_demo.launch.py
    ros2 launch tactile_viz filter_demo.launch.py duration:=20.0 point_index:=17
"""

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    # Declare launch arguments
    duration_arg = DeclareLaunchArgument(
        'duration',
        default_value='10.0',
        description='Data collection duration in seconds'
    )

    sample_rate_arg = DeclareLaunchArgument(
        'sample_rate',
        default_value='100.0',
        description='Sample rate in Hz'
    )

    point_index_arg = DeclareLaunchArgument(
        'point_index',
        default_value='0',
        description='Tactile point index to visualize (0-35)'
    )

    smoothing_alpha_arg = DeclareLaunchArgument(
        'smoothing_alpha',
        default_value='0.3',
        description='EMA smoothing factor (0-1, lower = smoother)'
    )

    max_slope_arg = DeclareLaunchArgument(
        'max_slope',
        default_value='500.0',
        description='Max allowed slope for slope filter (N/s)'
    )

    # Filter demo node
    filter_demo_node = Node(
        package='tactile_viz',
        executable='filter_demo_node',
        name='filter_demo_node',
        output='screen',
        parameters=[{
            'collection_duration': LaunchConfiguration('duration'),
            'sample_rate': LaunchConfiguration('sample_rate'),
            'point_index': LaunchConfiguration('point_index'),
            'smoothing_alpha': LaunchConfiguration('smoothing_alpha'),
            'max_slope': LaunchConfiguration('max_slope'),
        }],
    )

    return LaunchDescription([
        duration_arg,
        sample_rate_arg,
        point_index_arg,
        smoothing_alpha_arg,
        max_slope_arg,
        filter_demo_node,
    ])
