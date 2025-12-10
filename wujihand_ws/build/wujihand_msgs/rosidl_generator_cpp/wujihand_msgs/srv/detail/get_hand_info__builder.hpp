// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from wujihand_msgs:srv/GetHandInfo.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "wujihand_msgs/srv/get_hand_info.hpp"


#ifndef WUJIHAND_MSGS__SRV__DETAIL__GET_HAND_INFO__BUILDER_HPP_
#define WUJIHAND_MSGS__SRV__DETAIL__GET_HAND_INFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "wujihand_msgs/srv/detail/get_hand_info__struct.hpp"
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
auto build<::wujihand_msgs::srv::GetHandInfo_Request>()
{
  return ::wujihand_msgs::srv::GetHandInfo_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace wujihand_msgs


namespace wujihand_msgs
{

namespace srv
{

namespace builder
{

class Init_GetHandInfo_Response_lower_limits
{
public:
  explicit Init_GetHandInfo_Response_lower_limits(::wujihand_msgs::srv::GetHandInfo_Response & msg)
  : msg_(msg)
  {}
  ::wujihand_msgs::srv::GetHandInfo_Response lower_limits(::wujihand_msgs::srv::GetHandInfo_Response::_lower_limits_type arg)
  {
    msg_.lower_limits = std::move(arg);
    return std::move(msg_);
  }

private:
  ::wujihand_msgs::srv::GetHandInfo_Response msg_;
};

class Init_GetHandInfo_Response_upper_limits
{
public:
  explicit Init_GetHandInfo_Response_upper_limits(::wujihand_msgs::srv::GetHandInfo_Response & msg)
  : msg_(msg)
  {}
  Init_GetHandInfo_Response_lower_limits upper_limits(::wujihand_msgs::srv::GetHandInfo_Response::_upper_limits_type arg)
  {
    msg_.upper_limits = std::move(arg);
    return Init_GetHandInfo_Response_lower_limits(msg_);
  }

private:
  ::wujihand_msgs::srv::GetHandInfo_Response msg_;
};

class Init_GetHandInfo_Response_firmware_version
{
public:
  explicit Init_GetHandInfo_Response_firmware_version(::wujihand_msgs::srv::GetHandInfo_Response & msg)
  : msg_(msg)
  {}
  Init_GetHandInfo_Response_upper_limits firmware_version(::wujihand_msgs::srv::GetHandInfo_Response::_firmware_version_type arg)
  {
    msg_.firmware_version = std::move(arg);
    return Init_GetHandInfo_Response_upper_limits(msg_);
  }

private:
  ::wujihand_msgs::srv::GetHandInfo_Response msg_;
};

class Init_GetHandInfo_Response_handedness
{
public:
  Init_GetHandInfo_Response_handedness()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetHandInfo_Response_firmware_version handedness(::wujihand_msgs::srv::GetHandInfo_Response::_handedness_type arg)
  {
    msg_.handedness = std::move(arg);
    return Init_GetHandInfo_Response_firmware_version(msg_);
  }

private:
  ::wujihand_msgs::srv::GetHandInfo_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::wujihand_msgs::srv::GetHandInfo_Response>()
{
  return wujihand_msgs::srv::builder::Init_GetHandInfo_Response_handedness();
}

}  // namespace wujihand_msgs


namespace wujihand_msgs
{

namespace srv
{

namespace builder
{

class Init_GetHandInfo_Event_response
{
public:
  explicit Init_GetHandInfo_Event_response(::wujihand_msgs::srv::GetHandInfo_Event & msg)
  : msg_(msg)
  {}
  ::wujihand_msgs::srv::GetHandInfo_Event response(::wujihand_msgs::srv::GetHandInfo_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::wujihand_msgs::srv::GetHandInfo_Event msg_;
};

class Init_GetHandInfo_Event_request
{
public:
  explicit Init_GetHandInfo_Event_request(::wujihand_msgs::srv::GetHandInfo_Event & msg)
  : msg_(msg)
  {}
  Init_GetHandInfo_Event_response request(::wujihand_msgs::srv::GetHandInfo_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_GetHandInfo_Event_response(msg_);
  }

private:
  ::wujihand_msgs::srv::GetHandInfo_Event msg_;
};

class Init_GetHandInfo_Event_info
{
public:
  Init_GetHandInfo_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetHandInfo_Event_request info(::wujihand_msgs::srv::GetHandInfo_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_GetHandInfo_Event_request(msg_);
  }

private:
  ::wujihand_msgs::srv::GetHandInfo_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::wujihand_msgs::srv::GetHandInfo_Event>()
{
  return wujihand_msgs::srv::builder::Init_GetHandInfo_Event_info();
}

}  // namespace wujihand_msgs

#endif  // WUJIHAND_MSGS__SRV__DETAIL__GET_HAND_INFO__BUILDER_HPP_
