// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from wujihand_msgs:srv/GetDiagnostics.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "wujihand_msgs/srv/detail/get_diagnostics__rosidl_typesupport_introspection_c.h"
#include "wujihand_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "wujihand_msgs/srv/detail/get_diagnostics__functions.h"
#include "wujihand_msgs/srv/detail/get_diagnostics__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void wujihand_msgs__srv__GetDiagnostics_Request__rosidl_typesupport_introspection_c__GetDiagnostics_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  wujihand_msgs__srv__GetDiagnostics_Request__init(message_memory);
}

void wujihand_msgs__srv__GetDiagnostics_Request__rosidl_typesupport_introspection_c__GetDiagnostics_Request_fini_function(void * message_memory)
{
  wujihand_msgs__srv__GetDiagnostics_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember wujihand_msgs__srv__GetDiagnostics_Request__rosidl_typesupport_introspection_c__GetDiagnostics_Request_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wujihand_msgs__srv__GetDiagnostics_Request, structure_needs_at_least_one_member),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers wujihand_msgs__srv__GetDiagnostics_Request__rosidl_typesupport_introspection_c__GetDiagnostics_Request_message_members = {
  "wujihand_msgs__srv",  // message namespace
  "GetDiagnostics_Request",  // message name
  1,  // number of fields
  sizeof(wujihand_msgs__srv__GetDiagnostics_Request),
  false,  // has_any_key_member_
  wujihand_msgs__srv__GetDiagnostics_Request__rosidl_typesupport_introspection_c__GetDiagnostics_Request_message_member_array,  // message members
  wujihand_msgs__srv__GetDiagnostics_Request__rosidl_typesupport_introspection_c__GetDiagnostics_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  wujihand_msgs__srv__GetDiagnostics_Request__rosidl_typesupport_introspection_c__GetDiagnostics_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t wujihand_msgs__srv__GetDiagnostics_Request__rosidl_typesupport_introspection_c__GetDiagnostics_Request_message_type_support_handle = {
  0,
  &wujihand_msgs__srv__GetDiagnostics_Request__rosidl_typesupport_introspection_c__GetDiagnostics_Request_message_members,
  get_message_typesupport_handle_function,
  &wujihand_msgs__srv__GetDiagnostics_Request__get_type_hash,
  &wujihand_msgs__srv__GetDiagnostics_Request__get_type_description,
  &wujihand_msgs__srv__GetDiagnostics_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_wujihand_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, wujihand_msgs, srv, GetDiagnostics_Request)() {
  if (!wujihand_msgs__srv__GetDiagnostics_Request__rosidl_typesupport_introspection_c__GetDiagnostics_Request_message_type_support_handle.typesupport_identifier) {
    wujihand_msgs__srv__GetDiagnostics_Request__rosidl_typesupport_introspection_c__GetDiagnostics_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &wujihand_msgs__srv__GetDiagnostics_Request__rosidl_typesupport_introspection_c__GetDiagnostics_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "wujihand_msgs/srv/detail/get_diagnostics__rosidl_typesupport_introspection_c.h"
// already included above
// #include "wujihand_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "wujihand_msgs/srv/detail/get_diagnostics__functions.h"
// already included above
// #include "wujihand_msgs/srv/detail/get_diagnostics__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void wujihand_msgs__srv__GetDiagnostics_Response__rosidl_typesupport_introspection_c__GetDiagnostics_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  wujihand_msgs__srv__GetDiagnostics_Response__init(message_memory);
}

void wujihand_msgs__srv__GetDiagnostics_Response__rosidl_typesupport_introspection_c__GetDiagnostics_Response_fini_function(void * message_memory)
{
  wujihand_msgs__srv__GetDiagnostics_Response__fini(message_memory);
}

size_t wujihand_msgs__srv__GetDiagnostics_Response__rosidl_typesupport_introspection_c__size_function__GetDiagnostics_Response__joint_temperatures(
  const void * untyped_member)
{
  (void)untyped_member;
  return 20;
}

const void * wujihand_msgs__srv__GetDiagnostics_Response__rosidl_typesupport_introspection_c__get_const_function__GetDiagnostics_Response__joint_temperatures(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * wujihand_msgs__srv__GetDiagnostics_Response__rosidl_typesupport_introspection_c__get_function__GetDiagnostics_Response__joint_temperatures(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void wujihand_msgs__srv__GetDiagnostics_Response__rosidl_typesupport_introspection_c__fetch_function__GetDiagnostics_Response__joint_temperatures(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    wujihand_msgs__srv__GetDiagnostics_Response__rosidl_typesupport_introspection_c__get_const_function__GetDiagnostics_Response__joint_temperatures(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void wujihand_msgs__srv__GetDiagnostics_Response__rosidl_typesupport_introspection_c__assign_function__GetDiagnostics_Response__joint_temperatures(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    wujihand_msgs__srv__GetDiagnostics_Response__rosidl_typesupport_introspection_c__get_function__GetDiagnostics_Response__joint_temperatures(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

size_t wujihand_msgs__srv__GetDiagnostics_Response__rosidl_typesupport_introspection_c__size_function__GetDiagnostics_Response__error_codes(
  const void * untyped_member)
{
  (void)untyped_member;
  return 20;
}

const void * wujihand_msgs__srv__GetDiagnostics_Response__rosidl_typesupport_introspection_c__get_const_function__GetDiagnostics_Response__error_codes(
  const void * untyped_member, size_t index)
{
  const uint32_t * member =
    (const uint32_t *)(untyped_member);
  return &member[index];
}

void * wujihand_msgs__srv__GetDiagnostics_Response__rosidl_typesupport_introspection_c__get_function__GetDiagnostics_Response__error_codes(
  void * untyped_member, size_t index)
{
  uint32_t * member =
    (uint32_t *)(untyped_member);
  return &member[index];
}

void wujihand_msgs__srv__GetDiagnostics_Response__rosidl_typesupport_introspection_c__fetch_function__GetDiagnostics_Response__error_codes(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint32_t * item =
    ((const uint32_t *)
    wujihand_msgs__srv__GetDiagnostics_Response__rosidl_typesupport_introspection_c__get_const_function__GetDiagnostics_Response__error_codes(untyped_member, index));
  uint32_t * value =
    (uint32_t *)(untyped_value);
  *value = *item;
}

void wujihand_msgs__srv__GetDiagnostics_Response__rosidl_typesupport_introspection_c__assign_function__GetDiagnostics_Response__error_codes(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint32_t * item =
    ((uint32_t *)
    wujihand_msgs__srv__GetDiagnostics_Response__rosidl_typesupport_introspection_c__get_function__GetDiagnostics_Response__error_codes(untyped_member, index));
  const uint32_t * value =
    (const uint32_t *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember wujihand_msgs__srv__GetDiagnostics_Response__rosidl_typesupport_introspection_c__GetDiagnostics_Response_message_member_array[4] = {
  {
    "system_temperature",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wujihand_msgs__srv__GetDiagnostics_Response, system_temperature),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "input_voltage",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wujihand_msgs__srv__GetDiagnostics_Response, input_voltage),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "joint_temperatures",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    20,  // array size
    false,  // is upper bound
    offsetof(wujihand_msgs__srv__GetDiagnostics_Response, joint_temperatures),  // bytes offset in struct
    NULL,  // default value
    wujihand_msgs__srv__GetDiagnostics_Response__rosidl_typesupport_introspection_c__size_function__GetDiagnostics_Response__joint_temperatures,  // size() function pointer
    wujihand_msgs__srv__GetDiagnostics_Response__rosidl_typesupport_introspection_c__get_const_function__GetDiagnostics_Response__joint_temperatures,  // get_const(index) function pointer
    wujihand_msgs__srv__GetDiagnostics_Response__rosidl_typesupport_introspection_c__get_function__GetDiagnostics_Response__joint_temperatures,  // get(index) function pointer
    wujihand_msgs__srv__GetDiagnostics_Response__rosidl_typesupport_introspection_c__fetch_function__GetDiagnostics_Response__joint_temperatures,  // fetch(index, &value) function pointer
    wujihand_msgs__srv__GetDiagnostics_Response__rosidl_typesupport_introspection_c__assign_function__GetDiagnostics_Response__joint_temperatures,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "error_codes",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    20,  // array size
    false,  // is upper bound
    offsetof(wujihand_msgs__srv__GetDiagnostics_Response, error_codes),  // bytes offset in struct
    NULL,  // default value
    wujihand_msgs__srv__GetDiagnostics_Response__rosidl_typesupport_introspection_c__size_function__GetDiagnostics_Response__error_codes,  // size() function pointer
    wujihand_msgs__srv__GetDiagnostics_Response__rosidl_typesupport_introspection_c__get_const_function__GetDiagnostics_Response__error_codes,  // get_const(index) function pointer
    wujihand_msgs__srv__GetDiagnostics_Response__rosidl_typesupport_introspection_c__get_function__GetDiagnostics_Response__error_codes,  // get(index) function pointer
    wujihand_msgs__srv__GetDiagnostics_Response__rosidl_typesupport_introspection_c__fetch_function__GetDiagnostics_Response__error_codes,  // fetch(index, &value) function pointer
    wujihand_msgs__srv__GetDiagnostics_Response__rosidl_typesupport_introspection_c__assign_function__GetDiagnostics_Response__error_codes,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers wujihand_msgs__srv__GetDiagnostics_Response__rosidl_typesupport_introspection_c__GetDiagnostics_Response_message_members = {
  "wujihand_msgs__srv",  // message namespace
  "GetDiagnostics_Response",  // message name
  4,  // number of fields
  sizeof(wujihand_msgs__srv__GetDiagnostics_Response),
  false,  // has_any_key_member_
  wujihand_msgs__srv__GetDiagnostics_Response__rosidl_typesupport_introspection_c__GetDiagnostics_Response_message_member_array,  // message members
  wujihand_msgs__srv__GetDiagnostics_Response__rosidl_typesupport_introspection_c__GetDiagnostics_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  wujihand_msgs__srv__GetDiagnostics_Response__rosidl_typesupport_introspection_c__GetDiagnostics_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t wujihand_msgs__srv__GetDiagnostics_Response__rosidl_typesupport_introspection_c__GetDiagnostics_Response_message_type_support_handle = {
  0,
  &wujihand_msgs__srv__GetDiagnostics_Response__rosidl_typesupport_introspection_c__GetDiagnostics_Response_message_members,
  get_message_typesupport_handle_function,
  &wujihand_msgs__srv__GetDiagnostics_Response__get_type_hash,
  &wujihand_msgs__srv__GetDiagnostics_Response__get_type_description,
  &wujihand_msgs__srv__GetDiagnostics_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_wujihand_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, wujihand_msgs, srv, GetDiagnostics_Response)() {
  if (!wujihand_msgs__srv__GetDiagnostics_Response__rosidl_typesupport_introspection_c__GetDiagnostics_Response_message_type_support_handle.typesupport_identifier) {
    wujihand_msgs__srv__GetDiagnostics_Response__rosidl_typesupport_introspection_c__GetDiagnostics_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &wujihand_msgs__srv__GetDiagnostics_Response__rosidl_typesupport_introspection_c__GetDiagnostics_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "wujihand_msgs/srv/detail/get_diagnostics__rosidl_typesupport_introspection_c.h"
// already included above
// #include "wujihand_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "wujihand_msgs/srv/detail/get_diagnostics__functions.h"
// already included above
// #include "wujihand_msgs/srv/detail/get_diagnostics__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "wujihand_msgs/srv/get_diagnostics.h"
// Member `request`
// Member `response`
// already included above
// #include "wujihand_msgs/srv/detail/get_diagnostics__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__GetDiagnostics_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  wujihand_msgs__srv__GetDiagnostics_Event__init(message_memory);
}

void wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__GetDiagnostics_Event_fini_function(void * message_memory)
{
  wujihand_msgs__srv__GetDiagnostics_Event__fini(message_memory);
}

size_t wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__size_function__GetDiagnostics_Event__request(
  const void * untyped_member)
{
  const wujihand_msgs__srv__GetDiagnostics_Request__Sequence * member =
    (const wujihand_msgs__srv__GetDiagnostics_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__get_const_function__GetDiagnostics_Event__request(
  const void * untyped_member, size_t index)
{
  const wujihand_msgs__srv__GetDiagnostics_Request__Sequence * member =
    (const wujihand_msgs__srv__GetDiagnostics_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__get_function__GetDiagnostics_Event__request(
  void * untyped_member, size_t index)
{
  wujihand_msgs__srv__GetDiagnostics_Request__Sequence * member =
    (wujihand_msgs__srv__GetDiagnostics_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__fetch_function__GetDiagnostics_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const wujihand_msgs__srv__GetDiagnostics_Request * item =
    ((const wujihand_msgs__srv__GetDiagnostics_Request *)
    wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__get_const_function__GetDiagnostics_Event__request(untyped_member, index));
  wujihand_msgs__srv__GetDiagnostics_Request * value =
    (wujihand_msgs__srv__GetDiagnostics_Request *)(untyped_value);
  *value = *item;
}

void wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__assign_function__GetDiagnostics_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  wujihand_msgs__srv__GetDiagnostics_Request * item =
    ((wujihand_msgs__srv__GetDiagnostics_Request *)
    wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__get_function__GetDiagnostics_Event__request(untyped_member, index));
  const wujihand_msgs__srv__GetDiagnostics_Request * value =
    (const wujihand_msgs__srv__GetDiagnostics_Request *)(untyped_value);
  *item = *value;
}

bool wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__resize_function__GetDiagnostics_Event__request(
  void * untyped_member, size_t size)
{
  wujihand_msgs__srv__GetDiagnostics_Request__Sequence * member =
    (wujihand_msgs__srv__GetDiagnostics_Request__Sequence *)(untyped_member);
  wujihand_msgs__srv__GetDiagnostics_Request__Sequence__fini(member);
  return wujihand_msgs__srv__GetDiagnostics_Request__Sequence__init(member, size);
}

size_t wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__size_function__GetDiagnostics_Event__response(
  const void * untyped_member)
{
  const wujihand_msgs__srv__GetDiagnostics_Response__Sequence * member =
    (const wujihand_msgs__srv__GetDiagnostics_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__get_const_function__GetDiagnostics_Event__response(
  const void * untyped_member, size_t index)
{
  const wujihand_msgs__srv__GetDiagnostics_Response__Sequence * member =
    (const wujihand_msgs__srv__GetDiagnostics_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__get_function__GetDiagnostics_Event__response(
  void * untyped_member, size_t index)
{
  wujihand_msgs__srv__GetDiagnostics_Response__Sequence * member =
    (wujihand_msgs__srv__GetDiagnostics_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__fetch_function__GetDiagnostics_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const wujihand_msgs__srv__GetDiagnostics_Response * item =
    ((const wujihand_msgs__srv__GetDiagnostics_Response *)
    wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__get_const_function__GetDiagnostics_Event__response(untyped_member, index));
  wujihand_msgs__srv__GetDiagnostics_Response * value =
    (wujihand_msgs__srv__GetDiagnostics_Response *)(untyped_value);
  *value = *item;
}

void wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__assign_function__GetDiagnostics_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  wujihand_msgs__srv__GetDiagnostics_Response * item =
    ((wujihand_msgs__srv__GetDiagnostics_Response *)
    wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__get_function__GetDiagnostics_Event__response(untyped_member, index));
  const wujihand_msgs__srv__GetDiagnostics_Response * value =
    (const wujihand_msgs__srv__GetDiagnostics_Response *)(untyped_value);
  *item = *value;
}

bool wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__resize_function__GetDiagnostics_Event__response(
  void * untyped_member, size_t size)
{
  wujihand_msgs__srv__GetDiagnostics_Response__Sequence * member =
    (wujihand_msgs__srv__GetDiagnostics_Response__Sequence *)(untyped_member);
  wujihand_msgs__srv__GetDiagnostics_Response__Sequence__fini(member);
  return wujihand_msgs__srv__GetDiagnostics_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__GetDiagnostics_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wujihand_msgs__srv__GetDiagnostics_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(wujihand_msgs__srv__GetDiagnostics_Event, request),  // bytes offset in struct
    NULL,  // default value
    wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__size_function__GetDiagnostics_Event__request,  // size() function pointer
    wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__get_const_function__GetDiagnostics_Event__request,  // get_const(index) function pointer
    wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__get_function__GetDiagnostics_Event__request,  // get(index) function pointer
    wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__fetch_function__GetDiagnostics_Event__request,  // fetch(index, &value) function pointer
    wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__assign_function__GetDiagnostics_Event__request,  // assign(index, value) function pointer
    wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__resize_function__GetDiagnostics_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(wujihand_msgs__srv__GetDiagnostics_Event, response),  // bytes offset in struct
    NULL,  // default value
    wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__size_function__GetDiagnostics_Event__response,  // size() function pointer
    wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__get_const_function__GetDiagnostics_Event__response,  // get_const(index) function pointer
    wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__get_function__GetDiagnostics_Event__response,  // get(index) function pointer
    wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__fetch_function__GetDiagnostics_Event__response,  // fetch(index, &value) function pointer
    wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__assign_function__GetDiagnostics_Event__response,  // assign(index, value) function pointer
    wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__resize_function__GetDiagnostics_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__GetDiagnostics_Event_message_members = {
  "wujihand_msgs__srv",  // message namespace
  "GetDiagnostics_Event",  // message name
  3,  // number of fields
  sizeof(wujihand_msgs__srv__GetDiagnostics_Event),
  false,  // has_any_key_member_
  wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__GetDiagnostics_Event_message_member_array,  // message members
  wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__GetDiagnostics_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__GetDiagnostics_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__GetDiagnostics_Event_message_type_support_handle = {
  0,
  &wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__GetDiagnostics_Event_message_members,
  get_message_typesupport_handle_function,
  &wujihand_msgs__srv__GetDiagnostics_Event__get_type_hash,
  &wujihand_msgs__srv__GetDiagnostics_Event__get_type_description,
  &wujihand_msgs__srv__GetDiagnostics_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_wujihand_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, wujihand_msgs, srv, GetDiagnostics_Event)() {
  wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__GetDiagnostics_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__GetDiagnostics_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, wujihand_msgs, srv, GetDiagnostics_Request)();
  wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__GetDiagnostics_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, wujihand_msgs, srv, GetDiagnostics_Response)();
  if (!wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__GetDiagnostics_Event_message_type_support_handle.typesupport_identifier) {
    wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__GetDiagnostics_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__GetDiagnostics_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "wujihand_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "wujihand_msgs/srv/detail/get_diagnostics__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers wujihand_msgs__srv__detail__get_diagnostics__rosidl_typesupport_introspection_c__GetDiagnostics_service_members = {
  "wujihand_msgs__srv",  // service namespace
  "GetDiagnostics",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // wujihand_msgs__srv__detail__get_diagnostics__rosidl_typesupport_introspection_c__GetDiagnostics_Request_message_type_support_handle,
  NULL,  // response message
  // wujihand_msgs__srv__detail__get_diagnostics__rosidl_typesupport_introspection_c__GetDiagnostics_Response_message_type_support_handle
  NULL  // event_message
  // wujihand_msgs__srv__detail__get_diagnostics__rosidl_typesupport_introspection_c__GetDiagnostics_Response_message_type_support_handle
};


static rosidl_service_type_support_t wujihand_msgs__srv__detail__get_diagnostics__rosidl_typesupport_introspection_c__GetDiagnostics_service_type_support_handle = {
  0,
  &wujihand_msgs__srv__detail__get_diagnostics__rosidl_typesupport_introspection_c__GetDiagnostics_service_members,
  get_service_typesupport_handle_function,
  &wujihand_msgs__srv__GetDiagnostics_Request__rosidl_typesupport_introspection_c__GetDiagnostics_Request_message_type_support_handle,
  &wujihand_msgs__srv__GetDiagnostics_Response__rosidl_typesupport_introspection_c__GetDiagnostics_Response_message_type_support_handle,
  &wujihand_msgs__srv__GetDiagnostics_Event__rosidl_typesupport_introspection_c__GetDiagnostics_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    wujihand_msgs,
    srv,
    GetDiagnostics
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    wujihand_msgs,
    srv,
    GetDiagnostics
  ),
  &wujihand_msgs__srv__GetDiagnostics__get_type_hash,
  &wujihand_msgs__srv__GetDiagnostics__get_type_description,
  &wujihand_msgs__srv__GetDiagnostics__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, wujihand_msgs, srv, GetDiagnostics_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, wujihand_msgs, srv, GetDiagnostics_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, wujihand_msgs, srv, GetDiagnostics_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_wujihand_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, wujihand_msgs, srv, GetDiagnostics)(void) {
  if (!wujihand_msgs__srv__detail__get_diagnostics__rosidl_typesupport_introspection_c__GetDiagnostics_service_type_support_handle.typesupport_identifier) {
    wujihand_msgs__srv__detail__get_diagnostics__rosidl_typesupport_introspection_c__GetDiagnostics_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)wujihand_msgs__srv__detail__get_diagnostics__rosidl_typesupport_introspection_c__GetDiagnostics_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, wujihand_msgs, srv, GetDiagnostics_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, wujihand_msgs, srv, GetDiagnostics_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, wujihand_msgs, srv, GetDiagnostics_Event)()->data;
  }

  return &wujihand_msgs__srv__detail__get_diagnostics__rosidl_typesupport_introspection_c__GetDiagnostics_service_type_support_handle;
}
