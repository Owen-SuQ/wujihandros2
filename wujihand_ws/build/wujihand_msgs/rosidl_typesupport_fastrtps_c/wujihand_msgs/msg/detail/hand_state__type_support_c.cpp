// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from wujihand_msgs:msg/HandState.idl
// generated code does not contain a copyright notice
#include "wujihand_msgs/msg/detail/hand_state__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "wujihand_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "wujihand_msgs/msg/detail/hand_state__struct.h"
#include "wujihand_msgs/msg/detail/hand_state__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // handedness
#include "rosidl_runtime_c/string_functions.h"  // handedness
#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_wujihand_msgs
bool cdr_serialize_std_msgs__msg__Header(
  const std_msgs__msg__Header * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_wujihand_msgs
bool cdr_deserialize_std_msgs__msg__Header(
  eprosima::fastcdr::Cdr & cdr,
  std_msgs__msg__Header * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_wujihand_msgs
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_wujihand_msgs
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_wujihand_msgs
bool cdr_serialize_key_std_msgs__msg__Header(
  const std_msgs__msg__Header * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_wujihand_msgs
size_t get_serialized_size_key_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_wujihand_msgs
size_t max_serialized_size_key_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_wujihand_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();


using _HandState__ros_msg_type = wujihand_msgs__msg__HandState;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_wujihand_msgs
bool cdr_serialize_wujihand_msgs__msg__HandState(
  const wujihand_msgs__msg__HandState * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: header
  {
    cdr_serialize_std_msgs__msg__Header(
      &ros_message->header, cdr);
  }

  // Field name: handedness
  {
    const rosidl_runtime_c__String * str = &ros_message->handedness;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: system_temperature
  {
    cdr << ros_message->system_temperature;
  }

  // Field name: input_voltage
  {
    cdr << ros_message->input_voltage;
  }

  // Field name: actual_positions
  {
    size_t size = 20;
    auto array_ptr = ros_message->actual_positions;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: target_positions
  {
    size_t size = 20;
    auto array_ptr = ros_message->target_positions;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: joint_temperatures
  {
    size_t size = 20;
    auto array_ptr = ros_message->joint_temperatures;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: error_codes
  {
    size_t size = 20;
    auto array_ptr = ros_message->error_codes;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: enabled
  {
    size_t size = 20;
    auto array_ptr = ros_message->enabled;
    cdr.serialize_array(array_ptr, size);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_wujihand_msgs
bool cdr_deserialize_wujihand_msgs__msg__HandState(
  eprosima::fastcdr::Cdr & cdr,
  wujihand_msgs__msg__HandState * ros_message)
{
  // Field name: header
  {
    cdr_deserialize_std_msgs__msg__Header(cdr, &ros_message->header);
  }

  // Field name: handedness
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->handedness.data) {
      rosidl_runtime_c__String__init(&ros_message->handedness);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->handedness,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'handedness'\n");
      return false;
    }
  }

  // Field name: system_temperature
  {
    cdr >> ros_message->system_temperature;
  }

  // Field name: input_voltage
  {
    cdr >> ros_message->input_voltage;
  }

  // Field name: actual_positions
  {
    size_t size = 20;
    auto array_ptr = ros_message->actual_positions;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: target_positions
  {
    size_t size = 20;
    auto array_ptr = ros_message->target_positions;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: joint_temperatures
  {
    size_t size = 20;
    auto array_ptr = ros_message->joint_temperatures;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: error_codes
  {
    size_t size = 20;
    auto array_ptr = ros_message->error_codes;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: enabled
  {
    size_t size = 20;
    auto array_ptr = ros_message->enabled;
    for (size_t i = 0; i < size; ++i) {
      uint8_t tmp;
      cdr >> tmp;
      array_ptr[i] = tmp ? true : false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_wujihand_msgs
size_t get_serialized_size_wujihand_msgs__msg__HandState(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _HandState__ros_msg_type * ros_message = static_cast<const _HandState__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: header
  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);

  // Field name: handedness
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->handedness.size + 1);

  // Field name: system_temperature
  {
    size_t item_size = sizeof(ros_message->system_temperature);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: input_voltage
  {
    size_t item_size = sizeof(ros_message->input_voltage);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: actual_positions
  {
    size_t array_size = 20;
    auto array_ptr = ros_message->actual_positions;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: target_positions
  {
    size_t array_size = 20;
    auto array_ptr = ros_message->target_positions;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: joint_temperatures
  {
    size_t array_size = 20;
    auto array_ptr = ros_message->joint_temperatures;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: error_codes
  {
    size_t array_size = 20;
    auto array_ptr = ros_message->error_codes;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: enabled
  {
    size_t array_size = 20;
    auto array_ptr = ros_message->enabled;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_wujihand_msgs
size_t max_serialized_size_wujihand_msgs__msg__HandState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: header
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: handedness
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: system_temperature
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: input_voltage
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: actual_positions
  {
    size_t array_size = 20;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: target_positions
  {
    size_t array_size = 20;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: joint_temperatures
  {
    size_t array_size = 20;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: error_codes
  {
    size_t array_size = 20;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: enabled
  {
    size_t array_size = 20;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = wujihand_msgs__msg__HandState;
    is_plain =
      (
      offsetof(DataType, enabled) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_wujihand_msgs
bool cdr_serialize_key_wujihand_msgs__msg__HandState(
  const wujihand_msgs__msg__HandState * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: header
  {
    cdr_serialize_key_std_msgs__msg__Header(
      &ros_message->header, cdr);
  }

  // Field name: handedness
  {
    const rosidl_runtime_c__String * str = &ros_message->handedness;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: system_temperature
  {
    cdr << ros_message->system_temperature;
  }

  // Field name: input_voltage
  {
    cdr << ros_message->input_voltage;
  }

  // Field name: actual_positions
  {
    size_t size = 20;
    auto array_ptr = ros_message->actual_positions;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: target_positions
  {
    size_t size = 20;
    auto array_ptr = ros_message->target_positions;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: joint_temperatures
  {
    size_t size = 20;
    auto array_ptr = ros_message->joint_temperatures;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: error_codes
  {
    size_t size = 20;
    auto array_ptr = ros_message->error_codes;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: enabled
  {
    size_t size = 20;
    auto array_ptr = ros_message->enabled;
    cdr.serialize_array(array_ptr, size);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_wujihand_msgs
size_t get_serialized_size_key_wujihand_msgs__msg__HandState(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _HandState__ros_msg_type * ros_message = static_cast<const _HandState__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: header
  current_alignment += get_serialized_size_key_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);

  // Field name: handedness
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->handedness.size + 1);

  // Field name: system_temperature
  {
    size_t item_size = sizeof(ros_message->system_temperature);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: input_voltage
  {
    size_t item_size = sizeof(ros_message->input_voltage);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: actual_positions
  {
    size_t array_size = 20;
    auto array_ptr = ros_message->actual_positions;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: target_positions
  {
    size_t array_size = 20;
    auto array_ptr = ros_message->target_positions;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: joint_temperatures
  {
    size_t array_size = 20;
    auto array_ptr = ros_message->joint_temperatures;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: error_codes
  {
    size_t array_size = 20;
    auto array_ptr = ros_message->error_codes;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: enabled
  {
    size_t array_size = 20;
    auto array_ptr = ros_message->enabled;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_wujihand_msgs
size_t max_serialized_size_key_wujihand_msgs__msg__HandState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: header
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: handedness
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: system_temperature
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: input_voltage
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: actual_positions
  {
    size_t array_size = 20;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: target_positions
  {
    size_t array_size = 20;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: joint_temperatures
  {
    size_t array_size = 20;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: error_codes
  {
    size_t array_size = 20;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: enabled
  {
    size_t array_size = 20;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = wujihand_msgs__msg__HandState;
    is_plain =
      (
      offsetof(DataType, enabled) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _HandState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const wujihand_msgs__msg__HandState * ros_message = static_cast<const wujihand_msgs__msg__HandState *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_wujihand_msgs__msg__HandState(ros_message, cdr);
}

static bool _HandState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  wujihand_msgs__msg__HandState * ros_message = static_cast<wujihand_msgs__msg__HandState *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_wujihand_msgs__msg__HandState(cdr, ros_message);
}

static uint32_t _HandState__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_wujihand_msgs__msg__HandState(
      untyped_ros_message, 0));
}

static size_t _HandState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_wujihand_msgs__msg__HandState(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_HandState = {
  "wujihand_msgs::msg",
  "HandState",
  _HandState__cdr_serialize,
  _HandState__cdr_deserialize,
  _HandState__get_serialized_size,
  _HandState__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _HandState__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_HandState,
  get_message_typesupport_handle_function,
  &wujihand_msgs__msg__HandState__get_type_hash,
  &wujihand_msgs__msg__HandState__get_type_description,
  &wujihand_msgs__msg__HandState__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, wujihand_msgs, msg, HandState)() {
  return &_HandState__type_support;
}

#if defined(__cplusplus)
}
#endif
