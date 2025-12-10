// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from wujihand_msgs:srv/GetHandInfo.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "wujihand_msgs/srv/get_hand_info.hpp"


#ifndef WUJIHAND_MSGS__SRV__DETAIL__GET_HAND_INFO__TRAITS_HPP_
#define WUJIHAND_MSGS__SRV__DETAIL__GET_HAND_INFO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "wujihand_msgs/srv/detail/get_hand_info__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace wujihand_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetHandInfo_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetHandInfo_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetHandInfo_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace wujihand_msgs

namespace rosidl_generator_traits
{

[[deprecated("use wujihand_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const wujihand_msgs::srv::GetHandInfo_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  wujihand_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use wujihand_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const wujihand_msgs::srv::GetHandInfo_Request & msg)
{
  return wujihand_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<wujihand_msgs::srv::GetHandInfo_Request>()
{
  return "wujihand_msgs::srv::GetHandInfo_Request";
}

template<>
inline const char * name<wujihand_msgs::srv::GetHandInfo_Request>()
{
  return "wujihand_msgs/srv/GetHandInfo_Request";
}

template<>
struct has_fixed_size<wujihand_msgs::srv::GetHandInfo_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<wujihand_msgs::srv::GetHandInfo_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<wujihand_msgs::srv::GetHandInfo_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace wujihand_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetHandInfo_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: handedness
  {
    out << "handedness: ";
    rosidl_generator_traits::value_to_yaml(msg.handedness, out);
    out << ", ";
  }

  // member: firmware_version
  {
    out << "firmware_version: ";
    rosidl_generator_traits::value_to_yaml(msg.firmware_version, out);
    out << ", ";
  }

  // member: upper_limits
  {
    if (msg.upper_limits.size() == 0) {
      out << "upper_limits: []";
    } else {
      out << "upper_limits: [";
      size_t pending_items = msg.upper_limits.size();
      for (auto item : msg.upper_limits) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: lower_limits
  {
    if (msg.lower_limits.size() == 0) {
      out << "lower_limits: []";
    } else {
      out << "lower_limits: [";
      size_t pending_items = msg.lower_limits.size();
      for (auto item : msg.lower_limits) {
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
  const GetHandInfo_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: handedness
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "handedness: ";
    rosidl_generator_traits::value_to_yaml(msg.handedness, out);
    out << "\n";
  }

  // member: firmware_version
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "firmware_version: ";
    rosidl_generator_traits::value_to_yaml(msg.firmware_version, out);
    out << "\n";
  }

  // member: upper_limits
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.upper_limits.size() == 0) {
      out << "upper_limits: []\n";
    } else {
      out << "upper_limits:\n";
      for (auto item : msg.upper_limits) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: lower_limits
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.lower_limits.size() == 0) {
      out << "lower_limits: []\n";
    } else {
      out << "lower_limits:\n";
      for (auto item : msg.lower_limits) {
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

inline std::string to_yaml(const GetHandInfo_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace wujihand_msgs

namespace rosidl_generator_traits
{

[[deprecated("use wujihand_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const wujihand_msgs::srv::GetHandInfo_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  wujihand_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use wujihand_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const wujihand_msgs::srv::GetHandInfo_Response & msg)
{
  return wujihand_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<wujihand_msgs::srv::GetHandInfo_Response>()
{
  return "wujihand_msgs::srv::GetHandInfo_Response";
}

template<>
inline const char * name<wujihand_msgs::srv::GetHandInfo_Response>()
{
  return "wujihand_msgs/srv/GetHandInfo_Response";
}

template<>
struct has_fixed_size<wujihand_msgs::srv::GetHandInfo_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<wujihand_msgs::srv::GetHandInfo_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<wujihand_msgs::srv::GetHandInfo_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace wujihand_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetHandInfo_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
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
  const GetHandInfo_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetHandInfo_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace wujihand_msgs

namespace rosidl_generator_traits
{

[[deprecated("use wujihand_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const wujihand_msgs::srv::GetHandInfo_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  wujihand_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use wujihand_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const wujihand_msgs::srv::GetHandInfo_Event & msg)
{
  return wujihand_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<wujihand_msgs::srv::GetHandInfo_Event>()
{
  return "wujihand_msgs::srv::GetHandInfo_Event";
}

template<>
inline const char * name<wujihand_msgs::srv::GetHandInfo_Event>()
{
  return "wujihand_msgs/srv/GetHandInfo_Event";
}

template<>
struct has_fixed_size<wujihand_msgs::srv::GetHandInfo_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<wujihand_msgs::srv::GetHandInfo_Event>
  : std::integral_constant<bool, has_bounded_size<service_msgs::msg::ServiceEventInfo>::value && has_bounded_size<wujihand_msgs::srv::GetHandInfo_Request>::value && has_bounded_size<wujihand_msgs::srv::GetHandInfo_Response>::value> {};

template<>
struct is_message<wujihand_msgs::srv::GetHandInfo_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<wujihand_msgs::srv::GetHandInfo>()
{
  return "wujihand_msgs::srv::GetHandInfo";
}

template<>
inline const char * name<wujihand_msgs::srv::GetHandInfo>()
{
  return "wujihand_msgs/srv/GetHandInfo";
}

template<>
struct has_fixed_size<wujihand_msgs::srv::GetHandInfo>
  : std::integral_constant<
    bool,
    has_fixed_size<wujihand_msgs::srv::GetHandInfo_Request>::value &&
    has_fixed_size<wujihand_msgs::srv::GetHandInfo_Response>::value
  >
{
};

template<>
struct has_bounded_size<wujihand_msgs::srv::GetHandInfo>
  : std::integral_constant<
    bool,
    has_bounded_size<wujihand_msgs::srv::GetHandInfo_Request>::value &&
    has_bounded_size<wujihand_msgs::srv::GetHandInfo_Response>::value
  >
{
};

template<>
struct is_service<wujihand_msgs::srv::GetHandInfo>
  : std::true_type
{
};

template<>
struct is_service_request<wujihand_msgs::srv::GetHandInfo_Request>
  : std::true_type
{
};

template<>
struct is_service_response<wujihand_msgs::srv::GetHandInfo_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // WUJIHAND_MSGS__SRV__DETAIL__GET_HAND_INFO__TRAITS_HPP_
