// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from wujihand_msgs:srv/GetHandInfo.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "wujihand_msgs/srv/get_hand_info.hpp"


#ifndef WUJIHAND_MSGS__SRV__DETAIL__GET_HAND_INFO__STRUCT_HPP_
#define WUJIHAND_MSGS__SRV__DETAIL__GET_HAND_INFO__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__wujihand_msgs__srv__GetHandInfo_Request __attribute__((deprecated))
#else
# define DEPRECATED__wujihand_msgs__srv__GetHandInfo_Request __declspec(deprecated)
#endif

namespace wujihand_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetHandInfo_Request_
{
  using Type = GetHandInfo_Request_<ContainerAllocator>;

  explicit GetHandInfo_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit GetHandInfo_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    wujihand_msgs::srv::GetHandInfo_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const wujihand_msgs::srv::GetHandInfo_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<wujihand_msgs::srv::GetHandInfo_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<wujihand_msgs::srv::GetHandInfo_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      wujihand_msgs::srv::GetHandInfo_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<wujihand_msgs::srv::GetHandInfo_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      wujihand_msgs::srv::GetHandInfo_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<wujihand_msgs::srv::GetHandInfo_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<wujihand_msgs::srv::GetHandInfo_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<wujihand_msgs::srv::GetHandInfo_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__wujihand_msgs__srv__GetHandInfo_Request
    std::shared_ptr<wujihand_msgs::srv::GetHandInfo_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__wujihand_msgs__srv__GetHandInfo_Request
    std::shared_ptr<wujihand_msgs::srv::GetHandInfo_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetHandInfo_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetHandInfo_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetHandInfo_Request_

// alias to use template instance with default allocator
using GetHandInfo_Request =
  wujihand_msgs::srv::GetHandInfo_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace wujihand_msgs


#ifndef _WIN32
# define DEPRECATED__wujihand_msgs__srv__GetHandInfo_Response __attribute__((deprecated))
#else
# define DEPRECATED__wujihand_msgs__srv__GetHandInfo_Response __declspec(deprecated)
#endif

namespace wujihand_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetHandInfo_Response_
{
  using Type = GetHandInfo_Response_<ContainerAllocator>;

  explicit GetHandInfo_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->handedness = "";
      this->firmware_version = "";
      std::fill<typename std::array<double, 20>::iterator, double>(this->upper_limits.begin(), this->upper_limits.end(), 0.0);
      std::fill<typename std::array<double, 20>::iterator, double>(this->lower_limits.begin(), this->lower_limits.end(), 0.0);
    }
  }

  explicit GetHandInfo_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : handedness(_alloc),
    firmware_version(_alloc),
    upper_limits(_alloc),
    lower_limits(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->handedness = "";
      this->firmware_version = "";
      std::fill<typename std::array<double, 20>::iterator, double>(this->upper_limits.begin(), this->upper_limits.end(), 0.0);
      std::fill<typename std::array<double, 20>::iterator, double>(this->lower_limits.begin(), this->lower_limits.end(), 0.0);
    }
  }

  // field types and members
  using _handedness_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _handedness_type handedness;
  using _firmware_version_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _firmware_version_type firmware_version;
  using _upper_limits_type =
    std::array<double, 20>;
  _upper_limits_type upper_limits;
  using _lower_limits_type =
    std::array<double, 20>;
  _lower_limits_type lower_limits;

  // setters for named parameter idiom
  Type & set__handedness(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->handedness = _arg;
    return *this;
  }
  Type & set__firmware_version(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->firmware_version = _arg;
    return *this;
  }
  Type & set__upper_limits(
    const std::array<double, 20> & _arg)
  {
    this->upper_limits = _arg;
    return *this;
  }
  Type & set__lower_limits(
    const std::array<double, 20> & _arg)
  {
    this->lower_limits = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    wujihand_msgs::srv::GetHandInfo_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const wujihand_msgs::srv::GetHandInfo_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<wujihand_msgs::srv::GetHandInfo_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<wujihand_msgs::srv::GetHandInfo_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      wujihand_msgs::srv::GetHandInfo_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<wujihand_msgs::srv::GetHandInfo_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      wujihand_msgs::srv::GetHandInfo_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<wujihand_msgs::srv::GetHandInfo_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<wujihand_msgs::srv::GetHandInfo_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<wujihand_msgs::srv::GetHandInfo_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__wujihand_msgs__srv__GetHandInfo_Response
    std::shared_ptr<wujihand_msgs::srv::GetHandInfo_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__wujihand_msgs__srv__GetHandInfo_Response
    std::shared_ptr<wujihand_msgs::srv::GetHandInfo_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetHandInfo_Response_ & other) const
  {
    if (this->handedness != other.handedness) {
      return false;
    }
    if (this->firmware_version != other.firmware_version) {
      return false;
    }
    if (this->upper_limits != other.upper_limits) {
      return false;
    }
    if (this->lower_limits != other.lower_limits) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetHandInfo_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetHandInfo_Response_

// alias to use template instance with default allocator
using GetHandInfo_Response =
  wujihand_msgs::srv::GetHandInfo_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace wujihand_msgs


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__wujihand_msgs__srv__GetHandInfo_Event __attribute__((deprecated))
#else
# define DEPRECATED__wujihand_msgs__srv__GetHandInfo_Event __declspec(deprecated)
#endif

namespace wujihand_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetHandInfo_Event_
{
  using Type = GetHandInfo_Event_<ContainerAllocator>;

  explicit GetHandInfo_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit GetHandInfo_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<wujihand_msgs::srv::GetHandInfo_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<wujihand_msgs::srv::GetHandInfo_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<wujihand_msgs::srv::GetHandInfo_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<wujihand_msgs::srv::GetHandInfo_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<wujihand_msgs::srv::GetHandInfo_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<wujihand_msgs::srv::GetHandInfo_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<wujihand_msgs::srv::GetHandInfo_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<wujihand_msgs::srv::GetHandInfo_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    wujihand_msgs::srv::GetHandInfo_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const wujihand_msgs::srv::GetHandInfo_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<wujihand_msgs::srv::GetHandInfo_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<wujihand_msgs::srv::GetHandInfo_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      wujihand_msgs::srv::GetHandInfo_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<wujihand_msgs::srv::GetHandInfo_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      wujihand_msgs::srv::GetHandInfo_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<wujihand_msgs::srv::GetHandInfo_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<wujihand_msgs::srv::GetHandInfo_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<wujihand_msgs::srv::GetHandInfo_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__wujihand_msgs__srv__GetHandInfo_Event
    std::shared_ptr<wujihand_msgs::srv::GetHandInfo_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__wujihand_msgs__srv__GetHandInfo_Event
    std::shared_ptr<wujihand_msgs::srv::GetHandInfo_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetHandInfo_Event_ & other) const
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
  bool operator!=(const GetHandInfo_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetHandInfo_Event_

// alias to use template instance with default allocator
using GetHandInfo_Event =
  wujihand_msgs::srv::GetHandInfo_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace wujihand_msgs

namespace wujihand_msgs
{

namespace srv
{

struct GetHandInfo
{
  using Request = wujihand_msgs::srv::GetHandInfo_Request;
  using Response = wujihand_msgs::srv::GetHandInfo_Response;
  using Event = wujihand_msgs::srv::GetHandInfo_Event;
};

}  // namespace srv

}  // namespace wujihand_msgs

#endif  // WUJIHAND_MSGS__SRV__DETAIL__GET_HAND_INFO__STRUCT_HPP_
