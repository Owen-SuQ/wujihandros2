// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from wujihand_msgs:srv/SetEnabled.idl
// generated code does not contain a copyright notice
#include "wujihand_msgs/srv/detail/set_enabled__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
wujihand_msgs__srv__SetEnabled_Request__init(wujihand_msgs__srv__SetEnabled_Request * msg)
{
  if (!msg) {
    return false;
  }
  // finger_id
  // joint_id
  // enabled
  return true;
}

void
wujihand_msgs__srv__SetEnabled_Request__fini(wujihand_msgs__srv__SetEnabled_Request * msg)
{
  if (!msg) {
    return;
  }
  // finger_id
  // joint_id
  // enabled
}

bool
wujihand_msgs__srv__SetEnabled_Request__are_equal(const wujihand_msgs__srv__SetEnabled_Request * lhs, const wujihand_msgs__srv__SetEnabled_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // finger_id
  if (lhs->finger_id != rhs->finger_id) {
    return false;
  }
  // joint_id
  if (lhs->joint_id != rhs->joint_id) {
    return false;
  }
  // enabled
  if (lhs->enabled != rhs->enabled) {
    return false;
  }
  return true;
}

bool
wujihand_msgs__srv__SetEnabled_Request__copy(
  const wujihand_msgs__srv__SetEnabled_Request * input,
  wujihand_msgs__srv__SetEnabled_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // finger_id
  output->finger_id = input->finger_id;
  // joint_id
  output->joint_id = input->joint_id;
  // enabled
  output->enabled = input->enabled;
  return true;
}

