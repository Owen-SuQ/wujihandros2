// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from wujihand_msgs:srv/GetHandInfo.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "wujihand_msgs/srv/detail/get_hand_info__functions.h"
#include "wujihand_msgs/srv/detail/get_hand_info__struct.hpp"
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

typedef struct _GetHandInfo_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GetHandInfo_Request_type_support_ids_t;

static const _GetHandInfo_Request_type_support_ids_t _GetHandInfo_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _GetHandInfo_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GetHandInfo_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GetHandInfo_Request_type_support_symbol_names_t _GetHandInfo_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, wujihand_msgs, srv, GetHandInfo_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, wujihand_msgs, srv, GetHandInfo_Request)),
  }
};

typedef struct _GetHandInfo_Request_type_support_data_t
{
  void * data[2];
} _GetHandInfo_Request_type_support_data_t;

static _GetHandInfo_Request_type_support_data_t _GetHandInfo_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GetHandInfo_Request_message_typesupport_map = {
  2,
  "wujihand_msgs",
  &_GetHandInfo_Request_message_typesupport_ids.typesupport_identifier[0],
  &_GetHandInfo_Request_message_typesupport_symbol_names.symbol_name[0],
  &_GetHandInfo_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GetHandInfo_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GetHandInfo_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &wujihand_msgs__srv__GetHandInfo_Request__get_type_hash,
  &wujihand_msgs__srv__GetHandInfo_Request__get_type_description,
  &wujihand_msgs__srv__GetHandInfo_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace wujihand_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<wujihand_msgs::srv::GetHandInfo_Request>()
{
  return &::wujihand_msgs::srv::rosidl_typesupport_cpp::GetHandInfo_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, wujihand_msgs, srv, GetHandInfo_Request)() {
  return get_message_type_support_handle<wujihand_msgs::srv::GetHandInfo_Request>();
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
// #include "wujihand_msgs/srv/detail/get_hand_info__functions.h"
// already included above
// #include "wujihand_msgs/srv/detail/get_hand_info__struct.hpp"
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

typedef struct _GetHandInfo_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GetHandInfo_Response_type_support_ids_t;

static const _GetHandInfo_Response_type_support_ids_t _GetHandInfo_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _GetHandInfo_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GetHandInfo_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GetHandInfo_Response_type_support_symbol_names_t _GetHandInfo_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, wujihand_msgs, srv, GetHandInfo_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, wujihand_msgs, srv, GetHandInfo_Response)),
  }
};

typedef struct _GetHandInfo_Response_type_support_data_t
{
  void * data[2];
} _GetHandInfo_Response_type_support_data_t;

static _GetHandInfo_Response_type_support_data_t _GetHandInfo_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GetHandInfo_Response_message_typesupport_map = {
  2,
  "wujihand_msgs",
  &_GetHandInfo_Response_message_typesupport_ids.typesupport_identifier[0],
  &_GetHandInfo_Response_message_typesupport_symbol_names.symbol_name[0],
  &_GetHandInfo_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GetHandInfo_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GetHandInfo_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &wujihand_msgs__srv__GetHandInfo_Response__get_type_hash,
  &wujihand_msgs__srv__GetHandInfo_Response__get_type_description,
  &wujihand_msgs__srv__GetHandInfo_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace wujihand_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<wujihand_msgs::srv::GetHandInfo_Response>()
{
  return &::wujihand_msgs::srv::rosidl_typesupport_cpp::GetHandInfo_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, wujihand_msgs, srv, GetHandInfo_Response)() {
  return get_message_type_support_handle<wujihand_msgs::srv::GetHandInfo_Response>();
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
// #include "wujihand_msgs/srv/detail/get_hand_info__functions.h"
// already included above
// #include "wujihand_msgs/srv/detail/get_hand_info__struct.hpp"
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

typedef struct _GetHandInfo_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GetHandInfo_Event_type_support_ids_t;

static const _GetHandInfo_Event_type_support_ids_t _GetHandInfo_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _GetHandInfo_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GetHandInfo_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GetHandInfo_Event_type_support_symbol_names_t _GetHandInfo_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, wujihand_msgs, srv, GetHandInfo_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, wujihand_msgs, srv, GetHandInfo_Event)),
  }
};

typedef struct _GetHandInfo_Event_type_support_data_t
{
  void * data[2];
} _GetHandInfo_Event_type_support_data_t;

static _GetHandInfo_Event_type_support_data_t _GetHandInfo_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GetHandInfo_Event_message_typesupport_map = {
  2,
  "wujihand_msgs",
  &_GetHandInfo_Event_message_typesupport_ids.typesupport_identifier[0],
  &_GetHandInfo_Event_message_typesupport_symbol_names.symbol_name[0],
  &_GetHandInfo_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GetHandInfo_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GetHandInfo_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &wujihand_msgs__srv__GetHandInfo_Event__get_type_hash,
  &wujihand_msgs__srv__GetHandInfo_Event__get_type_description,
  &wujihand_msgs__srv__GetHandInfo_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace wujihand_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<wujihand_msgs::srv::GetHandInfo_Event>()
{
  return &::wujihand_msgs::srv::rosidl_typesupport_cpp::GetHandInfo_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, wujihand_msgs, srv, GetHandInfo_Event)() {
  return get_message_type_support_handle<wujihand_msgs::srv::GetHandInfo_Event>();
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
// #include "wujihand_msgs/srv/detail/get_hand_info__struct.hpp"
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

typedef struct _GetHandInfo_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GetHandInfo_type_support_ids_t;

static const _GetHandInfo_type_support_ids_t _GetHandInfo_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _GetHandInfo_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GetHandInfo_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GetHandInfo_type_support_symbol_names_t _GetHandInfo_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, wujihand_msgs, srv, GetHandInfo)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, wujihand_msgs, srv, GetHandInfo)),
  }
};

typedef struct _GetHandInfo_type_support_data_t
{
  void * data[2];
} _GetHandInfo_type_support_data_t;

static _GetHandInfo_type_support_data_t _GetHandInfo_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GetHandInfo_service_typesupport_map = {
  2,
  "wujihand_msgs",
  &_GetHandInfo_service_typesupport_ids.typesupport_identifier[0],
  &_GetHandInfo_service_typesupport_symbol_names.symbol_name[0],
  &_GetHandInfo_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t GetHandInfo_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GetHandInfo_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<wujihand_msgs::srv::GetHandInfo_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<wujihand_msgs::srv::GetHandInfo_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<wujihand_msgs::srv::GetHandInfo_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<wujihand_msgs::srv::GetHandInfo>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<wujihand_msgs::srv::GetHandInfo>,
  &wujihand_msgs__srv__GetHandInfo__get_type_hash,
  &wujihand_msgs__srv__GetHandInfo__get_type_description,
  &wujihand_msgs__srv__GetHandInfo__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace wujihand_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<wujihand_msgs::srv::GetHandInfo>()
{
  return &::wujihand_msgs::srv::rosidl_typesupport_cpp::GetHandInfo_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, wujihand_msgs, srv, GetHandInfo)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<wujihand_msgs::srv::GetHandInfo>();
}

#ifdef __cplusplus
}
#endif
