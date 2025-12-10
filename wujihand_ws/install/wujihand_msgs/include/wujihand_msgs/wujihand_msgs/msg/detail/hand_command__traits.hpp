// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from wujihand_msgs:msg/HandCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "wujihand_msgs/msg/hand_command.hpp"


#ifndef WUJIHAND_MSGS__MSG__DETAIL__HAND_COMMAND__TRAITS_HPP_
#define WUJIHAND_MSGS__MSG__DETAIL__HAND_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "wujihand_msgs/msg/detail/hand_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace wujihand_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const HandCommand & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: target_positions
  {
    if (msg.target_positions.size() == 0) {
      out << "target_positions: []";
    } else {
      out << "target_positions: [";
      size_t pending_items = msg.target_positions.size();
      for (auto item : msg.target_positions) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const HandCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: target_positions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.target_positions.size() == 0) {
      out << "target_positions: []\n";
    } else {
      out << "target_positions:\n";
      for (auto item : msg.target_positions) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const HandCommand & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace wujihand_msgs

namespace rosidl_generator_traits
{

[[deprecated("use wujihand_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const wujihand_msgs::msg::HandCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  wujihand_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use wujihand_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const wujihand_msgs::msg::HandCommand & msg)
{
  return wujihand_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<wujihand_msgs::msg::HandCommand>()
{
  return "wujihand_msgs::msg::HandCommand";
}

template<>
inline const char * name<wujihand_msgs::msg::HandCommand>()
{
  return "wujihand_msgs/msg/HandCommand";
}

template<>
struct has_fixed_size<wujihand_msgs::msg::HandCommand>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<wujihand_msgs::msg::HandCommand>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<wujihand_msgs::msg::HandCommand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // WUJIHAND_MSGS__MSG__DETAIL__HAND_COMMAND__TRAITS_HPP_
