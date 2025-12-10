/**
 * WujiHand ROS2 Example
 *
 * Demonstrates concurrent control and monitoring:
 * - Wave motion: fingers move in sinusoidal pattern
 * - State reading: prints joint positions every second
 *
 * Usage:
 *   1. Start the driver: ros2 run wujihand_driver wujihand_driver_node
 *   2. Run this example: ros2 run wujihand_example wujihand_example
 */

#include <rclcpp/rclcpp.hpp>
#include <wujihand_msgs/msg/hand_command.hpp>
#include <wujihand_msgs/msg/hand_state.hpp>
#include <cmath>
#include <chrono>
#include <iomanip>

using namespace std::chrono_literals;

class WujiHandExample : public rclcpp::Node
{
public:
  WujiHandExample() : Node("wujihand_example"), x_(0.0)
  {
    // Publisher for hand commands
    cmd_pub_ = create_publisher<wujihand_msgs::msg::HandCommand>(
      "/hand_command", 10);

    // Subscriber for hand state
    state_sub_ = create_subscription<wujihand_msgs::msg::HandState>(
      "/hand_state", 10,
      std::bind(&WujiHandExample::state_callback, this, std::placeholders::_1));

    // Wave motion timer (100Hz)
    wave_timer_ = create_wall_timer(10ms, std::bind(&WujiHandExample::wave_callback, this));

    // State print timer (1Hz)
    print_timer_ = create_wall_timer(1s, std::bind(&WujiHandExample::print_callback, this));

    RCLCPP_INFO(get_logger(), "WujiHand Example Started");
    RCLCPP_INFO(get_logger(), "Wave motion running at 100Hz, state print at 1Hz");
    RCLCPP_INFO(get_logger(), "Press Ctrl+C to stop");
  }

private:
  void wave_callback()
  {
    // Sinusoidal wave: y = (1 - cos(x)) * 0.8
    double y = (1.0 - std::cos(x_)) * 0.8;

    // 20 joints: 5 fingers x 4 joints each
    wujihand_msgs::msg::HandCommand msg;
    msg.header.stamp = this->now();
    
    // Joint order: [joint1, joint2, joint3, joint4] for each finger
    // Pattern from Python example: [y, 0, y, y]
    
    // Thumb (F1): keep still
    msg.target_positions[0] = 0.0;
    msg.target_positions[1] = 0.0;
    msg.target_positions[2] = 0.0;
    msg.target_positions[3] = 0.0;
    
    // Index, Middle, Ring, Little (F2-F5): wave motion
    // Pattern: [y, 0, y, y] - joint1, joint3, joint4 move; joint2 stays still
    for (int finger = 1; finger < 5; ++finger) {
      int base = finger * 4;
      msg.target_positions[base + 0] = y;    // joint1 (wave)
      msg.target_positions[base + 1] = 0.0;  // joint2 (keep still)
      msg.target_positions[base + 2] = y;    // joint3 (wave)
      msg.target_positions[base + 3] = y;    // joint4 (wave)
    }

    cmd_pub_->publish(msg);

    // Increment phase (100Hz, full cycle per ~2 seconds)
    x_ += M_PI / 100.0;
  }

  void state_callback(const wujihand_msgs::msg::HandState::SharedPtr msg)
  {
    latest_state_ = *msg;
    state_received_ = true;
  }

  void print_callback()
  {
    if (!state_received_) {
      RCLCPP_WARN(get_logger(), "No hand state received yet. Is the driver running?");
      return;
    }

    static const char* joint_names[] = {
      "finger1_joint1", "finger1_joint2", "finger1_joint3", "finger1_joint4",
      "finger2_joint1", "finger2_joint2", "finger2_joint3", "finger2_joint4",
      "finger3_joint1", "finger3_joint2", "finger3_joint3", "finger3_joint4",
      "finger4_joint1", "finger4_joint2", "finger4_joint3", "finger4_joint4",
      "finger5_joint1", "finger5_joint2", "finger5_joint3", "finger5_joint4"
    };

    std::cout << "\n=== Joint Positions ===" << std::endl;
    std::cout << std::left << std::setw(20) << "Joint" << "Position (rad)" << std::endl;
    std::cout << std::string(36, '-') << std::endl;

    for (size_t i = 0; i < 20; ++i) {
      std::cout << std::left << std::setw(20) << joint_names[i]
                << std::fixed << std::setprecision(4) 
                << latest_state_.actual_positions[i] << std::endl;
    }
  }

  rclcpp::Publisher<wujihand_msgs::msg::HandCommand>::SharedPtr cmd_pub_;
  rclcpp::Subscription<wujihand_msgs::msg::HandState>::SharedPtr state_sub_;
  rclcpp::TimerBase::SharedPtr wave_timer_;
  rclcpp::TimerBase::SharedPtr print_timer_;

  double x_;
  wujihand_msgs::msg::HandState latest_state_;
  bool state_received_ = false;
};

int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<WujiHandExample>());
  rclcpp::shutdown();
  return 0;
}
