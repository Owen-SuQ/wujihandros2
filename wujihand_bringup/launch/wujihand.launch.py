from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    serial_number_arg = DeclareLaunchArgument(
        "serial_number",
        default_value="",
        description="Serial number of the WujiHand device",
    )

    publish_rate_arg = DeclareLaunchArgument(
        "publish_rate", default_value="1000.0", description="State publish rate in Hz"
    )

    filter_cutoff_freq_arg = DeclareLaunchArgument(
        "filter_cutoff_freq",
        default_value="10.0",
        description="Low-pass filter cutoff frequency in Hz",
    )

    diagnostics_rate_arg = DeclareLaunchArgument(
        "diagnostics_rate",
        default_value="10.0",
        description="Diagnostics publish rate in Hz",
    )

    wujihand_driver_node = Node(
        package="wujihand_driver",
        executable="wujihand_driver_node",
        name="wujihand_driver",
        parameters=[
            {
                "serial_number": LaunchConfiguration("serial_number"),
                "publish_rate": LaunchConfiguration("publish_rate"),
                "filter_cutoff_freq": LaunchConfiguration("filter_cutoff_freq"),
                "diagnostics_rate": LaunchConfiguration("diagnostics_rate"),
            }
        ],
        output="screen",
    )

    return LaunchDescription(
        [
            serial_number_arg,
            publish_rate_arg,
            filter_cutoff_freq_arg,
            diagnostics_rate_arg,
            wujihand_driver_node,
        ]
    )
