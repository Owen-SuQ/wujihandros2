"""Common launch utilities for WujiHand."""

import os
import subprocess
import time

import rclpy
from ament_index_python.packages import get_package_share_directory
from launch import logging
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue
from rclpy.node import Node as RclpyNode

# Get launch logger
_logger = logging.get_logger(__name__)

# USB Vendor ID for WujiHand devices
WUJIHAND_USB_VID = "0483"
WUJIHAND_USB_MODEL = "WUJIHAND"


def detect_wujihand_devices():
    """Detect all connected WujiHand devices.

    Scans /dev/ttyACM* devices and returns serial numbers of WujiHand devices.

    Returns:
        List of serial numbers (strings) for connected WujiHand devices
    """
    devices = []
    import glob

    for dev_path in sorted(glob.glob("/dev/ttyACM*")):
        try:
            result = subprocess.run(
                ["udevadm", "info", "--query=all", f"--name={dev_path}"],
                capture_output=True,
                text=True,
                timeout=5.0,
            )
            if result.returncode != 0:
                continue

            # Parse udevadm output
            info = {}
            for line in result.stdout.splitlines():
                if line.startswith("E: "):
                    key_value = line[3:].split("=", 1)
                    if len(key_value) == 2:
                        info[key_value[0]] = key_value[1]

            # Check if this is a WujiHand device
            if (
                info.get("ID_VENDOR_ID") == WUJIHAND_USB_VID
                and info.get("ID_MODEL") == WUJIHAND_USB_MODEL
            ):
                serial = info.get("ID_SERIAL_SHORT", "")
                if serial:
                    devices.append(serial)
                    _logger.info(f"Found WujiHand device: {dev_path} (SN: {serial})")

        except (subprocess.TimeoutExpired, subprocess.SubprocessError, OSError) as e:
            _logger.debug(f"Error checking device {dev_path}: {e}")
            continue

    return devices


def parse_hands_config(hands_config):
    """Parse hands configuration string.

    Args:
        hands_config: Configuration string in one of these formats:
            - "auto" or "": Auto-detect all connected devices
            - "SN1": Single device by serial number (uses hand_0 as name)
            - "SN1,SN2": Multiple devices (uses hand_0, hand_1 as names)
            - "name1:SN1": Single device with custom name
            - "name1:SN1,name2:SN2": Multiple devices with custom names

    Returns:
        List of tuples: [(hand_name, serial_number), ...]
    """
    if not hands_config or hands_config.lower() == "auto":
        # Auto-detect devices
        serials = detect_wujihand_devices()
        if not serials:
            _logger.warning("No WujiHand devices detected")
            return []
        return [(f"hand_{i}", sn) for i, sn in enumerate(serials)]

    # Parse manual configuration
    hands = []
    for i, part in enumerate(hands_config.split(",")):
        part = part.strip()
        if not part:
            continue

        if ":" in part:
            name, serial = part.split(":", 1)
            hands.append((name.strip(), serial.strip()))
        else:
            # Only serial number provided, use default name
            hands.append((f"hand_{i}", part))

    return hands


def spawn_robot_state_publisher(context):
    """Spawn robot_state_publisher after detecting handedness from driver.

    This function polls the driver node for the handedness parameter,
    then creates a robot_state_publisher with the appropriate URDF.

    Args:
        context: Launch context

    Returns:
        List containing robot_state_publisher Node, or empty list on failure
    """
    hand_name = LaunchConfiguration("hand_name").perform(context)
    driver_node_name = f"/{hand_name}/wujihand_driver"
    wujihand_description_dir = get_package_share_directory("wujihand_description")

    _logger.info(f"Attempting to detect handedness from {driver_node_name}")

    # Use ROS 2 Python API to get parameter (more reliable than subprocess)
    hand_type = None
    try:
        if not rclpy.ok():
            rclpy.init()
        temp_node = RclpyNode("_handedness_detector_temp")

        # Poll for handedness parameter (retry up to 30 times with 0.5s interval)
        for attempt in range(30):
            try:
                # Get parameter client for the driver node
                from rcl_interfaces.srv import GetParameters

                client = temp_node.create_client(
                    GetParameters, f"{driver_node_name}/get_parameters"
                )
                if client.wait_for_service(timeout_sec=1.0):
                    request = GetParameters.Request()
                    request.names = ["handedness"]
                    future = client.call_async(request)
                    rclpy.spin_until_future_complete(temp_node, future, timeout_sec=2.0)
                    if future.result() is not None:
                        values = future.result().values
                        if values and values[0].string_value:
                            hand_type = values[0].string_value.lower()
                            _logger.info(f"Detected handedness: {hand_type}")
                            break
                temp_node.destroy_client(client)
            except Exception as e:
                _logger.debug(f"Attempt {attempt + 1}: {e}")
            time.sleep(0.5)

        temp_node.destroy_node()
    except Exception as e:
        _logger.error(f"Error detecting handedness: {e}")

    if hand_type is None or hand_type not in ["left", "right"]:
        _logger.error(
            f"Could not detect handedness from {driver_node_name} after 15 seconds. "
            "Please ensure the driver node is running and the device is connected."
        )
        return []

    _logger.info(f"Using handedness: {hand_type}")

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
            _logger.error(f"xacro failed: {result.stderr}")
            return []
        robot_description = result.stdout
    except (subprocess.TimeoutExpired, subprocess.SubprocessError, OSError) as e:
        _logger.error(f"Failed to process xacro: {e}")
        return []

    # Return robot_state_publisher node with URDF string as parameter
    # Note: robot_state_publisher subscribes to joint_states with SensorDataQoS by default
    return [
        Node(
            package="robot_state_publisher",
            executable="robot_state_publisher",
            name="robot_state_publisher",
            namespace=hand_name,
            parameters=[
                {
                    "robot_description": ParameterValue(
                        robot_description, value_type=str
                    )
                },
                {"publish_frequency": 100.0},
            ],
            remappings=[
                ("joint_states", "joint_states"),
            ],
            output="screen",
        )
    ]


