// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from wujihand_msgs:srv/GetDiagnostics.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "wujihand_msgs/srv/get_diagnostics.h"


#ifndef WUJIHAND_MSGS__SRV__DETAIL__GET_DIAGNOSTICS__STRUCT_H_
#define WUJIHAND_MSGS__SRV__DETAIL__GET_DIAGNOSTICS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GetDiagnostics in the package wujihand_msgs.
typedef struct wujihand_msgs__srv__GetDiagnostics_Request
{
  uint8_t structure_needs_at_least_one_member;
} wujihand_msgs__srv__GetDiagnostics_Request;

// Struct for a sequence of wujihand_msgs__srv__GetDiagnostics_Request.
typedef struct wujihand_msgs__srv__GetDiagnostics_Request__Sequence
{
  wujihand_msgs__srv__GetDiagnostics_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} wujihand_msgs__srv__GetDiagnostics_Request__Sequence;

// Constants defined in the message

/// Struct defined in srv/GetDiagnostics in the package wujihand_msgs.
typedef struct wujihand_msgs__srv__GetDiagnostics_Response
{
  /// System temperature (Celsius)
  double system_temperature;
  /// Input voltage (V)
  double input_voltage;
  /// Joint temperatures (Celsius)
  double joint_temperatures[20];
  /// Joint error codes (0 = no error)
  uint32_t error_codes[20];
} wujihand_msgs__srv__GetDiagnostics_Response;

// Struct for a sequence of wujihand_msgs__srv__GetDiagnostics_Response.
typedef struct wujihand_msgs__srv__GetDiagnostics_Response__Sequence
{
  wujihand_msgs__srv__GetDiagnostics_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} wujihand_msgs__srv__GetDiagnostics_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  wujihand_msgs__srv__GetDiagnostics_Event__request__MAX_SIZE = 1
};
// response
enum
{
  wujihand_msgs__srv__GetDiagnostics_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/GetDiagnostics in the package wujihand_msgs.
typedef struct wujihand_msgs__srv__GetDiagnostics_Event
{
  service_msgs__msg__ServiceEventInfo info;
  wujihand_msgs__srv__GetDiagnostics_Request__Sequence request;
  wujihand_msgs__srv__GetDiagnostics_Response__Sequence response;
} wujihand_msgs__srv__GetDiagnostics_Event;

// Struct for a sequence of wujihand_msgs__srv__GetDiagnostics_Event.
typedef struct wujihand_msgs__srv__GetDiagnostics_Event__Sequence
{
  wujihand_msgs__srv__GetDiagnostics_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} wujihand_msgs__srv__GetDiagnostics_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // WUJIHAND_MSGS__SRV__DETAIL__GET_DIAGNOSTICS__STRUCT_H_
