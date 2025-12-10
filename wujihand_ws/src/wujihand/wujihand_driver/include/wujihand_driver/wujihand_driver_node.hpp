#ifndef WUJIHAND_DRIVER__WUJIHAND_DRIVER_NODE_HPP_
#define WUJIHAND_DRIVER__WUJIHAND_DRIVER_NODE_HPP_

#include <array>
#include <memory>
#include <string>
#include <wujihandcpp/data/hand.hpp>
#include <wujihandcpp/data/joint.hpp>
#include <wujihandcpp/device/controller.hpp>
#include <wujihandcpp/device/hand.hpp>
#include <wujihandcpp/filter/low_pass.hpp>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "wujihand_msgs/msg/hand_command.hpp"
#include "wujihand_msgs/msg/hand_state.hpp"
#include "wujihand_msgs/srv/get_hand_info.hpp"
#include "wujihand_msgs/srv/get_diagnostics.hpp"
#include "wujihand_msgs/srv/reset_error.hpp"
#include "wujihand_msgs/srv/set_enabled.hpp"

namespace wujihand_driver {

class WujiHandDriverNode : public rclcpp::Node {
 public:
  static constexpr size_t NUM_JOINTS = 20;
  static constexpr size_t NUM_FINGERS = 5;
  static constexpr size_t JOINTS_PER_FINGER = 4;

  WujiHandDriverNode();
  ~WujiHandDriverNode();

 private:
  // Joint names for JointState message
  static const std::array<std::string, NUM_JOINTS> JOINT_NAMES;

  // Hardware connection
  std::unique_ptr<wujihandcpp::device::Hand> hand_;
  std::unique_ptr<wujihandcpp::device::IController> controller_;

  // Publishers
  rclcpp::Publisher<wujihand_msgs::msg::HandState>::SharedPtr state_pub_;
  rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_state_pub_;

  // Subscribers
  rclcpp::Subscription<wujihand_msgs::msg::HandCommand>::SharedPtr cmd_sub_;

  // Services
  rclcpp::Service<wujihand_msgs::srv::GetHandInfo>::SharedPtr get_info_srv_;
  rclcpp::Service<wujihand_msgs::srv::GetDiagnostics>::SharedPtr get_diagnostics_srv_;
  rclcpp::Service<wujihand_msgs::srv::SetEnabled>::SharedPtr set_enabled_srv_;
  rclcpp::Service<wujihand_msgs::srv::ResetError>::SharedPtr reset_error_srv_;

  // Timers
  rclcpp::TimerBase::SharedPtr state_timer_;

  // Parameters
  std::string serial_number_;
  double publish_rate_;
  double filter_cutoff_freq_;

  // Cached state
  std::array<double, NUM_JOINTS> last_positions_;
  bool hardware_connected_;

  // Pre-allocated messages for efficiency
  wujihand_msgs::msg::HandState hand_state_msg_;
  sensor_msgs::msg::JointState joint_state_msg_;

  // Callbacks
  void command_callback(const wujihand_msgs::msg::HandCommand::SharedPtr msg);
  void publish_state();

  // Service callbacks
  void get_hand_info_callback(
      const std::shared_ptr<wujihand_msgs::srv::GetHandInfo::Request> request,
      std::shared_ptr<wujihand_msgs::srv::GetHandInfo::Response> response);
  void get_diagnostics_callback(
      const std::shared_ptr<wujihand_msgs::srv::GetDiagnostics::Request> request,
      std::shared_ptr<wujihand_msgs::srv::GetDiagnostics::Response> response);
  void set_enabled_callback(const std::shared_ptr<wujihand_msgs::srv::SetEnabled::Request> request,
                            std::shared_ptr<wujihand_msgs::srv::SetEnabled::Response> response);
  void reset_error_callback(const std::shared_ptr<wujihand_msgs::srv::ResetError::Request> request,
                            std::shared_ptr<wujihand_msgs::srv::ResetError::Response> response);

  // Helper functions
  bool connect_hardware();
  void disconnect_hardware();
  static size_t to_flat_index(size_t finger_id, size_t joint_id);
};

}  // namespace wujihand_driver

#endif  // WUJIHAND_DRIVER__WUJIHAND_DRIVER_NODE_HPP_