def spawn_robot_state_publisher_for_hand(hand_name):
    """Create a closure to spawn robot_state_publisher for a specific hand.

    Args:
        hand_name: The hand namespace

    Returns:
        Function that spawns robot_state_publisher for the specified hand
    """

    def _spawn(context):
        driver_node_name = f"/{hand_name}/wujihand_driver"
        wujihand_description_dir = get_package_share_directory("wujihand_description")

        _logger.info(f"Attempting to detect handedness from {driver_node_name}")

        hand_type = None
        try:
            if not rclpy.ok():
                rclpy.init()
            temp_node = RclpyNode(f"_handedness_detector_{hand_name}")

            for attempt in range(30):
                try:
                    from rcl_interfaces.srv import GetParameters

                    client = temp_node.create_client(
                        GetParameters, f"{driver_node_name}/get_parameters"
                    )
                    if client.wait_for_service(timeout_sec=1.0):
                        request = GetParameters.Request()
                        request.names = ["handedness"]
                        future = client.call_async(request)
                        rclpy.spin_until_future_complete(
                            temp_node, future, timeout_sec=2.0
                        )
                        if future.result() is not None:
                            values = future.result().values
                            if values and values[0].string_value:
                                hand_type = values[0].string_value.lower()
                                _logger.info(
                                    f"[{hand_name}] Detected handedness: {hand_type}"
                                )
                                break
                    temp_node.destroy_client(client)
                except Exception as e:
                    _logger.debug(f"[{hand_name}] Attempt {attempt + 1}: {e}")
                time.sleep(0.5)

            temp_node.destroy_node()
        except Exception as e:
            _logger.error(f"[{hand_name}] Error detecting handedness: {e}")

        if hand_type is None or hand_type not in ["left", "right"]:
            _logger.error(
                f"[{hand_name}] Could not detect handedness from {driver_node_name}"
            )
            return []

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
                _logger.error(f"[{hand_name}] xacro failed: {result.stderr}")
                return []
            robot_description = result.stdout
        except (subprocess.TimeoutExpired, subprocess.SubprocessError, OSError) as e:
            _logger.error(f"[{hand_name}] Failed to process xacro: {e}")
            return []

        return [
            Node(
                package="robot_state_publisher",
                executable="robot_state_publisher",
                name="robot_state_publisher",
                namespace=hand_name,
                parameters=[
                    {
                        "robot_description": ParameterValue(
                            robot_description, value_type=str
                        )
                    },
                    {"publish_frequency": 100.0},
                ],
                remappings=[
                    ("joint_states", "joint_states"),
                ],
                output="screen",
            )
        ]

    return _spawn


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


def get_multi_hand_launch_arguments():
    """Return launch arguments for multi-hand support.

    Returns:
        List of DeclareLaunchArgument actions
    """
    return [
        DeclareLaunchArgument(
            "hands",
            default_value="auto",
            description=(
                "Hands configuration. Formats: "
                "'auto' (auto-detect), "
                "'SN1,SN2' (serial numbers), "
                "'name1:SN1,name2:SN2' (with custom names)"
            ),
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
