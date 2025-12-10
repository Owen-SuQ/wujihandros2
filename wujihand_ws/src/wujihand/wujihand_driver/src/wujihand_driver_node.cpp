#include "wujihand_driver/wujihand_driver_node.hpp"

#include <chrono>
#include <functional>

namespace wujihand_driver {

const std::array<std::string, WujiHandDriverNode::NUM_JOINTS> WujiHandDriverNode::JOINT_NAMES = {
    "finger1_joint1", "finger1_joint2", "finger1_joint3", "finger1_joint4",
    "finger2_joint1", "finger2_joint2", "finger2_joint3", "finger2_joint4",
    "finger3_joint1", "finger3_joint2", "finger3_joint3", "finger3_joint4",
    "finger4_joint1", "finger4_joint2", "finger4_joint3", "finger4_joint4",
    "finger5_joint1", "finger5_joint2", "finger5_joint3", "finger5_joint4"};

WujiHandDriverNode::WujiHandDriverNode() : Node("wujihand_driver"), hardware_connected_(false) {
  // Declare parameters
  this->declare_parameter("serial_number", "");
  this->declare_parameter("publish_rate", 1000.0);
  this->declare_parameter("filter_cutoff_freq", 10.0);

  // Get parameters
  serial_number_ = this->get_parameter("serial_number").as_string();
  publish_rate_ = this->get_parameter("publish_rate").as_double();
  filter_cutoff_freq_ = this->get_parameter("filter_cutoff_freq").as_double();

  // Initialize last positions
  last_positions_.fill(0.0);

  // Connect to hardware
  if (!connect_hardware()) {
    RCLCPP_ERROR(this->get_logger(), "Failed to connect to WujiHand hardware");
    throw std::runtime_error("Hardware connection failed");
  }

  // Create publishers
  state_pub_ = this->create_publisher<wujihand_msgs::msg::HandState>("hand_state", 10);
  joint_state_pub_ = this->create_publisher<sensor_msgs::msg::JointState>("joint_states", 10);

  // Create subscriber
  cmd_sub_ = this->create_subscription<wujihand_msgs::msg::HandCommand>(
      "hand_command", 10,
      std::bind(&WujiHandDriverNode::command_callback, this, std::placeholders::_1));

  // Create services
  get_info_srv_ = this->create_service<wujihand_msgs::srv::GetHandInfo>(
      "get_hand_info", std::bind(&WujiHandDriverNode::get_hand_info_callback, this,
                                 std::placeholders::_1, std::placeholders::_2));

  get_diagnostics_srv_ = this->create_service<wujihand_msgs::srv::GetDiagnostics>(
      "get_diagnostics", std::bind(&WujiHandDriverNode::get_diagnostics_callback, this,
                                   std::placeholders::_1, std::placeholders::_2));

  set_enabled_srv_ = this->create_service<wujihand_msgs::srv::SetEnabled>(
      "set_enabled", std::bind(&WujiHandDriverNode::set_enabled_callback, this,
                               std::placeholders::_1, std::placeholders::_2));

  reset_error_srv_ = this->create_service<wujihand_msgs::srv::ResetError>(
      "reset_error", std::bind(&WujiHandDriverNode::reset_error_callback, this,
                               std::placeholders::_1, std::placeholders::_2));

  // Initialize pre-allocated JointState message
  joint_state_msg_.name.reserve(NUM_JOINTS);
  joint_state_msg_.position.resize(NUM_JOINTS, 0.0);
  for (size_t i = 0; i < NUM_JOINTS; ++i) {
    joint_state_msg_.name.push_back(JOINT_NAMES[i]);
  }

  // Create state publish timer
  auto period = std::chrono::duration<double>(1.0 / publish_rate_);
  state_timer_ =
      this->create_wall_timer(std::chrono::duration_cast<std::chrono::nanoseconds>(period),
                              std::bind(&WujiHandDriverNode::publish_state, this));

  RCLCPP_INFO(this->get_logger(), "WujiHand driver started (rate: %.1f Hz)", publish_rate_);
}

WujiHandDriverNode::~WujiHandDriverNode() {
  disconnect_hardware();
}

bool WujiHandDriverNode::connect_hardware() {
  try {
    const char* serial = serial_number_.empty() ? nullptr : serial_number_.c_str();
    hand_ = std::make_unique<wujihandcpp::device::Hand>(serial);

    // Create realtime controller with filter
    wujihandcpp::filter::LowPass filter(filter_cutoff_freq_);
    controller_ = hand_->realtime_controller<true>(filter);

    // Enable all joints
    hand_->write<wujihandcpp::data::joint::Enabled>(true);

    // Read initial positions
    const auto& positions = controller_->get_joint_actual_position();
    for (size_t f = 0; f < NUM_FINGERS; ++f) {
      for (size_t j = 0; j < JOINTS_PER_FINGER; ++j) {
        last_positions_[to_flat_index(f, j)] = positions[f][j].load();
      }
    }

    hardware_connected_ = true;
    RCLCPP_INFO(this->get_logger(), "Connected to WujiHand");
    return true;

  } catch (const std::exception& e) {
    RCLCPP_ERROR(this->get_logger(), "Failed to connect: %s", e.what());
    return false;
  }
}

void WujiHandDriverNode::disconnect_hardware() {
  if (hardware_connected_ && hand_) {
    try {
      // Disable all joints before disconnecting
      hand_->write<wujihandcpp::data::joint::Enabled>(false);
      RCLCPP_INFO(this->get_logger(), "Disconnected from WujiHand");
    } catch (const std::exception& e) {
      RCLCPP_WARN(this->get_logger(), "Error during disconnect: %s", e.what());
    }
  }
  controller_.reset();
  hand_.reset();
  hardware_connected_ = false;
}

void WujiHandDriverNode::command_callback(const wujihand_msgs::msg::HandCommand::SharedPtr msg) {
  if (!hardware_connected_ || !controller_) {
    RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 1000,
                         "Cannot send command: hardware not connected");
    return;
  }

