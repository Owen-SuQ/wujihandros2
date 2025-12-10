// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from wujihand_msgs:srv/ResetError.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "wujihand_msgs/srv/reset_error.h"


#ifndef WUJIHAND_MSGS__SRV__DETAIL__RESET_ERROR__STRUCT_H_
#define WUJIHAND_MSGS__SRV__DETAIL__RESET_ERROR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/ResetError in the package wujihand_msgs.
typedef struct wujihand_msgs__srv__ResetError_Request
{
  /// 0-4 (thumb, index, middle, ring, little), 255 for all fingers
  uint8_t finger_id;
  /// 0-3 (mcp_abd, mcp_flex, pip, dip), 255 for all joints
  uint8_t joint_id;
} wujihand_msgs__srv__ResetError_Request;

// Struct for a sequence of wujihand_msgs__srv__ResetError_Request.
typedef struct wujihand_msgs__srv__ResetError_Request__Sequence
{
  wujihand_msgs__srv__ResetError_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} wujihand_msgs__srv__ResetError_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ResetError in the package wujihand_msgs.
typedef struct wujihand_msgs__srv__ResetError_Response
{
  bool success;
  rosidl_runtime_c__String message;
} wujihand_msgs__srv__ResetError_Response;

// Struct for a sequence of wujihand_msgs__srv__ResetError_Response.
typedef struct wujihand_msgs__srv__ResetError_Response__Sequence
{
  wujihand_msgs__srv__ResetError_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} wujihand_msgs__srv__ResetError_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  wujihand_msgs__srv__ResetError_Event__request__MAX_SIZE = 1
};
// response
enum
{
  wujihand_msgs__srv__ResetError_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/ResetError in the package wujihand_msgs.
typedef struct wujihand_msgs__srv__ResetError_Event
{
  service_msgs__msg__ServiceEventInfo info;
  wujihand_msgs__srv__ResetError_Request__Sequence request;
  wujihand_msgs__srv__ResetError_Response__Sequence response;
} wujihand_msgs__srv__ResetError_Event;

// Struct for a sequence of wujihand_msgs__srv__ResetError_Event.
typedef struct wujihand_msgs__srv__ResetError_Event__Sequence
{
  wujihand_msgs__srv__ResetError_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} wujihand_msgs__srv__ResetError_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // WUJIHAND_MSGS__SRV__DETAIL__RESET_ERROR__STRUCT_H_
