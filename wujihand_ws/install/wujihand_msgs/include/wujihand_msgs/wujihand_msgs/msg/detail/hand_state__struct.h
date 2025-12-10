// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from wujihand_msgs:msg/HandState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "wujihand_msgs/msg/hand_state.h"


#ifndef WUJIHAND_MSGS__MSG__DETAIL__HAND_STATE__STRUCT_H_
#define WUJIHAND_MSGS__MSG__DETAIL__HAND_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'handedness'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/HandState in the package wujihand_msgs.
typedef struct wujihand_msgs__msg__HandState
{
  std_msgs__msg__Header header;
  /// Hand identification
  /// "left" or "right"
  rosidl_runtime_c__String handedness;
  /// System status
  float system_temperature;
  float input_voltage;
  /// Joint states (20 joints: 5 fingers x 4 joints)
  /// Order: thumb(0-3), index(4-7), middle(8-11), ring(12-15), little(16-19)
  /// Each finger: mcp_abd, mcp_flex, pip, dip
  double actual_positions[20];
  double target_positions[20];
  float joint_temperatures[20];
  uint32_t error_codes[20];
  bool enabled[20];
} wujihand_msgs__msg__HandState;

// Struct for a sequence of wujihand_msgs__msg__HandState.
typedef struct wujihand_msgs__msg__HandState__Sequence
{
  wujihand_msgs__msg__HandState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} wujihand_msgs__msg__HandState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // WUJIHAND_MSGS__MSG__DETAIL__HAND_STATE__STRUCT_H_