  // Convert flat array to 2D array and cache target positions
  double positions[NUM_FINGERS][JOINTS_PER_FINGER];
  for (size_t f = 0; f < NUM_FINGERS; ++f) {
    for (size_t j = 0; j < JOINTS_PER_FINGER; ++j) {
      size_t idx = to_flat_index(f, j);
      positions[f][j] = msg->target_positions[idx];
      last_positions_[idx] = msg->target_positions[idx];  // Update cached target
    }
  }

  // Send to hardware
  controller_->set_joint_target_position(positions);
}

void WujiHandDriverNode::publish_state() {
  if (!hardware_connected_ || !controller_) {
    return;
  }

  auto now = this->now();

  // Get actual positions from controller (fast, from cached realtime data)
  const auto& positions = controller_->get_joint_actual_position();

  // Build HandState message
  hand_state_msg_.header.stamp = now;

  // Read joint positions (always, this is fast)
  for (size_t f = 0; f < NUM_FINGERS; ++f) {
    for (size_t j = 0; j < JOINTS_PER_FINGER; ++j) {
      size_t idx = to_flat_index(f, j);
      hand_state_msg_.actual_positions[idx] = positions[f][j].load();
      hand_state_msg_.target_positions[idx] = last_positions_[idx];
    }
  }

  state_pub_->publish(hand_state_msg_);

  // Publish JointState message for RViz compatibility (using cached message)
  joint_state_msg_.header.stamp = now;
  for (size_t i = 0; i < NUM_JOINTS; ++i) {
    joint_state_msg_.position[i] = hand_state_msg_.actual_positions[i];
  }

  joint_state_pub_->publish(joint_state_msg_);
}

void WujiHandDriverNode::get_hand_info_callback(
    const std::shared_ptr<wujihand_msgs::srv::GetHandInfo::Request> /*request*/,
    std::shared_ptr<wujihand_msgs::srv::GetHandInfo::Response> response) {
  if (!hardware_connected_ || !hand_) {
    response->handedness = "unknown";
    response->firmware_version = "unknown";
    return;
  }

  try {
    // Read handedness
    auto handedness = hand_->read<wujihandcpp::data::hand::Handedness>();
    response->handedness = (handedness == 0) ? "left" : "right";

    // Read firmware version
    auto version = hand_->read<wujihandcpp::data::hand::FirmwareVersion>();
    response->firmware_version = std::to_string((version >> 16) & 0xFF) + "." +
                                 std::to_string((version >> 8) & 0xFF) + "." +
                                 std::to_string(version & 0xFF);

    // Set joint limits (placeholder values)
    for (size_t i = 0; i < NUM_JOINTS; ++i) {
      response->upper_limits[i] = 1.57;  // ~90 degrees
      response->lower_limits[i] = 0.0;
    }
    // Abduction joints have different limits
    for (size_t f = 0; f < NUM_FINGERS; ++f) {
      size_t abd_idx = f * JOINTS_PER_FINGER;
      response->upper_limits[abd_idx] = 0.5;
      response->lower_limits[abd_idx] = -0.5;
    }

  } catch (const std::exception& e) {
    RCLCPP_ERROR(this->get_logger(), "Error getting hand info: %s", e.what());
    response->handedness = "error";
    response->firmware_version = "error";
  }
}

