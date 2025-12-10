// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from wujihand_msgs:msg/HandCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "wujihand_msgs/msg/hand_command.h"


#ifndef WUJIHAND_MSGS__MSG__DETAIL__HAND_COMMAND__STRUCT_H_
#define WUJIHAND_MSGS__MSG__DETAIL__HAND_COMMAND__STRUCT_H_

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

/// Struct defined in msg/HandCommand in the package wujihand_msgs.
typedef struct wujihand_msgs__msg__HandCommand
{
  std_msgs__msg__Header header;
  /// Target positions for all 20 joints
  /// Order: thumb(0-3), index(4-7), middle(8-11), ring(12-15), little(16-19)
  /// Each finger: mcp_abd, mcp_flex, pip, dip
  double target_positions[20];
} wujihand_msgs__msg__HandCommand;

// Struct for a sequence of wujihand_msgs__msg__HandCommand.
typedef struct wujihand_msgs__msg__HandCommand__Sequence
{
  wujihand_msgs__msg__HandCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} wujihand_msgs__msg__HandCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // WUJIHAND_MSGS__MSG__DETAIL__HAND_COMMAND__STRUCT_H_
