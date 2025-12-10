// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from wujihand_msgs:srv/GetDiagnostics.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "wujihand_msgs/srv/get_diagnostics.hpp"


#ifndef WUJIHAND_MSGS__SRV__DETAIL__GET_DIAGNOSTICS__TRAITS_HPP_
#define WUJIHAND_MSGS__SRV__DETAIL__GET_DIAGNOSTICS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "wujihand_msgs/srv/detail/get_diagnostics__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace wujihand_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetDiagnostics_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetDiagnostics_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetDiagnostics_Request & msg, bool use_flow_style = false)
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
  const wujihand_msgs::srv::GetDiagnostics_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  wujihand_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use wujihand_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const wujihand_msgs::srv::GetDiagnostics_Request & msg)
{
  return wujihand_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<wujihand_msgs::srv::GetDiagnostics_Request>()
{
  return "wujihand_msgs::srv::GetDiagnostics_Request";
}

template<>
inline const char * name<wujihand_msgs::srv::GetDiagnostics_Request>()
{
  return "wujihand_msgs/srv/GetDiagnostics_Request";
}

template<>
struct has_fixed_size<wujihand_msgs::srv::GetDiagnostics_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<wujihand_msgs::srv::GetDiagnostics_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<wujihand_msgs::srv::GetDiagnostics_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace wujihand_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetDiagnostics_Response & msg,
  std::ostream & out)
{
  out << "{";
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
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetDiagnostics_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetDiagnostics_Response & msg, bool use_flow_style = false)
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
  const wujihand_msgs::srv::GetDiagnostics_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  wujihand_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use wujihand_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const wujihand_msgs::srv::GetDiagnostics_Response & msg)
{
  return wujihand_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<wujihand_msgs::srv::GetDiagnostics_Response>()
{
  return "wujihand_msgs::srv::GetDiagnostics_Response";
}

template<>
inline const char * name<wujihand_msgs::srv::GetDiagnostics_Response>()
{
  return "wujihand_msgs/srv/GetDiagnostics_Response";
}

template<>
struct has_fixed_size<wujihand_msgs::srv::GetDiagnostics_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<wujihand_msgs::srv::GetDiagnostics_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<wujihand_msgs::srv::GetDiagnostics_Response>
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
  const GetDiagnostics_Event & msg,
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
  const GetDiagnostics_Event & msg,
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

inline std::string to_yaml(const GetDiagnostics_Event & msg, bool use_flow_style = false)
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
  const wujihand_msgs::srv::GetDiagnostics_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  wujihand_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use wujihand_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const wujihand_msgs::srv::GetDiagnostics_Event & msg)
{
  return wujihand_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<wujihand_msgs::srv::GetDiagnostics_Event>()
{
  return "wujihand_msgs::srv::GetDiagnostics_Event";
}

template<>
inline const char * name<wujihand_msgs::srv::GetDiagnostics_Event>()
{
  return "wujihand_msgs/srv/GetDiagnostics_Event";
}

template<>
struct has_fixed_size<wujihand_msgs::srv::GetDiagnostics_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<wujihand_msgs::srv::GetDiagnostics_Event>
  : std::integral_constant<bool, has_bounded_size<service_msgs::msg::ServiceEventInfo>::value && has_bounded_size<wujihand_msgs::srv::GetDiagnostics_Request>::value && has_bounded_size<wujihand_msgs::srv::GetDiagnostics_Response>::value> {};

template<>
struct is_message<wujihand_msgs::srv::GetDiagnostics_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<wujihand_msgs::srv::GetDiagnostics>()
{
  return "wujihand_msgs::srv::GetDiagnostics";
}

template<>
inline const char * name<wujihand_msgs::srv::GetDiagnostics>()
{
  return "wujihand_msgs/srv/GetDiagnostics";
}

template<>
struct has_fixed_size<wujihand_msgs::srv::GetDiagnostics>
  : std::integral_constant<
    bool,
    has_fixed_size<wujihand_msgs::srv::GetDiagnostics_Request>::value &&
    has_fixed_size<wujihand_msgs::srv::GetDiagnostics_Response>::value
  >
{
};

template<>
struct has_bounded_size<wujihand_msgs::srv::GetDiagnostics>
  : std::integral_constant<
    bool,
    has_bounded_size<wujihand_msgs::srv::GetDiagnostics_Request>::value &&
    has_bounded_size<wujihand_msgs::srv::GetDiagnostics_Response>::value
  >
{
};

template<>
struct is_service<wujihand_msgs::srv::GetDiagnostics>
  : std::true_type
{
};

template<>
struct is_service_request<wujihand_msgs::srv::GetDiagnostics_Request>
  : std::true_type
{
};

template<>
struct is_service_response<wujihand_msgs::srv::GetDiagnostics_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // WUJIHAND_MSGS__SRV__DETAIL__GET_DIAGNOSTICS__TRAITS_HPP_
