// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from wujihand_msgs:srv/GetHandInfo.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "wujihand_msgs/srv/detail/get_hand_info__functions.h"
#include "wujihand_msgs/srv/detail/get_hand_info__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace wujihand_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void GetHandInfo_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) wujihand_msgs::srv::GetHandInfo_Request(_init);
}

void GetHandInfo_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<wujihand_msgs::srv::GetHandInfo_Request *>(message_memory);
  typed_message->~GetHandInfo_Request();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember GetHandInfo_Request_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wujihand_msgs::srv::GetHandInfo_Request, structure_needs_at_least_one_member),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers GetHandInfo_Request_message_members = {
  "wujihand_msgs::srv",  // message namespace
  "GetHandInfo_Request",  // message name
  1,  // number of fields
  sizeof(wujihand_msgs::srv::GetHandInfo_Request),
  false,  // has_any_key_member_
  GetHandInfo_Request_message_member_array,  // message members
  GetHandInfo_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  GetHandInfo_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t GetHandInfo_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GetHandInfo_Request_message_members,
  get_message_typesupport_handle_function,
  &wujihand_msgs__srv__GetHandInfo_Request__get_type_hash,
  &wujihand_msgs__srv__GetHandInfo_Request__get_type_description,
  &wujihand_msgs__srv__GetHandInfo_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace wujihand_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<wujihand_msgs::srv::GetHandInfo_Request>()
{
  return &::wujihand_msgs::srv::rosidl_typesupport_introspection_cpp::GetHandInfo_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, wujihand_msgs, srv, GetHandInfo_Request)() {
  return &::wujihand_msgs::srv::rosidl_typesupport_introspection_cpp::GetHandInfo_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "wujihand_msgs/srv/detail/get_hand_info__functions.h"
// already included above
// #include "wujihand_msgs/srv/detail/get_hand_info__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace wujihand_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void GetHandInfo_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) wujihand_msgs::srv::GetHandInfo_Response(_init);
}

void GetHandInfo_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<wujihand_msgs::srv::GetHandInfo_Response *>(message_memory);
  typed_message->~GetHandInfo_Response();
}

size_t size_function__GetHandInfo_Response__upper_limits(const void * untyped_member)
{
  (void)untyped_member;
  return 20;
}

const void * get_const_function__GetHandInfo_Response__upper_limits(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 20> *>(untyped_member);
  return &member[index];
}

void * get_function__GetHandInfo_Response__upper_limits(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 20> *>(untyped_member);
  return &member[index];
}

