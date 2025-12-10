// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from wujihand_msgs:srv/SetEnabled.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "wujihand_msgs/srv/detail/set_enabled__functions.h"
#include "wujihand_msgs/srv/detail/set_enabled__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace wujihand_msgs
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _SetEnabled_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetEnabled_Request_type_support_ids_t;

static const _SetEnabled_Request_type_support_ids_t _SetEnabled_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SetEnabled_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetEnabled_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetEnabled_Request_type_support_symbol_names_t _SetEnabled_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, wujihand_msgs, srv, SetEnabled_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, wujihand_msgs, srv, SetEnabled_Request)),
  }
};

typedef struct _SetEnabled_Request_type_support_data_t
{
  void * data[2];
} _SetEnabled_Request_type_support_data_t;

static _SetEnabled_Request_type_support_data_t _SetEnabled_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetEnabled_Request_message_typesupport_map = {
  2,
  "wujihand_msgs",
  &_SetEnabled_Request_message_typesupport_ids.typesupport_identifier[0],
  &_SetEnabled_Request_message_typesupport_symbol_names.symbol_name[0],
  &_SetEnabled_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetEnabled_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetEnabled_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &wujihand_msgs__srv__SetEnabled_Request__get_type_hash,
  &wujihand_msgs__srv__SetEnabled_Request__get_type_description,
  &wujihand_msgs__srv__SetEnabled_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace wujihand_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<wujihand_msgs::srv::SetEnabled_Request>()
{
  return &::wujihand_msgs::srv::rosidl_typesupport_cpp::SetEnabled_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, wujihand_msgs, srv, SetEnabled_Request)() {
  return get_message_type_support_handle<wujihand_msgs::srv::SetEnabled_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "wujihand_msgs/srv/detail/set_enabled__functions.h"
// already included above
// #include "wujihand_msgs/srv/detail/set_enabled__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace wujihand_msgs
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _SetEnabled_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetEnabled_Response_type_support_ids_t;

static const _SetEnabled_Response_type_support_ids_t _SetEnabled_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SetEnabled_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetEnabled_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetEnabled_Response_type_support_symbol_names_t _SetEnabled_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, wujihand_msgs, srv, SetEnabled_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, wujihand_msgs, srv, SetEnabled_Response)),
  }
};

typedef struct _SetEnabled_Response_type_support_data_t
{
  void * data[2];
} _SetEnabled_Response_type_support_data_t;

static _SetEnabled_Response_type_support_data_t _SetEnabled_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetEnabled_Response_message_typesupport_map = {
  2,
  "wujihand_msgs",
  &_SetEnabled_Response_message_typesupport_ids.typesupport_identifier[0],
  &_SetEnabled_Response_message_typesupport_symbol_names.symbol_name[0],
  &_SetEnabled_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetEnabled_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetEnabled_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &wujihand_msgs__srv__SetEnabled_Response__get_type_hash,
  &wujihand_msgs__srv__SetEnabled_Response__get_type_description,
  &wujihand_msgs__srv__SetEnabled_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace wujihand_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<wujihand_msgs::srv::SetEnabled_Response>()
{
  return &::wujihand_msgs::srv::rosidl_typesupport_cpp::SetEnabled_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, wujihand_msgs, srv, SetEnabled_Response)() {
  return get_message_type_support_handle<wujihand_msgs::srv::SetEnabled_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "wujihand_msgs/srv/detail/set_enabled__functions.h"
// already included above
// #include "wujihand_msgs/srv/detail/set_enabled__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace wujihand_msgs
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _SetEnabled_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetEnabled_Event_type_support_ids_t;

static const _SetEnabled_Event_type_support_ids_t _SetEnabled_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SetEnabled_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetEnabled_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetEnabled_Event_type_support_symbol_names_t _SetEnabled_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, wujihand_msgs, srv, SetEnabled_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, wujihand_msgs, srv, SetEnabled_Event)),
  }
};

typedef struct _SetEnabled_Event_type_support_data_t
{
  void * data[2];
} _SetEnabled_Event_type_support_data_t;

static _SetEnabled_Event_type_support_data_t _SetEnabled_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetEnabled_Event_message_typesupport_map = {
  2,
  "wujihand_msgs",
  &_SetEnabled_Event_message_typesupport_ids.typesupport_identifier[0],
  &_SetEnabled_Event_message_typesupport_symbol_names.symbol_name[0],
  &_SetEnabled_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetEnabled_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetEnabled_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &wujihand_msgs__srv__SetEnabled_Event__get_type_hash,
  &wujihand_msgs__srv__SetEnabled_Event__get_type_description,
  &wujihand_msgs__srv__SetEnabled_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace wujihand_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<wujihand_msgs::srv::SetEnabled_Event>()
{
  return &::wujihand_msgs::srv::rosidl_typesupport_cpp::SetEnabled_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, wujihand_msgs, srv, SetEnabled_Event)() {
  return get_message_type_support_handle<wujihand_msgs::srv::SetEnabled_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "wujihand_msgs/srv/detail/set_enabled__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace wujihand_msgs
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _SetEnabled_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetEnabled_type_support_ids_t;

static const _SetEnabled_type_support_ids_t _SetEnabled_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SetEnabled_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetEnabled_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetEnabled_type_support_symbol_names_t _SetEnabled_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, wujihand_msgs, srv, SetEnabled)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, wujihand_msgs, srv, SetEnabled)),
  }
};

typedef struct _SetEnabled_type_support_data_t
{
  void * data[2];
} _SetEnabled_type_support_data_t;

static _SetEnabled_type_support_data_t _SetEnabled_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetEnabled_service_typesupport_map = {
  2,
  "wujihand_msgs",
  &_SetEnabled_service_typesupport_ids.typesupport_identifier[0],
  &_SetEnabled_service_typesupport_symbol_names.symbol_name[0],
  &_SetEnabled_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t SetEnabled_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetEnabled_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<wujihand_msgs::srv::SetEnabled_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<wujihand_msgs::srv::SetEnabled_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<wujihand_msgs::srv::SetEnabled_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<wujihand_msgs::srv::SetEnabled>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<wujihand_msgs::srv::SetEnabled>,
  &wujihand_msgs__srv__SetEnabled__get_type_hash,
  &wujihand_msgs__srv__SetEnabled__get_type_description,
  &wujihand_msgs__srv__SetEnabled__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace wujihand_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<wujihand_msgs::srv::SetEnabled>()
{
  return &::wujihand_msgs::srv::rosidl_typesupport_cpp::SetEnabled_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, wujihand_msgs, srv, SetEnabled)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<wujihand_msgs::srv::SetEnabled>();
}

#ifdef __cplusplus
}
#endif
