// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from wujihand_msgs:msg/HandState.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "wujihand_msgs/msg/detail/hand_state__functions.h"
#include "wujihand_msgs/msg/detail/hand_state__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace wujihand_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void HandState_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) wujihand_msgs::msg::HandState(_init);
}

void HandState_fini_function(void * message_memory)
{
  auto typed_message = static_cast<wujihand_msgs::msg::HandState *>(message_memory);
  typed_message->~HandState();
}

size_t size_function__HandState__actual_positions(const void * untyped_member)
{
  (void)untyped_member;
  return 20;
}

const void * get_const_function__HandState__actual_positions(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 20> *>(untyped_member);
  return &member[index];
}

void * get_function__HandState__actual_positions(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 20> *>(untyped_member);
  return &member[index];
}

void fetch_function__HandState__actual_positions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__HandState__actual_positions(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__HandState__actual_positions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__HandState__actual_positions(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

size_t size_function__HandState__target_positions(const void * untyped_member)
{
  (void)untyped_member;
  return 20;
}

const void * get_const_function__HandState__target_positions(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 20> *>(untyped_member);
  return &member[index];
}

void * get_function__HandState__target_positions(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 20> *>(untyped_member);
  return &member[index];
}

void fetch_function__HandState__target_positions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__HandState__target_positions(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__HandState__target_positions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__HandState__target_positions(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

size_t size_function__HandState__joint_temperatures(const void * untyped_member)
{
  (void)untyped_member;
  return 20;
}

const void * get_const_function__HandState__joint_temperatures(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 20> *>(untyped_member);
  return &member[index];
}

void * get_function__HandState__joint_temperatures(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 20> *>(untyped_member);
  return &member[index];
}

void fetch_function__HandState__joint_temperatures(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__HandState__joint_temperatures(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__HandState__joint_temperatures(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__HandState__joint_temperatures(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

size_t size_function__HandState__error_codes(const void * untyped_member)
{
  (void)untyped_member;
  return 20;
}

const void * get_const_function__HandState__error_codes(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<uint32_t, 20> *>(untyped_member);
  return &member[index];
}

void * get_function__HandState__error_codes(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<uint32_t, 20> *>(untyped_member);
  return &member[index];
}

void fetch_function__HandState__error_codes(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint32_t *>(
    get_const_function__HandState__error_codes(untyped_member, index));
  auto & value = *reinterpret_cast<uint32_t *>(untyped_value);
  value = item;
}

void assign_function__HandState__error_codes(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint32_t *>(
    get_function__HandState__error_codes(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint32_t *>(untyped_value);
  item = value;
}

size_t size_function__HandState__enabled(const void * untyped_member)
{
  (void)untyped_member;
  return 20;
}

const void * get_const_function__HandState__enabled(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<bool, 20> *>(untyped_member);
  return &member[index];
}

void * get_function__HandState__enabled(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<bool, 20> *>(untyped_member);
  return &member[index];
}

void fetch_function__HandState__enabled(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const bool *>(
    get_const_function__HandState__enabled(untyped_member, index));
  auto & value = *reinterpret_cast<bool *>(untyped_value);
  value = item;
}

void assign_function__HandState__enabled(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<bool *>(
    get_function__HandState__enabled(untyped_member, index));
  const auto & value = *reinterpret_cast<const bool *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember HandState_message_member_array[9] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wujihand_msgs::msg::HandState, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "handedness",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wujihand_msgs::msg::HandState, handedness),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "system_temperature",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wujihand_msgs::msg::HandState, system_temperature),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "input_voltage",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wujihand_msgs::msg::HandState, input_voltage),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "actual_positions",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    20,  // array size
    false,  // is upper bound
    offsetof(wujihand_msgs::msg::HandState, actual_positions),  // bytes offset in struct
    nullptr,  // default value
    size_function__HandState__actual_positions,  // size() function pointer
    get_const_function__HandState__actual_positions,  // get_const(index) function pointer
    get_function__HandState__actual_positions,  // get(index) function pointer
    fetch_function__HandState__actual_positions,  // fetch(index, &value) function pointer
    assign_function__HandState__actual_positions,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "target_positions",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    20,  // array size
    false,  // is upper bound
    offsetof(wujihand_msgs::msg::HandState, target_positions),  // bytes offset in struct
    nullptr,  // default value
    size_function__HandState__target_positions,  // size() function pointer
    get_const_function__HandState__target_positions,  // get_const(index) function pointer
    get_function__HandState__target_positions,  // get(index) function pointer
    fetch_function__HandState__target_positions,  // fetch(index, &value) function pointer
    assign_function__HandState__target_positions,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "joint_temperatures",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    20,  // array size
    false,  // is upper bound
    offsetof(wujihand_msgs::msg::HandState, joint_temperatures),  // bytes offset in struct
    nullptr,  // default value
    size_function__HandState__joint_temperatures,  // size() function pointer
    get_const_function__HandState__joint_temperatures,  // get_const(index) function pointer
    get_function__HandState__joint_temperatures,  // get(index) function pointer
    fetch_function__HandState__joint_temperatures,  // fetch(index, &value) function pointer
    assign_function__HandState__joint_temperatures,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "error_codes",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    20,  // array size
    false,  // is upper bound
    offsetof(wujihand_msgs::msg::HandState, error_codes),  // bytes offset in struct
    nullptr,  // default value
    size_function__HandState__error_codes,  // size() function pointer
    get_const_function__HandState__error_codes,  // get_const(index) function pointer
    get_function__HandState__error_codes,  // get(index) function pointer
    fetch_function__HandState__error_codes,  // fetch(index, &value) function pointer
    assign_function__HandState__error_codes,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "enabled",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    20,  // array size
    false,  // is upper bound
    offsetof(wujihand_msgs::msg::HandState, enabled),  // bytes offset in struct
    nullptr,  // default value
    size_function__HandState__enabled,  // size() function pointer
    get_const_function__HandState__enabled,  // get_const(index) function pointer
    get_function__HandState__enabled,  // get(index) function pointer
    fetch_function__HandState__enabled,  // fetch(index, &value) function pointer
    assign_function__HandState__enabled,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers HandState_message_members = {
  "wujihand_msgs::msg",  // message namespace
  "HandState",  // message name
  9,  // number of fields
  sizeof(wujihand_msgs::msg::HandState),
  false,  // has_any_key_member_
  HandState_message_member_array,  // message members
  HandState_init_function,  // function to initialize message memory (memory has to be allocated)
  HandState_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t HandState_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &HandState_message_members,
  get_message_typesupport_handle_function,
  &wujihand_msgs__msg__HandState__get_type_hash,
  &wujihand_msgs__msg__HandState__get_type_description,
  &wujihand_msgs__msg__HandState__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace wujihand_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<wujihand_msgs::msg::HandState>()
{
  return &::wujihand_msgs::msg::rosidl_typesupport_introspection_cpp::HandState_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, wujihand_msgs, msg, HandState)() {
  return &::wujihand_msgs::msg::rosidl_typesupport_introspection_cpp::HandState_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
