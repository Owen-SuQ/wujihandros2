// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from wujihand_msgs:msg/HandState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "wujihand_msgs/msg/hand_state.hpp"


#ifndef WUJIHAND_MSGS__MSG__DETAIL__HAND_STATE__TRAITS_HPP_
#define WUJIHAND_MSGS__MSG__DETAIL__HAND_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "wujihand_msgs/msg/detail/hand_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace wujihand_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const HandState & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: handedness
  {
    out << "handedness: ";
    rosidl_generator_traits::value_to_yaml(msg.handedness, out);
    out << ", ";
  }

  // member: system_temperature
  {
    out << "system_temperature: ";
    rosidl_generator_traits::value_to_yaml(msg.system_temperature, out);
    out << ", ";
  }

  // member: input_voltage
  {
    out << "input_voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.input_voltage, out);
    out << ", ";
  }

  // member: actual_positions
  {
    if (msg.actual_positions.size() == 0) {
      out << "actual_positions: []";
    } else {
      out << "actual_positions: [";
      size_t pending_items = msg.actual_positions.size();
      for (auto item : msg.actual_positions) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
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
    out << ", ";
  }

  // member: joint_temperatures
  {
    if (msg.joint_temperatures.size() == 0) {
      out << "joint_temperatures: []";
    } else {
      out << "joint_temperatures: [";
      size_t pending_items = msg.joint_temperatures.size();
      for (auto item : msg.joint_temperatures) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: error_codes
  {
    if (msg.error_codes.size() == 0) {
      out << "error_codes: []";
    } else {
      out << "error_codes: [";
      size_t pending_items = msg.error_codes.size();
      for (auto item : msg.error_codes) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: enabled
  {
    if (msg.enabled.size() == 0) {
      out << "enabled: []";
    } else {
      out << "enabled: [";
      size_t pending_items = msg.enabled.size();
      for (auto item : msg.enabled) {
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
  const HandState & msg,
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

  // member: handedness
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "handedness: ";
    rosidl_generator_traits::value_to_yaml(msg.handedness, out);
    out << "\n";
  }

  // member: system_temperature
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "system_temperature: ";
    rosidl_generator_traits::value_to_yaml(msg.system_temperature, out);
    out << "\n";
  }

  // member: input_voltage
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "input_voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.input_voltage, out);
    out << "\n";
  }

  // member: actual_positions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.actual_positions.size() == 0) {
      out << "actual_positions: []\n";
    } else {
      out << "actual_positions:\n";
      for (auto item : msg.actual_positions) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
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

  // member: joint_temperatures
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.joint_temperatures.size() == 0) {
      out << "joint_temperatures: []\n";
    } else {
      out << "joint_temperatures:\n";
      for (auto item : msg.joint_temperatures) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: error_codes
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.error_codes.size() == 0) {
      out << "error_codes: []\n";
    } else {
      out << "error_codes:\n";
      for (auto item : msg.error_codes) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: enabled
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.enabled.size() == 0) {
      out << "enabled: []\n";
    } else {
      out << "enabled:\n";
      for (auto item : msg.enabled) {
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

inline std::string to_yaml(const HandState & msg, bool use_flow_style = false)
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
  const wujihand_msgs::msg::HandState & msg,
  std::ostream & out, size_t indentation = 0)
{
  wujihand_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use wujihand_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const wujihand_msgs::msg::HandState & msg)
{
  return wujihand_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<wujihand_msgs::msg::HandState>()
{
  return "wujihand_msgs::msg::HandState";
}

template<>
inline const char * name<wujihand_msgs::msg::HandState>()
{
  return "wujihand_msgs/msg/HandState";
}

template<>
struct has_fixed_size<wujihand_msgs::msg::HandState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<wujihand_msgs::msg::HandState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<wujihand_msgs::msg::HandState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // WUJIHAND_MSGS__MSG__DETAIL__HAND_STATE__TRAITS_HPP_
