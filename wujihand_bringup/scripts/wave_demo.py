#!/usr/bin/env python3
"""
WujiHand Wave Motion Demo

Demonstrates wave motion control:
- Wave motion: fingers move in sinusoidal pattern at 100Hz

Usage:
  1. Start the driver: ros2 launch wujihand_bringup wujihand.launch.py
  2. Run this demo: ros2 run wujihand_bringup wave_demo.py
"""

import math

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState

JOINT_NAMES = [
    "finger1_joint1",
    "finger1_joint2",
    "finger1_joint3",
    "finger1_joint4",
    "finger2_joint1",
    "finger2_joint2",
    "finger2_joint3",
    "finger2_joint4",
    "finger3_joint1",
    "finger3_joint2",
    "finger3_joint3",
    "finger3_joint4",
    "finger4_joint1",
    "finger4_joint2",
    "finger4_joint3",
    "finger4_joint4",
    "finger5_joint1",
    "finger5_joint2",
    "finger5_joint3",
    "finger5_joint4",
]


class WaveDemo(Node):
    def __init__(self):
        super().__init__("wave_demo")
        self.x = 0.0

        # Pre-allocate message (no names = faster O(n) processing in driver)
        self.msg = JointState()
        self.msg.position = [0.0] * 20

        # Publisher for joint commands
        self.cmd_pub = self.create_publisher(JointState, "/joint_commands", 10)

        # Wave motion timer (100Hz)
        self.wave_timer = self.create_timer(0.01, self.wave_callback)

        self.get_logger().info("WujiHand Wave Demo Started (100Hz)")
        self.get_logger().info("Press Ctrl+C to stop")

    def wave_callback(self):
        # Sinusoidal wave: y = (1 - cos(x)) * 0.8
        y = (1.0 - math.cos(self.x)) * 0.8

        # Thumb (F1): keep still (indices 0-3 stay 0)

        # Index, Middle, Ring, Little (F2-F5): wave motion
        for finger in range(1, 5):
            base = finger * 4
            self.msg.position[base + 0] = y  # joint1
            self.msg.position[base + 2] = y  # joint3
            self.msg.position[base + 3] = y  # joint4

        self.cmd_pub.publish(self.msg)

        # Increment phase (full cycle per ~2 seconds)
        self.x += math.pi / 100.0


def main(args=None):
    rclpy.init(args=args)
    node = WaveDemo()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
