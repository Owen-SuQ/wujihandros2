// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from wujihand_msgs:msg/HandCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "wujihand_msgs/msg/hand_command.hpp"


#ifndef WUJIHAND_MSGS__MSG__DETAIL__HAND_COMMAND__BUILDER_HPP_
#define WUJIHAND_MSGS__MSG__DETAIL__HAND_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "wujihand_msgs/msg/detail/hand_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace wujihand_msgs
{

namespace msg
{

namespace builder
{

class Init_HandCommand_target_positions
{
public:
  explicit Init_HandCommand_target_positions(::wujihand_msgs::msg::HandCommand & msg)
  : msg_(msg)
  {}
  ::wujihand_msgs::msg::HandCommand target_positions(::wujihand_msgs::msg::HandCommand::_target_positions_type arg)
  {
    msg_.target_positions = std::move(arg);
    return std::move(msg_);
  }

private:
  ::wujihand_msgs::msg::HandCommand msg_;
};

class Init_HandCommand_header
{
public:
  Init_HandCommand_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HandCommand_target_positions header(::wujihand_msgs::msg::HandCommand::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_HandCommand_target_positions(msg_);
  }

private:
  ::wujihand_msgs::msg::HandCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::wujihand_msgs::msg::HandCommand>()
{
  return wujihand_msgs::msg::builder::Init_HandCommand_header();
}

}  // namespace wujihand_msgs

#endif  // WUJIHAND_MSGS__MSG__DETAIL__HAND_COMMAND__BUILDER_HPP_