wujihand_msgs__srv__SetEnabled_Request *
wujihand_msgs__srv__SetEnabled_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  wujihand_msgs__srv__SetEnabled_Request * msg = (wujihand_msgs__srv__SetEnabled_Request *)allocator.allocate(sizeof(wujihand_msgs__srv__SetEnabled_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(wujihand_msgs__srv__SetEnabled_Request));
  bool success = wujihand_msgs__srv__SetEnabled_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
wujihand_msgs__srv__SetEnabled_Request__destroy(wujihand_msgs__srv__SetEnabled_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    wujihand_msgs__srv__SetEnabled_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
wujihand_msgs__srv__SetEnabled_Request__Sequence__init(wujihand_msgs__srv__SetEnabled_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  wujihand_msgs__srv__SetEnabled_Request * data = NULL;

  if (size) {
    data = (wujihand_msgs__srv__SetEnabled_Request *)allocator.zero_allocate(size, sizeof(wujihand_msgs__srv__SetEnabled_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = wujihand_msgs__srv__SetEnabled_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        wujihand_msgs__srv__SetEnabled_Request__fini(&data[i - 1]);
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
wujihand_msgs__srv__SetEnabled_Request__Sequence__fini(wujihand_msgs__srv__SetEnabled_Request__Sequence * array)
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
      wujihand_msgs__srv__SetEnabled_Request__fini(&array->data[i]);
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

wujihand_msgs__srv__SetEnabled_Request__Sequence *
wujihand_msgs__srv__SetEnabled_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  wujihand_msgs__srv__SetEnabled_Request__Sequence * array = (wujihand_msgs__srv__SetEnabled_Request__Sequence *)allocator.allocate(sizeof(wujihand_msgs__srv__SetEnabled_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = wujihand_msgs__srv__SetEnabled_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
wujihand_msgs__srv__SetEnabled_Request__Sequence__destroy(wujihand_msgs__srv__SetEnabled_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    wujihand_msgs__srv__SetEnabled_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
wujihand_msgs__srv__SetEnabled_Request__Sequence__are_equal(const wujihand_msgs__srv__SetEnabled_Request__Sequence * lhs, const wujihand_msgs__srv__SetEnabled_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!wujihand_msgs__srv__SetEnabled_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
wujihand_msgs__srv__SetEnabled_Request__Sequence__copy(
  const wujihand_msgs__srv__SetEnabled_Request__Sequence * input,
  wujihand_msgs__srv__SetEnabled_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(wujihand_msgs__srv__SetEnabled_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    wujihand_msgs__srv__SetEnabled_Request * data =
      (wujihand_msgs__srv__SetEnabled_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!wujihand_msgs__srv__SetEnabled_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          wujihand_msgs__srv__SetEnabled_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!wujihand_msgs__srv__SetEnabled_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
wujihand_msgs__srv__SetEnabled_Response__init(wujihand_msgs__srv__SetEnabled_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    wujihand_msgs__srv__SetEnabled_Response__fini(msg);
    return false;
  }
  return true;
}

void
wujihand_msgs__srv__SetEnabled_Response__fini(wujihand_msgs__srv__SetEnabled_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
wujihand_msgs__srv__SetEnabled_Response__are_equal(const wujihand_msgs__srv__SetEnabled_Response * lhs, const wujihand_msgs__srv__SetEnabled_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
wujihand_msgs__srv__SetEnabled_Response__copy(
  const wujihand_msgs__srv__SetEnabled_Response * input,
  wujihand_msgs__srv__SetEnabled_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

wujihand_msgs__srv__SetEnabled_Response *
wujihand_msgs__srv__SetEnabled_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  wujihand_msgs__srv__SetEnabled_Response * msg = (wujihand_msgs__srv__SetEnabled_Response *)allocator.allocate(sizeof(wujihand_msgs__srv__SetEnabled_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(wujihand_msgs__srv__SetEnabled_Response));
  bool success = wujihand_msgs__srv__SetEnabled_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
wujihand_msgs__srv__SetEnabled_Response__destroy(wujihand_msgs__srv__SetEnabled_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    wujihand_msgs__srv__SetEnabled_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
wujihand_msgs__srv__SetEnabled_Response__Sequence__init(wujihand_msgs__srv__SetEnabled_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  wujihand_msgs__srv__SetEnabled_Response * data = NULL;

  if (size) {
    data = (wujihand_msgs__srv__SetEnabled_Response *)allocator.zero_allocate(size, sizeof(wujihand_msgs__srv__SetEnabled_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = wujihand_msgs__srv__SetEnabled_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        wujihand_msgs__srv__SetEnabled_Response__fini(&data[i - 1]);
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
wujihand_msgs__srv__SetEnabled_Response__Sequence__fini(wujihand_msgs__srv__SetEnabled_Response__Sequence * array)
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
      wujihand_msgs__srv__SetEnabled_Response__fini(&array->data[i]);
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

wujihand_msgs__srv__SetEnabled_Response__Sequence *
wujihand_msgs__srv__SetEnabled_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  wujihand_msgs__srv__SetEnabled_Response__Sequence * array = (wujihand_msgs__srv__SetEnabled_Response__Sequence *)allocator.allocate(sizeof(wujihand_msgs__srv__SetEnabled_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = wujihand_msgs__srv__SetEnabled_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
wujihand_msgs__srv__SetEnabled_Response__Sequence__destroy(wujihand_msgs__srv__SetEnabled_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    wujihand_msgs__srv__SetEnabled_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
wujihand_msgs__srv__SetEnabled_Response__Sequence__are_equal(const wujihand_msgs__srv__SetEnabled_Response__Sequence * lhs, const wujihand_msgs__srv__SetEnabled_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!wujihand_msgs__srv__SetEnabled_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
wujihand_msgs__srv__SetEnabled_Response__Sequence__copy(
  const wujihand_msgs__srv__SetEnabled_Response__Sequence * input,
  wujihand_msgs__srv__SetEnabled_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(wujihand_msgs__srv__SetEnabled_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    wujihand_msgs__srv__SetEnabled_Response * data =
      (wujihand_msgs__srv__SetEnabled_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!wujihand_msgs__srv__SetEnabled_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          wujihand_msgs__srv__SetEnabled_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!wujihand_msgs__srv__SetEnabled_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "wujihand_msgs/srv/detail/set_enabled__functions.h"

bool
wujihand_msgs__srv__SetEnabled_Event__init(wujihand_msgs__srv__SetEnabled_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    wujihand_msgs__srv__SetEnabled_Event__fini(msg);
    return false;
  }
  // request
  if (!wujihand_msgs__srv__SetEnabled_Request__Sequence__init(&msg->request, 0)) {
    wujihand_msgs__srv__SetEnabled_Event__fini(msg);
    return false;
  }
  // response
  if (!wujihand_msgs__srv__SetEnabled_Response__Sequence__init(&msg->response, 0)) {
    wujihand_msgs__srv__SetEnabled_Event__fini(msg);
    return false;
  }
  return true;
}

void
wujihand_msgs__srv__SetEnabled_Event__fini(wujihand_msgs__srv__SetEnabled_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  wujihand_msgs__srv__SetEnabled_Request__Sequence__fini(&msg->request);
  // response
  wujihand_msgs__srv__SetEnabled_Response__Sequence__fini(&msg->response);
}

bool
wujihand_msgs__srv__SetEnabled_Event__are_equal(const wujihand_msgs__srv__SetEnabled_Event * lhs, const wujihand_msgs__srv__SetEnabled_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!wujihand_msgs__srv__SetEnabled_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!wujihand_msgs__srv__SetEnabled_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
wujihand_msgs__srv__SetEnabled_Event__copy(
  const wujihand_msgs__srv__SetEnabled_Event * input,
  wujihand_msgs__srv__SetEnabled_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!wujihand_msgs__srv__SetEnabled_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!wujihand_msgs__srv__SetEnabled_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

wujihand_msgs__srv__SetEnabled_Event *
wujihand_msgs__srv__SetEnabled_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  wujihand_msgs__srv__SetEnabled_Event * msg = (wujihand_msgs__srv__SetEnabled_Event *)allocator.allocate(sizeof(wujihand_msgs__srv__SetEnabled_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(wujihand_msgs__srv__SetEnabled_Event));
  bool success = wujihand_msgs__srv__SetEnabled_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
wujihand_msgs__srv__SetEnabled_Event__destroy(wujihand_msgs__srv__SetEnabled_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    wujihand_msgs__srv__SetEnabled_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
wujihand_msgs__srv__SetEnabled_Event__Sequence__init(wujihand_msgs__srv__SetEnabled_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  wujihand_msgs__srv__SetEnabled_Event * data = NULL;

  if (size) {
    data = (wujihand_msgs__srv__SetEnabled_Event *)allocator.zero_allocate(size, sizeof(wujihand_msgs__srv__SetEnabled_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = wujihand_msgs__srv__SetEnabled_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        wujihand_msgs__srv__SetEnabled_Event__fini(&data[i - 1]);
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
wujihand_msgs__srv__SetEnabled_Event__Sequence__fini(wujihand_msgs__srv__SetEnabled_Event__Sequence * array)
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
      wujihand_msgs__srv__SetEnabled_Event__fini(&array->data[i]);
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

wujihand_msgs__srv__SetEnabled_Event__Sequence *
wujihand_msgs__srv__SetEnabled_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  wujihand_msgs__srv__SetEnabled_Event__Sequence * array = (wujihand_msgs__srv__SetEnabled_Event__Sequence *)allocator.allocate(sizeof(wujihand_msgs__srv__SetEnabled_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = wujihand_msgs__srv__SetEnabled_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
wujihand_msgs__srv__SetEnabled_Event__Sequence__destroy(wujihand_msgs__srv__SetEnabled_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    wujihand_msgs__srv__SetEnabled_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
wujihand_msgs__srv__SetEnabled_Event__Sequence__are_equal(const wujihand_msgs__srv__SetEnabled_Event__Sequence * lhs, const wujihand_msgs__srv__SetEnabled_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!wujihand_msgs__srv__SetEnabled_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
wujihand_msgs__srv__SetEnabled_Event__Sequence__copy(
  const wujihand_msgs__srv__SetEnabled_Event__Sequence * input,
  wujihand_msgs__srv__SetEnabled_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(wujihand_msgs__srv__SetEnabled_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    wujihand_msgs__srv__SetEnabled_Event * data =
      (wujihand_msgs__srv__SetEnabled_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!wujihand_msgs__srv__SetEnabled_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          wujihand_msgs__srv__SetEnabled_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!wujihand_msgs__srv__SetEnabled_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
