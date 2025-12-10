// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from wujihand_msgs:msg/HandCommand.idl
// generated code does not contain a copyright notice
#include "wujihand_msgs/msg/detail/hand_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
wujihand_msgs__msg__HandCommand__init(wujihand_msgs__msg__HandCommand * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    wujihand_msgs__msg__HandCommand__fini(msg);
    return false;
  }
  // target_positions
  return true;
}

void
wujihand_msgs__msg__HandCommand__fini(wujihand_msgs__msg__HandCommand * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // target_positions
}

bool
wujihand_msgs__msg__HandCommand__are_equal(const wujihand_msgs__msg__HandCommand * lhs, const wujihand_msgs__msg__HandCommand * rhs)
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
  // target_positions
  for (size_t i = 0; i < 20; ++i) {
    if (lhs->target_positions[i] != rhs->target_positions[i]) {
      return false;
    }
  }
  return true;
}

bool
wujihand_msgs__msg__HandCommand__copy(
  const wujihand_msgs__msg__HandCommand * input,
  wujihand_msgs__msg__HandCommand * output)
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
  // target_positions
  for (size_t i = 0; i < 20; ++i) {
    output->target_positions[i] = input->target_positions[i];
  }
  return true;
}

wujihand_msgs__msg__HandCommand *
wujihand_msgs__msg__HandCommand__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  wujihand_msgs__msg__HandCommand * msg = (wujihand_msgs__msg__HandCommand *)allocator.allocate(sizeof(wujihand_msgs__msg__HandCommand), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(wujihand_msgs__msg__HandCommand));
  bool success = wujihand_msgs__msg__HandCommand__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
wujihand_msgs__msg__HandCommand__destroy(wujihand_msgs__msg__HandCommand * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    wujihand_msgs__msg__HandCommand__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
wujihand_msgs__msg__HandCommand__Sequence__init(wujihand_msgs__msg__HandCommand__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  wujihand_msgs__msg__HandCommand * data = NULL;

  if (size) {
    data = (wujihand_msgs__msg__HandCommand *)allocator.zero_allocate(size, sizeof(wujihand_msgs__msg__HandCommand), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = wujihand_msgs__msg__HandCommand__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        wujihand_msgs__msg__HandCommand__fini(&data[i - 1]);
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
wujihand_msgs__msg__HandCommand__Sequence__fini(wujihand_msgs__msg__HandCommand__Sequence * array)
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
      wujihand_msgs__msg__HandCommand__fini(&array->data[i]);
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

wujihand_msgs__msg__HandCommand__Sequence *
wujihand_msgs__msg__HandCommand__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  wujihand_msgs__msg__HandCommand__Sequence * array = (wujihand_msgs__msg__HandCommand__Sequence *)allocator.allocate(sizeof(wujihand_msgs__msg__HandCommand__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = wujihand_msgs__msg__HandCommand__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
wujihand_msgs__msg__HandCommand__Sequence__destroy(wujihand_msgs__msg__HandCommand__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    wujihand_msgs__msg__HandCommand__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
wujihand_msgs__msg__HandCommand__Sequence__are_equal(const wujihand_msgs__msg__HandCommand__Sequence * lhs, const wujihand_msgs__msg__HandCommand__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!wujihand_msgs__msg__HandCommand__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
wujihand_msgs__msg__HandCommand__Sequence__copy(
  const wujihand_msgs__msg__HandCommand__Sequence * input,
  wujihand_msgs__msg__HandCommand__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(wujihand_msgs__msg__HandCommand);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    wujihand_msgs__msg__HandCommand * data =
      (wujihand_msgs__msg__HandCommand *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!wujihand_msgs__msg__HandCommand__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          wujihand_msgs__msg__HandCommand__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!wujihand_msgs__msg__HandCommand__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
