// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from wujihand_msgs:srv/ResetError.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "wujihand_msgs/srv/reset_error.hpp"


#ifndef WUJIHAND_MSGS__SRV__DETAIL__RESET_ERROR__BUILDER_HPP_
#define WUJIHAND_MSGS__SRV__DETAIL__RESET_ERROR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "wujihand_msgs/srv/detail/reset_error__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace wujihand_msgs
{

namespace srv
{

namespace builder
{

class Init_ResetError_Request_joint_id
{
public:
  explicit Init_ResetError_Request_joint_id(::wujihand_msgs::srv::ResetError_Request & msg)
  : msg_(msg)
  {}
  ::wujihand_msgs::srv::ResetError_Request joint_id(::wujihand_msgs::srv::ResetError_Request::_joint_id_type arg)
  {
    msg_.joint_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::wujihand_msgs::srv::ResetError_Request msg_;
};

class Init_ResetError_Request_finger_id
{
public:
  Init_ResetError_Request_finger_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ResetError_Request_joint_id finger_id(::wujihand_msgs::srv::ResetError_Request::_finger_id_type arg)
  {
    msg_.finger_id = std::move(arg);
    return Init_ResetError_Request_joint_id(msg_);
  }

private:
  ::wujihand_msgs::srv::ResetError_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::wujihand_msgs::srv::ResetError_Request>()
{
  return wujihand_msgs::srv::builder::Init_ResetError_Request_finger_id();
}

}  // namespace wujihand_msgs


namespace wujihand_msgs
{

namespace srv
{

namespace builder
{

class Init_ResetError_Response_message
{
public:
  explicit Init_ResetError_Response_message(::wujihand_msgs::srv::ResetError_Response & msg)
  : msg_(msg)
  {}
  ::wujihand_msgs::srv::ResetError_Response message(::wujihand_msgs::srv::ResetError_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::wujihand_msgs::srv::ResetError_Response msg_;
};

class Init_ResetError_Response_success
{
public:
  Init_ResetError_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ResetError_Response_message success(::wujihand_msgs::srv::ResetError_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_ResetError_Response_message(msg_);
  }

private:
  ::wujihand_msgs::srv::ResetError_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::wujihand_msgs::srv::ResetError_Response>()
{
  return wujihand_msgs::srv::builder::Init_ResetError_Response_success();
}

}  // namespace wujihand_msgs


namespace wujihand_msgs
{

namespace srv
{

namespace builder
{

class Init_ResetError_Event_response
{
public:
  explicit Init_ResetError_Event_response(::wujihand_msgs::srv::ResetError_Event & msg)
  : msg_(msg)
  {}
  ::wujihand_msgs::srv::ResetError_Event response(::wujihand_msgs::srv::ResetError_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::wujihand_msgs::srv::ResetError_Event msg_;
};

class Init_ResetError_Event_request
{
public:
  explicit Init_ResetError_Event_request(::wujihand_msgs::srv::ResetError_Event & msg)
  : msg_(msg)
  {}
  Init_ResetError_Event_response request(::wujihand_msgs::srv::ResetError_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_ResetError_Event_response(msg_);
  }

private:
  ::wujihand_msgs::srv::ResetError_Event msg_;
};

class Init_ResetError_Event_info
{
public:
  Init_ResetError_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ResetError_Event_request info(::wujihand_msgs::srv::ResetError_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_ResetError_Event_request(msg_);
  }

private:
  ::wujihand_msgs::srv::ResetError_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::wujihand_msgs::srv::ResetError_Event>()
{
  return wujihand_msgs::srv::builder::Init_ResetError_Event_info();
}

}  // namespace wujihand_msgs

#endif  // WUJIHAND_MSGS__SRV__DETAIL__RESET_ERROR__BUILDER_HPP_
