// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from wujihand_msgs:srv/GetDiagnostics.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "wujihand_msgs/srv/get_diagnostics.hpp"


#ifndef WUJIHAND_MSGS__SRV__DETAIL__GET_DIAGNOSTICS__STRUCT_HPP_
#define WUJIHAND_MSGS__SRV__DETAIL__GET_DIAGNOSTICS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__wujihand_msgs__srv__GetDiagnostics_Request __attribute__((deprecated))
#else
# define DEPRECATED__wujihand_msgs__srv__GetDiagnostics_Request __declspec(deprecated)
#endif

namespace wujihand_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetDiagnostics_Request_
{
  using Type = GetDiagnostics_Request_<ContainerAllocator>;

  explicit GetDiagnostics_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit GetDiagnostics_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    wujihand_msgs::srv::GetDiagnostics_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const wujihand_msgs::srv::GetDiagnostics_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<wujihand_msgs::srv::GetDiagnostics_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<wujihand_msgs::srv::GetDiagnostics_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      wujihand_msgs::srv::GetDiagnostics_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<wujihand_msgs::srv::GetDiagnostics_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      wujihand_msgs::srv::GetDiagnostics_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<wujihand_msgs::srv::GetDiagnostics_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<wujihand_msgs::srv::GetDiagnostics_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<wujihand_msgs::srv::GetDiagnostics_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__wujihand_msgs__srv__GetDiagnostics_Request
    std::shared_ptr<wujihand_msgs::srv::GetDiagnostics_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__wujihand_msgs__srv__GetDiagnostics_Request
    std::shared_ptr<wujihand_msgs::srv::GetDiagnostics_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetDiagnostics_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetDiagnostics_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetDiagnostics_Request_

// alias to use template instance with default allocator
using GetDiagnostics_Request =
  wujihand_msgs::srv::GetDiagnostics_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace wujihand_msgs


#ifndef _WIN32
# define DEPRECATED__wujihand_msgs__srv__GetDiagnostics_Response __attribute__((deprecated))
#else
# define DEPRECATED__wujihand_msgs__srv__GetDiagnostics_Response __declspec(deprecated)
#endif

namespace wujihand_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetDiagnostics_Response_
{
  using Type = GetDiagnostics_Response_<ContainerAllocator>;

