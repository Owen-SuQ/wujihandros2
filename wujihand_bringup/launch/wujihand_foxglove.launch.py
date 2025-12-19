"""Launch WujiHand driver with Foxglove Bridge for visualization."""

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
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import (
    EqualsSubstitution,
    LaunchConfiguration,
    NotEqualsSubstitution,
)
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue

# Add launch directory to path for local imports
sys.path.insert(0, os.path.dirname(__file__))
from common import get_common_launch_arguments, get_robot_description_command


def spawn_robot_state_publisher_auto(context):
    """Spawn robot_state_publisher after detecting handedness from driver."""
    hand_name = LaunchConfiguration("hand_name").perform(context)
    hand_type_value = LaunchConfiguration("hand_type").perform(context)

    # Only run auto-detection if hand_type is "auto"
    if hand_type_value != "auto":
        return []

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

    hand_name = LaunchConfiguration("hand_name")
    hand_type = LaunchConfiguration("hand_type")

    # Condition: hand_type is NOT "auto" (user specified left/right explicitly)
    hand_type_specified = NotEqualsSubstitution(hand_type, "auto")

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

    # Foxglove Bridge node with asset URI allowlist for mesh loading
    foxglove_bridge_node = Node(
        package="foxglove_bridge",
        executable="foxglove_bridge",
        name="foxglove_bridge",
        parameters=[
            {
                "port": 8765,
                "address": "0.0.0.0",
                "send_buffer_limit": 50000000,
                "asset_uri_allowlist": [
                    "^package://.*\\.(?:dae|fbx|glb|gltf|jpeg|jpg|mtl|obj|png|stl|tif|tiff|urdf|webp|xacro|STL)$"
                ],
            }
        ],
        output="screen",
        emulate_tty=True,
    )

    # Auto-detect: use OpaqueFunction to spawn robot_state_publisher after driver starts
    auto_detect_action = TimerAction(
        period=1.0,  # Wait 1 second for driver to start
        actions=[OpaqueFunction(function=spawn_robot_state_publisher_auto)],
        condition=IfCondition(EqualsSubstitution(hand_type, "auto")),
    )

    # Robot state publisher for explicit hand_type (non-auto mode)
    robot_state_publisher_node = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        name="robot_state_publisher",
        namespace=hand_name,
        parameters=[
            {"robot_description": get_robot_description_command(hand_name, hand_type)}
        ],
        output="screen",
        emulate_tty=True,
        condition=IfCondition(hand_type_specified),
    )

    return LaunchDescription(
        get_common_launch_arguments()
        + [
            # Always launch driver first
            wujihand_launch,
            # Launch robot_state_publisher only if hand_type is explicitly specified
            robot_state_publisher_node,
            # Auto-detect handedness and spawn robot_state_publisher
            auto_detect_action,
            # Foxglove Bridge
            foxglove_bridge_node,
        ]
    )