void WujiHandDriverNode::get_diagnostics_callback(
    const std::shared_ptr<wujihand_msgs::srv::GetDiagnostics::Request> /*request*/,
    std::shared_ptr<wujihand_msgs::srv::GetDiagnostics::Response> response) {
  if (!hardware_connected_ || !hand_) {
    response->system_temperature = 0.0;
    response->input_voltage = 0.0;
    return;
  }

  try {
    response->system_temperature = hand_->read<wujihandcpp::data::hand::Temperature>();
    response->input_voltage = hand_->read<wujihandcpp::data::hand::InputVoltage>();

    for (size_t f = 0; f < NUM_FINGERS; ++f) {
      for (size_t j = 0; j < JOINTS_PER_FINGER; ++j) {
        size_t idx = to_flat_index(f, j);
        auto joint = hand_->finger(f).joint(j);
        response->joint_temperatures[idx] = joint.read<wujihandcpp::data::joint::Temperature>();
        response->error_codes[idx] = joint.read<wujihandcpp::data::joint::ErrorCode>();
      }
    }
  } catch (const std::exception& e) {
    RCLCPP_ERROR(this->get_logger(), "Error getting diagnostics: %s", e.what());
  }
}

void WujiHandDriverNode::set_enabled_callback(
    const std::shared_ptr<wujihand_msgs::srv::SetEnabled::Request> request,
    std::shared_ptr<wujihand_msgs::srv::SetEnabled::Response> response) {
  if (!hardware_connected_ || !hand_) {
    response->success = false;
    response->message = "Hardware not connected";
    return;
  }

  try {
    if (request->finger_id == 255 && request->joint_id == 255) {
      hand_->write<wujihandcpp::data::joint::Enabled>(request->enabled);
      response->success = true;
      response->message = request->enabled ? "All joints enabled" : "All joints disabled";
    } else if (request->finger_id < NUM_FINGERS) {
      if (request->joint_id == 255) {
        for (size_t j = 0; j < JOINTS_PER_FINGER; ++j) {
          hand_->finger(request->finger_id).joint(j).write<wujihandcpp::data::joint::Enabled>(request->enabled);
        }
        response->success = true;
        response->message = "Finger joints updated";
      } else if (request->joint_id < JOINTS_PER_FINGER) {
        hand_->finger(request->finger_id).joint(request->joint_id).write<wujihandcpp::data::joint::Enabled>(request->enabled);
        response->success = true;
        response->message = "Joint updated";
      } else {
        response->success = false;
        response->message = "Invalid joint_id";
      }
    } else {
      response->success = false;
      response->message = "Invalid finger_id";
    }
  } catch (const std::exception& e) {
    response->success = false;
    response->message = std::string("Error: ") + e.what();
  }
}

void WujiHandDriverNode::reset_error_callback(
    const std::shared_ptr<wujihand_msgs::srv::ResetError::Request> request,
    std::shared_ptr<wujihand_msgs::srv::ResetError::Response> response) {
  if (!hardware_connected_ || !hand_) {
    response->success = false;
    response->message = "Hardware not connected";
    return;
  }

  try {
    if (request->finger_id == 255 && request->joint_id == 255) {
      hand_->write<wujihandcpp::data::joint::ResetError>(1);
      response->success = true;
      response->message = "All errors reset";
    } else if (request->finger_id < NUM_FINGERS) {
      if (request->joint_id == 255) {
        for (size_t j = 0; j < JOINTS_PER_FINGER; ++j) {
          hand_->finger(request->finger_id).joint(j).write<wujihandcpp::data::joint::ResetError>(1);
        }
        response->success = true;
        response->message = "Finger errors reset";
      } else if (request->joint_id < JOINTS_PER_FINGER) {
        hand_->finger(request->finger_id).joint(request->joint_id).write<wujihandcpp::data::joint::ResetError>(1);
        response->success = true;
        response->message = "Joint error reset";
      } else {
        response->success = false;
        response->message = "Invalid joint_id";
      }
    } else {
      response->success = false;
      response->message = "Invalid finger_id";
    }
  } catch (const std::exception& e) {
    response->success = false;
    response->message = std::string("Error: ") + e.what();
  }
}

size_t WujiHandDriverNode::to_flat_index(size_t finger_id, size_t joint_id) {
  return finger_id * JOINTS_PER_FINGER + joint_id;
}

}  // namespace wujihand_driver
