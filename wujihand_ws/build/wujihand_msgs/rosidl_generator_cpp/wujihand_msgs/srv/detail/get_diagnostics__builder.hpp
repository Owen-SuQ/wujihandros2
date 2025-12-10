// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from wujihand_msgs:srv/GetDiagnostics.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "wujihand_msgs/srv/get_diagnostics.hpp"


#ifndef WUJIHAND_MSGS__SRV__DETAIL__GET_DIAGNOSTICS__BUILDER_HPP_
#define WUJIHAND_MSGS__SRV__DETAIL__GET_DIAGNOSTICS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "wujihand_msgs/srv/detail/get_diagnostics__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace wujihand_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::wujihand_msgs::srv::GetDiagnostics_Request>()
{
  return ::wujihand_msgs::srv::GetDiagnostics_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace wujihand_msgs


namespace wujihand_msgs
{

namespace srv
{

namespace builder
{

class Init_GetDiagnostics_Response_error_codes
{
public:
  explicit Init_GetDiagnostics_Response_error_codes(::wujihand_msgs::srv::GetDiagnostics_Response & msg)
  : msg_(msg)
  {}
  ::wujihand_msgs::srv::GetDiagnostics_Response error_codes(::wujihand_msgs::srv::GetDiagnostics_Response::_error_codes_type arg)
  {
    msg_.error_codes = std::move(arg);
    return std::move(msg_);
  }

private:
  ::wujihand_msgs::srv::GetDiagnostics_Response msg_;
};

class Init_GetDiagnostics_Response_joint_temperatures
{
public:
  explicit Init_GetDiagnostics_Response_joint_temperatures(::wujihand_msgs::srv::GetDiagnostics_Response & msg)
  : msg_(msg)
  {}
  Init_GetDiagnostics_Response_error_codes joint_temperatures(::wujihand_msgs::srv::GetDiagnostics_Response::_joint_temperatures_type arg)
  {
    msg_.joint_temperatures = std::move(arg);
    return Init_GetDiagnostics_Response_error_codes(msg_);
  }

private:
  ::wujihand_msgs::srv::GetDiagnostics_Response msg_;
};

class Init_GetDiagnostics_Response_input_voltage
{
public:
  explicit Init_GetDiagnostics_Response_input_voltage(::wujihand_msgs::srv::GetDiagnostics_Response & msg)
  : msg_(msg)
  {}
  Init_GetDiagnostics_Response_joint_temperatures input_voltage(::wujihand_msgs::srv::GetDiagnostics_Response::_input_voltage_type arg)
  {
    msg_.input_voltage = std::move(arg);
    return Init_GetDiagnostics_Response_joint_temperatures(msg_);
  }

private:
  ::wujihand_msgs::srv::GetDiagnostics_Response msg_;
};

class Init_GetDiagnostics_Response_system_temperature
{
public:
  Init_GetDiagnostics_Response_system_temperature()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetDiagnostics_Response_input_voltage system_temperature(::wujihand_msgs::srv::GetDiagnostics_Response::_system_temperature_type arg)
  {
    msg_.system_temperature = std::move(arg);
    return Init_GetDiagnostics_Response_input_voltage(msg_);
  }

private:
  ::wujihand_msgs::srv::GetDiagnostics_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::wujihand_msgs::srv::GetDiagnostics_Response>()
{
  return wujihand_msgs::srv::builder::Init_GetDiagnostics_Response_system_temperature();
}

}  // namespace wujihand_msgs


namespace wujihand_msgs
{

namespace srv
{

namespace builder
{

class Init_GetDiagnostics_Event_response
{
public:
  explicit Init_GetDiagnostics_Event_response(::wujihand_msgs::srv::GetDiagnostics_Event & msg)
  : msg_(msg)
  {}
  ::wujihand_msgs::srv::GetDiagnostics_Event response(::wujihand_msgs::srv::GetDiagnostics_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::wujihand_msgs::srv::GetDiagnostics_Event msg_;
};

class Init_GetDiagnostics_Event_request
{
public:
  explicit Init_GetDiagnostics_Event_request(::wujihand_msgs::srv::GetDiagnostics_Event & msg)
  : msg_(msg)
  {}
  Init_GetDiagnostics_Event_response request(::wujihand_msgs::srv::GetDiagnostics_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_GetDiagnostics_Event_response(msg_);
  }

private:
  ::wujihand_msgs::srv::GetDiagnostics_Event msg_;
};

class Init_GetDiagnostics_Event_info
{
public:
  Init_GetDiagnostics_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetDiagnostics_Event_request info(::wujihand_msgs::srv::GetDiagnostics_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_GetDiagnostics_Event_request(msg_);
  }

private:
  ::wujihand_msgs::srv::GetDiagnostics_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::wujihand_msgs::srv::GetDiagnostics_Event>()
{
  return wujihand_msgs::srv::builder::Init_GetDiagnostics_Event_info();
}

}  // namespace wujihand_msgs

#endif  // WUJIHAND_MSGS__SRV__DETAIL__GET_DIAGNOSTICS__BUILDER_HPP_