void fetch_function__GetHandInfo_Response__upper_limits(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__GetHandInfo_Response__upper_limits(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__GetHandInfo_Response__upper_limits(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__GetHandInfo_Response__upper_limits(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

size_t size_function__GetHandInfo_Response__lower_limits(const void * untyped_member)
{
  (void)untyped_member;
  return 20;
}

const void * get_const_function__GetHandInfo_Response__lower_limits(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 20> *>(untyped_member);
  return &member[index];
}

void * get_function__GetHandInfo_Response__lower_limits(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 20> *>(untyped_member);
  return &member[index];
}

void fetch_function__GetHandInfo_Response__lower_limits(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__GetHandInfo_Response__lower_limits(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__GetHandInfo_Response__lower_limits(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__GetHandInfo_Response__lower_limits(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember GetHandInfo_Response_message_member_array[4] = {
  {
    "handedness",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wujihand_msgs::srv::GetHandInfo_Response, handedness),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "firmware_version",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wujihand_msgs::srv::GetHandInfo_Response, firmware_version),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "upper_limits",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    20,  // array size
    false,  // is upper bound
    offsetof(wujihand_msgs::srv::GetHandInfo_Response, upper_limits),  // bytes offset in struct
    nullptr,  // default value
    size_function__GetHandInfo_Response__upper_limits,  // size() function pointer
    get_const_function__GetHandInfo_Response__upper_limits,  // get_const(index) function pointer
    get_function__GetHandInfo_Response__upper_limits,  // get(index) function pointer
    fetch_function__GetHandInfo_Response__upper_limits,  // fetch(index, &value) function pointer
    assign_function__GetHandInfo_Response__upper_limits,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "lower_limits",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    20,  // array size
    false,  // is upper bound
    offsetof(wujihand_msgs::srv::GetHandInfo_Response, lower_limits),  // bytes offset in struct
    nullptr,  // default value
    size_function__GetHandInfo_Response__lower_limits,  // size() function pointer
    get_const_function__GetHandInfo_Response__lower_limits,  // get_const(index) function pointer
    get_function__GetHandInfo_Response__lower_limits,  // get(index) function pointer
    fetch_function__GetHandInfo_Response__lower_limits,  // fetch(index, &value) function pointer
    assign_function__GetHandInfo_Response__lower_limits,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers GetHandInfo_Response_message_members = {
  "wujihand_msgs::srv",  // message namespace
  "GetHandInfo_Response",  // message name
  4,  // number of fields
  sizeof(wujihand_msgs::srv::GetHandInfo_Response),
  false,  // has_any_key_member_
  GetHandInfo_Response_message_member_array,  // message members
  GetHandInfo_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  GetHandInfo_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t GetHandInfo_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GetHandInfo_Response_message_members,
  get_message_typesupport_handle_function,
  &wujihand_msgs__srv__GetHandInfo_Response__get_type_hash,
  &wujihand_msgs__srv__GetHandInfo_Response__get_type_description,
  &wujihand_msgs__srv__GetHandInfo_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace wujihand_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<wujihand_msgs::srv::GetHandInfo_Response>()
{
  return &::wujihand_msgs::srv::rosidl_typesupport_introspection_cpp::GetHandInfo_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, wujihand_msgs, srv, GetHandInfo_Response)() {
  return &::wujihand_msgs::srv::rosidl_typesupport_introspection_cpp::GetHandInfo_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "wujihand_msgs/srv/detail/get_hand_info__functions.h"
// already included above
// #include "wujihand_msgs/srv/detail/get_hand_info__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace wujihand_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void GetHandInfo_Event_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) wujihand_msgs::srv::GetHandInfo_Event(_init);
}

void GetHandInfo_Event_fini_function(void * message_memory)
{
  auto typed_message = static_cast<wujihand_msgs::srv::GetHandInfo_Event *>(message_memory);
  typed_message->~GetHandInfo_Event();
}

size_t size_function__GetHandInfo_Event__request(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<wujihand_msgs::srv::GetHandInfo_Request> *>(untyped_member);
  return member->size();
}

const void * get_const_function__GetHandInfo_Event__request(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<wujihand_msgs::srv::GetHandInfo_Request> *>(untyped_member);
  return &member[index];
}

void * get_function__GetHandInfo_Event__request(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<wujihand_msgs::srv::GetHandInfo_Request> *>(untyped_member);
  return &member[index];
}

void fetch_function__GetHandInfo_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const wujihand_msgs::srv::GetHandInfo_Request *>(
    get_const_function__GetHandInfo_Event__request(untyped_member, index));
  auto & value = *reinterpret_cast<wujihand_msgs::srv::GetHandInfo_Request *>(untyped_value);
  value = item;
}

void assign_function__GetHandInfo_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<wujihand_msgs::srv::GetHandInfo_Request *>(
    get_function__GetHandInfo_Event__request(untyped_member, index));
  const auto & value = *reinterpret_cast<const wujihand_msgs::srv::GetHandInfo_Request *>(untyped_value);
  item = value;
}

void resize_function__GetHandInfo_Event__request(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<wujihand_msgs::srv::GetHandInfo_Request> *>(untyped_member);
  member->resize(size);
}

size_t size_function__GetHandInfo_Event__response(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<wujihand_msgs::srv::GetHandInfo_Response> *>(untyped_member);
  return member->size();
}

const void * get_const_function__GetHandInfo_Event__response(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<wujihand_msgs::srv::GetHandInfo_Response> *>(untyped_member);
  return &member[index];
}

void * get_function__GetHandInfo_Event__response(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<wujihand_msgs::srv::GetHandInfo_Response> *>(untyped_member);
  return &member[index];
}

void fetch_function__GetHandInfo_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const wujihand_msgs::srv::GetHandInfo_Response *>(
    get_const_function__GetHandInfo_Event__response(untyped_member, index));
  auto & value = *reinterpret_cast<wujihand_msgs::srv::GetHandInfo_Response *>(untyped_value);
  value = item;
}

void assign_function__GetHandInfo_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<wujihand_msgs::srv::GetHandInfo_Response *>(
    get_function__GetHandInfo_Event__response(untyped_member, index));
  const auto & value = *reinterpret_cast<const wujihand_msgs::srv::GetHandInfo_Response *>(untyped_value);
  item = value;
}

void resize_function__GetHandInfo_Event__response(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<wujihand_msgs::srv::GetHandInfo_Response> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember GetHandInfo_Event_message_member_array[3] = {
  {
    "info",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<service_msgs::msg::ServiceEventInfo>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wujihand_msgs::srv::GetHandInfo_Event, info),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "request",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<wujihand_msgs::srv::GetHandInfo_Request>(),  // members of sub message
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(wujihand_msgs::srv::GetHandInfo_Event, request),  // bytes offset in struct
    nullptr,  // default value
    size_function__GetHandInfo_Event__request,  // size() function pointer
    get_const_function__GetHandInfo_Event__request,  // get_const(index) function pointer
    get_function__GetHandInfo_Event__request,  // get(index) function pointer
    fetch_function__GetHandInfo_Event__request,  // fetch(index, &value) function pointer
    assign_function__GetHandInfo_Event__request,  // assign(index, value) function pointer
    resize_function__GetHandInfo_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<wujihand_msgs::srv::GetHandInfo_Response>(),  // members of sub message
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(wujihand_msgs::srv::GetHandInfo_Event, response),  // bytes offset in struct
    nullptr,  // default value
    size_function__GetHandInfo_Event__response,  // size() function pointer
    get_const_function__GetHandInfo_Event__response,  // get_const(index) function pointer
    get_function__GetHandInfo_Event__response,  // get(index) function pointer
    fetch_function__GetHandInfo_Event__response,  // fetch(index, &value) function pointer
    assign_function__GetHandInfo_Event__response,  // assign(index, value) function pointer
    resize_function__GetHandInfo_Event__response  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers GetHandInfo_Event_message_members = {
  "wujihand_msgs::srv",  // message namespace
  "GetHandInfo_Event",  // message name
  3,  // number of fields
  sizeof(wujihand_msgs::srv::GetHandInfo_Event),
  false,  // has_any_key_member_
  GetHandInfo_Event_message_member_array,  // message members
  GetHandInfo_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  GetHandInfo_Event_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t GetHandInfo_Event_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GetHandInfo_Event_message_members,
  get_message_typesupport_handle_function,
  &wujihand_msgs__srv__GetHandInfo_Event__get_type_hash,
  &wujihand_msgs__srv__GetHandInfo_Event__get_type_description,
  &wujihand_msgs__srv__GetHandInfo_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace wujihand_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<wujihand_msgs::srv::GetHandInfo_Event>()
{
  return &::wujihand_msgs::srv::rosidl_typesupport_introspection_cpp::GetHandInfo_Event_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, wujihand_msgs, srv, GetHandInfo_Event)() {
  return &::wujihand_msgs::srv::rosidl_typesupport_introspection_cpp::GetHandInfo_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "wujihand_msgs/srv/detail/get_hand_info__functions.h"
// already included above
// #include "wujihand_msgs/srv/detail/get_hand_info__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace wujihand_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers GetHandInfo_service_members = {
  "wujihand_msgs::srv",  // service namespace
  "GetHandInfo",  // service name
  // the following fields are initialized below on first access
  // see get_service_type_support_handle<wujihand_msgs::srv::GetHandInfo>()
  nullptr,  // request message
  nullptr,  // response message
  nullptr,  // event message
};

static const rosidl_service_type_support_t GetHandInfo_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GetHandInfo_service_members,
  get_service_typesupport_handle_function,
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<wujihand_msgs::srv::GetHandInfo_Request>(),
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<wujihand_msgs::srv::GetHandInfo_Response>(),
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<wujihand_msgs::srv::GetHandInfo_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<wujihand_msgs::srv::GetHandInfo>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<wujihand_msgs::srv::GetHandInfo>,
  &wujihand_msgs__srv__GetHandInfo__get_type_hash,
  &wujihand_msgs__srv__GetHandInfo__get_type_description,
  &wujihand_msgs__srv__GetHandInfo__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace wujihand_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<wujihand_msgs::srv::GetHandInfo>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::wujihand_msgs::srv::rosidl_typesupport_introspection_cpp::GetHandInfo_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure all of the service_members are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr ||
    service_members->event_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::wujihand_msgs::srv::GetHandInfo_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::wujihand_msgs::srv::GetHandInfo_Response
      >()->data
      );
    // initialize the event_members_ with the static function from the external library
    service_members->event_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::wujihand_msgs::srv::GetHandInfo_Event
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, wujihand_msgs, srv, GetHandInfo)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<wujihand_msgs::srv::GetHandInfo>();
}

#ifdef __cplusplus
}
#endif
