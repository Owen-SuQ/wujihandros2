#!/usr/bin/env python3
"""
WujiHand Wave Motion Demo

Demonstrates wave motion control with fingers moving in a sinusoidal pattern.
Uses a dedicated thread for consistent 100Hz publishing rate.
Supports auto-detection and control of multiple hands.

Usage:
  # Auto-detect all connected hands
  ros2 run wujihand_bringup wave_demo.py

  # Specify by serial number (single)
  ros2 run wujihand_bringup wave_demo.py --ros-args -p hands:=355737633533

  # Specify by serial number (multiple)
  ros2 run wujihand_bringup wave_demo.py --ros-args -p hands:=355737633533,3557376F3533

  # Specify with custom names
  ros2 run wujihand_bringup wave_demo.py --ros-args -p hands:=left:355737633533,right:3557376F3533
"""

import glob
import math
import subprocess
import threading
import time

import rclpy
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data
from sensor_msgs.msg import JointState

# Constants
NUM_JOINTS = 20
PUBLISH_RATE = 100.0  # Hz
WAVE_FREQUENCY = 0.5  # Hz (one cycle per 2 seconds)
WAVE_AMPLITUDE = 0.8  # radians

# USB identifiers for WujiHand devices
WUJIHAND_USB_VID = "0483"
WUJIHAND_USB_MODEL = "WUJIHAND"


def detect_wujihand_devices():
    """Detect all connected WujiHand devices.

    Scans /dev/ttyACM* devices and returns serial numbers of WujiHand devices.

    Returns:
        List of serial numbers (strings) for connected WujiHand devices
    """
    devices = []

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

        except (subprocess.TimeoutExpired, subprocess.SubprocessError, OSError):
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


class WaveDemo(Node):
    def __init__(self):
        super().__init__("wave_demo")

        # Parameters
        self.declare_parameter("hands", "auto")
        hands_param = self.get_parameter("hands").get_parameter_value().string_value

        # Parse hands configuration (same format as launch files)
        hands = parse_hands_config(hands_param)

        if not hands:
            self.get_logger().error("No WujiHand devices detected or configured!")
            raise RuntimeError("No WujiHand devices detected or configured")

        self.hands = hands
        self.hand_names = [name for name, _ in hands]
        serials = [sn for _, sn in hands]

        if hands_param.lower() == "auto":
            self.get_logger().info(f"Auto-detected {len(hands)} device(s): {serials}")
        else:
            self.get_logger().info(f"Configured {len(hands)} device(s): {serials}")
        self.get_logger().info(f"Controlling hands: {self.hand_names}")

        # Create publishers for all hands
        self.publishers = {}
        for hand_name in self.hand_names:
            topic_name = f"/{hand_name}/joint_commands"
            self.publishers[hand_name] = self.create_publisher(
                JointState, topic_name, qos_profile_sensor_data
            )
            self.get_logger().info(f"Created publisher for {topic_name}")

        # Pre-allocate message (no names = faster processing in driver)
        self.msg = JointState()
        self.msg.position = [0.0] * NUM_JOINTS

        # Thread control
        self.running = True
        self.pub_thread = threading.Thread(target=self._publish_loop, daemon=True)
        self.pub_thread.start()

        self.get_logger().info(
            f"Wave demo started ({PUBLISH_RATE:.0f}Hz) for {len(self.hand_names)} hand(s)"
        )

    def _publish_loop(self):
        """Dedicated thread for consistent rate publishing."""
        start_time = time.perf_counter()
        period = 1.0 / PUBLISH_RATE
        next_time = start_time + period
        last_pub_time = start_time
        max_gap = 0.0
        anomaly_count = 0

        while self.running:
            now = time.perf_counter()
            gap = now - last_pub_time
            if gap > max_gap:
                max_gap = gap
            # Count anomalies (gap > 20ms)
            if gap > period * 2:
                anomaly_count += 1
                self.get_logger().warn(
                    f"Gap {gap*1000:.1f}ms detected (count: {anomaly_count})"
                )
            last_pub_time = now

            elapsed = now - start_time
            phase = 2.0 * math.pi * WAVE_FREQUENCY * elapsed
            y = (1.0 - math.cos(phase)) * WAVE_AMPLITUDE

            # F2-F5 wave motion (skip F1 thumb)
            for finger in range(1, 5):
                base = finger * 4
                self.msg.position[base + 0] = y  # MCP
                self.msg.position[base + 2] = y  # PIP
                self.msg.position[base + 3] = y  # DIP

            # Publish to all hands
            for publisher in self.publishers.values():
                publisher.publish(self.msg)

            # Precise timing
            sleep_time = next_time - time.perf_counter()
            if sleep_time > 0:
                time.sleep(sleep_time)
            next_time += period

    def destroy_node(self):
        self.running = False
        self.pub_thread.join(timeout=1.0)
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    try:
        node = WaveDemo()
        rclpy.spin(node)
    except RuntimeError as e:
        print(f"Error: {e}")
        return 1
    except KeyboardInterrupt:
        pass
    finally:
        if "node" in locals():
            node.destroy_node()
        rclpy.shutdown()
    return 0


if __name__ == "__main__":
    exit(main())