  explicit GetDiagnostics_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->system_temperature = 0.0;
      this->input_voltage = 0.0;
      std::fill<typename std::array<double, 20>::iterator, double>(this->joint_temperatures.begin(), this->joint_temperatures.end(), 0.0);
      std::fill<typename std::array<uint32_t, 20>::iterator, uint32_t>(this->error_codes.begin(), this->error_codes.end(), 0ul);
    }
  }

  explicit GetDiagnostics_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : joint_temperatures(_alloc),
    error_codes(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->system_temperature = 0.0;
      this->input_voltage = 0.0;
      std::fill<typename std::array<double, 20>::iterator, double>(this->joint_temperatures.begin(), this->joint_temperatures.end(), 0.0);
      std::fill<typename std::array<uint32_t, 20>::iterator, uint32_t>(this->error_codes.begin(), this->error_codes.end(), 0ul);
    }
  }

  // field types and members
  using _system_temperature_type =
    double;
  _system_temperature_type system_temperature;
  using _input_voltage_type =
    double;
  _input_voltage_type input_voltage;
  using _joint_temperatures_type =
    std::array<double, 20>;
  _joint_temperatures_type joint_temperatures;
  using _error_codes_type =
    std::array<uint32_t, 20>;
  _error_codes_type error_codes;

  // setters for named parameter idiom
  Type & set__system_temperature(
    const double & _arg)
  {
    this->system_temperature = _arg;
    return *this;
  }
  Type & set__input_voltage(
    const double & _arg)
  {
    this->input_voltage = _arg;
    return *this;
  }
  Type & set__joint_temperatures(
    const std::array<double, 20> & _arg)
  {
    this->joint_temperatures = _arg;
    return *this;
  }
  Type & set__error_codes(
    const std::array<uint32_t, 20> & _arg)
  {
    this->error_codes = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    wujihand_msgs::srv::GetDiagnostics_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const wujihand_msgs::srv::GetDiagnostics_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<wujihand_msgs::srv::GetDiagnostics_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<wujihand_msgs::srv::GetDiagnostics_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      wujihand_msgs::srv::GetDiagnostics_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<wujihand_msgs::srv::GetDiagnostics_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      wujihand_msgs::srv::GetDiagnostics_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<wujihand_msgs::srv::GetDiagnostics_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<wujihand_msgs::srv::GetDiagnostics_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<wujihand_msgs::srv::GetDiagnostics_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__wujihand_msgs__srv__GetDiagnostics_Response
    std::shared_ptr<wujihand_msgs::srv::GetDiagnostics_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__wujihand_msgs__srv__GetDiagnostics_Response
    std::shared_ptr<wujihand_msgs::srv::GetDiagnostics_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetDiagnostics_Response_ & other) const
  {
    if (this->system_temperature != other.system_temperature) {
      return false;
    }
    if (this->input_voltage != other.input_voltage) {
      return false;
    }
    if (this->joint_temperatures != other.joint_temperatures) {
      return false;
    }
    if (this->error_codes != other.error_codes) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetDiagnostics_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetDiagnostics_Response_

// alias to use template instance with default allocator
using GetDiagnostics_Response =
  wujihand_msgs::srv::GetDiagnostics_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace wujihand_msgs


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__wujihand_msgs__srv__GetDiagnostics_Event __attribute__((deprecated))
#else
# define DEPRECATED__wujihand_msgs__srv__GetDiagnostics_Event __declspec(deprecated)
#endif

namespace wujihand_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetDiagnostics_Event_
{
  using Type = GetDiagnostics_Event_<ContainerAllocator>;

  explicit GetDiagnostics_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit GetDiagnostics_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<wujihand_msgs::srv::GetDiagnostics_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<wujihand_msgs::srv::GetDiagnostics_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<wujihand_msgs::srv::GetDiagnostics_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<wujihand_msgs::srv::GetDiagnostics_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<wujihand_msgs::srv::GetDiagnostics_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<wujihand_msgs::srv::GetDiagnostics_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<wujihand_msgs::srv::GetDiagnostics_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<wujihand_msgs::srv::GetDiagnostics_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    wujihand_msgs::srv::GetDiagnostics_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const wujihand_msgs::srv::GetDiagnostics_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<wujihand_msgs::srv::GetDiagnostics_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<wujihand_msgs::srv::GetDiagnostics_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      wujihand_msgs::srv::GetDiagnostics_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<wujihand_msgs::srv::GetDiagnostics_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      wujihand_msgs::srv::GetDiagnostics_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<wujihand_msgs::srv::GetDiagnostics_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<wujihand_msgs::srv::GetDiagnostics_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<wujihand_msgs::srv::GetDiagnostics_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__wujihand_msgs__srv__GetDiagnostics_Event
    std::shared_ptr<wujihand_msgs::srv::GetDiagnostics_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__wujihand_msgs__srv__GetDiagnostics_Event
    std::shared_ptr<wujihand_msgs::srv::GetDiagnostics_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetDiagnostics_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetDiagnostics_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetDiagnostics_Event_

// alias to use template instance with default allocator
using GetDiagnostics_Event =
  wujihand_msgs::srv::GetDiagnostics_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace wujihand_msgs

namespace wujihand_msgs
{

namespace srv
{

struct GetDiagnostics
{
  using Request = wujihand_msgs::srv::GetDiagnostics_Request;
  using Response = wujihand_msgs::srv::GetDiagnostics_Response;
  using Event = wujihand_msgs::srv::GetDiagnostics_Event;
};

}  // namespace srv

}  // namespace wujihand_msgs

#endif  // WUJIHAND_MSGS__SRV__DETAIL__GET_DIAGNOSTICS__STRUCT_HPP_
