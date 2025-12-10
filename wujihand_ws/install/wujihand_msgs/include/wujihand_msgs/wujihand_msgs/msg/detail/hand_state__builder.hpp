// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from wujihand_msgs:msg/HandState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "wujihand_msgs/msg/hand_state.hpp"


#ifndef WUJIHAND_MSGS__MSG__DETAIL__HAND_STATE__BUILDER_HPP_
#define WUJIHAND_MSGS__MSG__DETAIL__HAND_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "wujihand_msgs/msg/detail/hand_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace wujihand_msgs
{

namespace msg
{

namespace builder
{

class Init_HandState_enabled
{
public:
  explicit Init_HandState_enabled(::wujihand_msgs::msg::HandState & msg)
  : msg_(msg)
  {}
  ::wujihand_msgs::msg::HandState enabled(::wujihand_msgs::msg::HandState::_enabled_type arg)
  {
    msg_.enabled = std::move(arg);
    return std::move(msg_);
  }

private:
  ::wujihand_msgs::msg::HandState msg_;
};

class Init_HandState_error_codes
{
public:
  explicit Init_HandState_error_codes(::wujihand_msgs::msg::HandState & msg)
  : msg_(msg)
  {}
  Init_HandState_enabled error_codes(::wujihand_msgs::msg::HandState::_error_codes_type arg)
  {
    msg_.error_codes = std::move(arg);
    return Init_HandState_enabled(msg_);
  }

private:
  ::wujihand_msgs::msg::HandState msg_;
};

class Init_HandState_joint_temperatures
{
public:
  explicit Init_HandState_joint_temperatures(::wujihand_msgs::msg::HandState & msg)
  : msg_(msg)
  {}
  Init_HandState_error_codes joint_temperatures(::wujihand_msgs::msg::HandState::_joint_temperatures_type arg)
  {
    msg_.joint_temperatures = std::move(arg);
    return Init_HandState_error_codes(msg_);
  }

private:
  ::wujihand_msgs::msg::HandState msg_;
};

class Init_HandState_target_positions
{
public:
  explicit Init_HandState_target_positions(::wujihand_msgs::msg::HandState & msg)
  : msg_(msg)
  {}
  Init_HandState_joint_temperatures target_positions(::wujihand_msgs::msg::HandState::_target_positions_type arg)
  {
    msg_.target_positions = std::move(arg);
    return Init_HandState_joint_temperatures(msg_);
  }

private:
  ::wujihand_msgs::msg::HandState msg_;
};

class Init_HandState_actual_positions
{
public:
  explicit Init_HandState_actual_positions(::wujihand_msgs::msg::HandState & msg)
  : msg_(msg)
  {}
  Init_HandState_target_positions actual_positions(::wujihand_msgs::msg::HandState::_actual_positions_type arg)
  {
    msg_.actual_positions = std::move(arg);
    return Init_HandState_target_positions(msg_);
  }

private:
  ::wujihand_msgs::msg::HandState msg_;
};

class Init_HandState_input_voltage
{
public:
  explicit Init_HandState_input_voltage(::wujihand_msgs::msg::HandState & msg)
  : msg_(msg)
  {}
  Init_HandState_actual_positions input_voltage(::wujihand_msgs::msg::HandState::_input_voltage_type arg)
  {
    msg_.input_voltage = std::move(arg);
    return Init_HandState_actual_positions(msg_);
  }

private:
  ::wujihand_msgs::msg::HandState msg_;
};

class Init_HandState_system_temperature
{
public:
  explicit Init_HandState_system_temperature(::wujihand_msgs::msg::HandState & msg)
  : msg_(msg)
  {}
  Init_HandState_input_voltage system_temperature(::wujihand_msgs::msg::HandState::_system_temperature_type arg)
  {
    msg_.system_temperature = std::move(arg);
    return Init_HandState_input_voltage(msg_);
  }

private:
  ::wujihand_msgs::msg::HandState msg_;
};

class Init_HandState_handedness
{
public:
  explicit Init_HandState_handedness(::wujihand_msgs::msg::HandState & msg)
  : msg_(msg)
  {}
  Init_HandState_system_temperature handedness(::wujihand_msgs::msg::HandState::_handedness_type arg)
  {
    msg_.handedness = std::move(arg);
    return Init_HandState_system_temperature(msg_);
  }

private:
  ::wujihand_msgs::msg::HandState msg_;
};

class Init_HandState_header
{
public:
  Init_HandState_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HandState_handedness header(::wujihand_msgs::msg::HandState::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_HandState_handedness(msg_);
  }

private:
  ::wujihand_msgs::msg::HandState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::wujihand_msgs::msg::HandState>()
{
  return wujihand_msgs::msg::builder::Init_HandState_header();
}

}  // namespace wujihand_msgs

#endif  // WUJIHAND_MSGS__MSG__DETAIL__HAND_STATE__BUILDER_HPP_
