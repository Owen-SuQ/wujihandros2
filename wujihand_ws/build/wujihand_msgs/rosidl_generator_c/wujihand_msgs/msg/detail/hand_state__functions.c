// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from wujihand_msgs:msg/HandState.idl
// generated code does not contain a copyright notice
#include "wujihand_msgs/msg/detail/hand_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `handedness`
#include "rosidl_runtime_c/string_functions.h"

bool
wujihand_msgs__msg__HandState__init(wujihand_msgs__msg__HandState * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    wujihand_msgs__msg__HandState__fini(msg);
    return false;
  }
  // handedness
  if (!rosidl_runtime_c__String__init(&msg->handedness)) {
    wujihand_msgs__msg__HandState__fini(msg);
    return false;
  }
  // system_temperature
  // input_voltage
  // actual_positions
  // target_positions
  // joint_temperatures
  // error_codes
  // enabled
  return true;
}

void
wujihand_msgs__msg__HandState__fini(wujihand_msgs__msg__HandState * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // handedness
  rosidl_runtime_c__String__fini(&msg->handedness);
  // system_temperature
  // input_voltage
  // actual_positions
  // target_positions
  // joint_temperatures
  // error_codes
  // enabled
}

bool
wujihand_msgs__msg__HandState__are_equal(const wujihand_msgs__msg__HandState * lhs, const wujihand_msgs__msg__HandState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // handedness
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->handedness), &(rhs->handedness)))
  {
    return false;
  }
  // system_temperature
  if (lhs->system_temperature != rhs->system_temperature) {
    return false;
  }
  // input_voltage
  if (lhs->input_voltage != rhs->input_voltage) {
    return false;
  }
  // actual_positions
  for (size_t i = 0; i < 20; ++i) {
    if (lhs->actual_positions[i] != rhs->actual_positions[i]) {
      return false;
    }
  }
  // target_positions
  for (size_t i = 0; i < 20; ++i) {
    if (lhs->target_positions[i] != rhs->target_positions[i]) {
      return false;
    }
  }
  // joint_temperatures
  for (size_t i = 0; i < 20; ++i) {
    if (lhs->joint_temperatures[i] != rhs->joint_temperatures[i]) {
      return false;
    }
  }
  // error_codes
  for (size_t i = 0; i < 20; ++i) {
    if (lhs->error_codes[i] != rhs->error_codes[i]) {
      return false;
    }
  }
  // enabled
  for (size_t i = 0; i < 20; ++i) {
    if (lhs->enabled[i] != rhs->enabled[i]) {
      return false;
    }
  }
  return true;
}

bool
wujihand_msgs__msg__HandState__copy(
  const wujihand_msgs__msg__HandState * input,
  wujihand_msgs__msg__HandState * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // handedness
  if (!rosidl_runtime_c__String__copy(
      &(input->handedness), &(output->handedness)))
  {
    return false;
  }
  // system_temperature
  output->system_temperature = input->system_temperature;
  // input_voltage
  output->input_voltage = input->input_voltage;
  // actual_positions
  for (size_t i = 0; i < 20; ++i) {
    output->actual_positions[i] = input->actual_positions[i];
  }
  // target_positions
  for (size_t i = 0; i < 20; ++i) {
    output->target_positions[i] = input->target_positions[i];
  }
  // joint_temperatures
  for (size_t i = 0; i < 20; ++i) {
    output->joint_temperatures[i] = input->joint_temperatures[i];
  }
  // error_codes
  for (size_t i = 0; i < 20; ++i) {
    output->error_codes[i] = input->error_codes[i];
  }
  // enabled
  for (size_t i = 0; i < 20; ++i) {
    output->enabled[i] = input->enabled[i];
  }
  return true;
}

wujihand_msgs__msg__HandState *
wujihand_msgs__msg__HandState__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  wujihand_msgs__msg__HandState * msg = (wujihand_msgs__msg__HandState *)allocator.allocate(sizeof(wujihand_msgs__msg__HandState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(wujihand_msgs__msg__HandState));
  bool success = wujihand_msgs__msg__HandState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
wujihand_msgs__msg__HandState__destroy(wujihand_msgs__msg__HandState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    wujihand_msgs__msg__HandState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
wujihand_msgs__msg__HandState__Sequence__init(wujihand_msgs__msg__HandState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  wujihand_msgs__msg__HandState * data = NULL;

  if (size) {
    data = (wujihand_msgs__msg__HandState *)allocator.zero_allocate(size, sizeof(wujihand_msgs__msg__HandState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = wujihand_msgs__msg__HandState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        wujihand_msgs__msg__HandState__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
wujihand_msgs__msg__HandState__Sequence__fini(wujihand_msgs__msg__HandState__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      wujihand_msgs__msg__HandState__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

wujihand_msgs__msg__HandState__Sequence *
wujihand_msgs__msg__HandState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  wujihand_msgs__msg__HandState__Sequence * array = (wujihand_msgs__msg__HandState__Sequence *)allocator.allocate(sizeof(wujihand_msgs__msg__HandState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = wujihand_msgs__msg__HandState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
wujihand_msgs__msg__HandState__Sequence__destroy(wujihand_msgs__msg__HandState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    wujihand_msgs__msg__HandState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
wujihand_msgs__msg__HandState__Sequence__are_equal(const wujihand_msgs__msg__HandState__Sequence * lhs, const wujihand_msgs__msg__HandState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!wujihand_msgs__msg__HandState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
wujihand_msgs__msg__HandState__Sequence__copy(
  const wujihand_msgs__msg__HandState__Sequence * input,
  wujihand_msgs__msg__HandState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(wujihand_msgs__msg__HandState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    wujihand_msgs__msg__HandState * data =
      (wujihand_msgs__msg__HandState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!wujihand_msgs__msg__HandState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          wujihand_msgs__msg__HandState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!wujihand_msgs__msg__HandState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
