"""Launch WujiHand driver with RViz for visualization."""

import os
import subprocess
import sys
import time

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import (
    IncludeLaunchDescription,
    OpaqueFunction,
    TimerAction,
)
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue

# Add launch directory to path for local imports
sys.path.insert(0, os.path.dirname(__file__))
from common import get_common_launch_arguments


def spawn_robot_state_publisher(context):
    """Spawn robot_state_publisher after detecting handedness from driver."""
    hand_name = LaunchConfiguration("hand_name").perform(context)
    driver_node_name = f"/{hand_name}/wujihand_driver"
    wujihand_description_dir = get_package_share_directory("wujihand_description")

    # Poll for handedness parameter (retry up to 30 times with 0.5s interval)
    hand_type = None
    for _ in range(30):
        try:
            result = subprocess.run(
                ["ros2", "param", "get", driver_node_name, "handedness"],
                capture_output=True,
                text=True,
                timeout=2.0,
            )
            if result.returncode == 0:
                output = result.stdout.strip().lower()
                if "left" in output:
                    hand_type = "left"
                    break
                elif "right" in output:
                    hand_type = "right"
                    break
        except Exception:
            pass
        time.sleep(0.5)

    if hand_type is None:
        print("[WARN] Could not detect handedness, defaulting to 'right'")
        hand_type = "right"

    print(f"[INFO] Detected handedness: {hand_type}")

    # Use xacro to process the URDF with prefix
    xacro_file = os.path.join(
        wujihand_description_dir, "urdf", f"{hand_type}.urdf.xacro"
    )
    prefix = f"{hand_name}/"
    try:
        result = subprocess.run(
            ["xacro", xacro_file, f"prefix:={prefix}"],
            capture_output=True,
            text=True,
            timeout=10.0,
        )
        if result.returncode != 0:
            print(f"[ERROR] xacro failed: {result.stderr}")
            return []
        robot_description = result.stdout
    except Exception as e:
        print(f"[ERROR] Failed to process xacro: {e}")
        return []

    # Return robot_state_publisher node with URDF string as parameter
    return [
        Node(
            package="robot_state_publisher",
            executable="robot_state_publisher",
            name="robot_state_publisher",
            namespace=hand_name,
            parameters=[
                {"robot_description": ParameterValue(robot_description, value_type=str)}
            ],
            output="screen",
        )
    ]


def generate_launch_description():
    wujihand_bringup_dir = get_package_share_directory("wujihand_bringup")
    wujihand_description_dir = get_package_share_directory("wujihand_description")

    hand_name = LaunchConfiguration("hand_name")

    # WujiHand driver launch
    wujihand_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(wujihand_bringup_dir, "launch", "wujihand.launch.py")
        ),
        launch_arguments={
            "hand_name": hand_name,
            "serial_number": LaunchConfiguration("serial_number"),
            "publish_rate": LaunchConfiguration("publish_rate"),
            "filter_cutoff_freq": LaunchConfiguration("filter_cutoff_freq"),
            "diagnostics_rate": LaunchConfiguration("diagnostics_rate"),
        }.items(),
    )

    # RViz node with namespace for multi-hand support
    rviz_config = os.path.join(wujihand_description_dir, "rviz", "robot_display.rviz")
    rviz_node = Node(
        package="rviz2",
        executable="rviz2",
        name="rviz2",
        namespace=hand_name,
        arguments=["-d", rviz_config],
        output="screen",
        emulate_tty=True,
    )

    # Auto-detect handedness and spawn robot_state_publisher after driver starts
    auto_detect_action = TimerAction(
        period=1.0,  # Wait 1 second for driver to start
        actions=[OpaqueFunction(function=spawn_robot_state_publisher)],
    )

    return LaunchDescription(
        get_common_launch_arguments()
        + [
            # Always launch driver first
            wujihand_launch,
            # Auto-detect handedness and spawn robot_state_publisher
            auto_detect_action,
            # RViz
            rviz_node,
        ]
    )
