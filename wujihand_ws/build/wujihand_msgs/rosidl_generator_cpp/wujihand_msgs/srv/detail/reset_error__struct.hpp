// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from wujihand_msgs:srv/ResetError.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "wujihand_msgs/srv/reset_error.hpp"


#ifndef WUJIHAND_MSGS__SRV__DETAIL__RESET_ERROR__STRUCT_HPP_
#define WUJIHAND_MSGS__SRV__DETAIL__RESET_ERROR__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__wujihand_msgs__srv__ResetError_Request __attribute__((deprecated))
#else
# define DEPRECATED__wujihand_msgs__srv__ResetError_Request __declspec(deprecated)
#endif

namespace wujihand_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ResetError_Request_
{
  using Type = ResetError_Request_<ContainerAllocator>;

  explicit ResetError_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->finger_id = 0;
      this->joint_id = 0;
    }
  }

  explicit ResetError_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->finger_id = 0;
      this->joint_id = 0;
    }
  }

  // field types and members
  using _finger_id_type =
    uint8_t;
  _finger_id_type finger_id;
  using _joint_id_type =
    uint8_t;
  _joint_id_type joint_id;

  // setters for named parameter idiom
  Type & set__finger_id(
    const uint8_t & _arg)
  {
    this->finger_id = _arg;
    return *this;
  }
  Type & set__joint_id(
    const uint8_t & _arg)
  {
    this->joint_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    wujihand_msgs::srv::ResetError_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const wujihand_msgs::srv::ResetError_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<wujihand_msgs::srv::ResetError_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<wujihand_msgs::srv::ResetError_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      wujihand_msgs::srv::ResetError_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<wujihand_msgs::srv::ResetError_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      wujihand_msgs::srv::ResetError_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<wujihand_msgs::srv::ResetError_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<wujihand_msgs::srv::ResetError_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<wujihand_msgs::srv::ResetError_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__wujihand_msgs__srv__ResetError_Request
    std::shared_ptr<wujihand_msgs::srv::ResetError_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__wujihand_msgs__srv__ResetError_Request
    std::shared_ptr<wujihand_msgs::srv::ResetError_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ResetError_Request_ & other) const
  {
    if (this->finger_id != other.finger_id) {
      return false;
    }
    if (this->joint_id != other.joint_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const ResetError_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ResetError_Request_

// alias to use template instance with default allocator
using ResetError_Request =
  wujihand_msgs::srv::ResetError_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace wujihand_msgs


#ifndef _WIN32
# define DEPRECATED__wujihand_msgs__srv__ResetError_Response __attribute__((deprecated))
#else
# define DEPRECATED__wujihand_msgs__srv__ResetError_Response __declspec(deprecated)
#endif

namespace wujihand_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ResetError_Response_
{
  using Type = ResetError_Response_<ContainerAllocator>;

  explicit ResetError_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit ResetError_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    wujihand_msgs::srv::ResetError_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const wujihand_msgs::srv::ResetError_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<wujihand_msgs::srv::ResetError_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<wujihand_msgs::srv::ResetError_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      wujihand_msgs::srv::ResetError_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<wujihand_msgs::srv::ResetError_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      wujihand_msgs::srv::ResetError_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<wujihand_msgs::srv::ResetError_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<wujihand_msgs::srv::ResetError_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<wujihand_msgs::srv::ResetError_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__wujihand_msgs__srv__ResetError_Response
    std::shared_ptr<wujihand_msgs::srv::ResetError_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__wujihand_msgs__srv__ResetError_Response
    std::shared_ptr<wujihand_msgs::srv::ResetError_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ResetError_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const ResetError_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ResetError_Response_

// alias to use template instance with default allocator
using ResetError_Response =
  wujihand_msgs::srv::ResetError_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace wujihand_msgs


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__wujihand_msgs__srv__ResetError_Event __attribute__((deprecated))
#else
# define DEPRECATED__wujihand_msgs__srv__ResetError_Event __declspec(deprecated)
#endif

namespace wujihand_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ResetError_Event_
{
  using Type = ResetError_Event_<ContainerAllocator>;

  explicit ResetError_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit ResetError_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<wujihand_msgs::srv::ResetError_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<wujihand_msgs::srv::ResetError_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<wujihand_msgs::srv::ResetError_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<wujihand_msgs::srv::ResetError_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<wujihand_msgs::srv::ResetError_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<wujihand_msgs::srv::ResetError_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<wujihand_msgs::srv::ResetError_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<wujihand_msgs::srv::ResetError_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    wujihand_msgs::srv::ResetError_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const wujihand_msgs::srv::ResetError_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<wujihand_msgs::srv::ResetError_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<wujihand_msgs::srv::ResetError_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      wujihand_msgs::srv::ResetError_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<wujihand_msgs::srv::ResetError_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      wujihand_msgs::srv::ResetError_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<wujihand_msgs::srv::ResetError_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<wujihand_msgs::srv::ResetError_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<wujihand_msgs::srv::ResetError_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__wujihand_msgs__srv__ResetError_Event
    std::shared_ptr<wujihand_msgs::srv::ResetError_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__wujihand_msgs__srv__ResetError_Event
    std::shared_ptr<wujihand_msgs::srv::ResetError_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ResetError_Event_ & other) const
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
  bool operator!=(const ResetError_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ResetError_Event_

// alias to use template instance with default allocator
using ResetError_Event =
  wujihand_msgs::srv::ResetError_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace wujihand_msgs

namespace wujihand_msgs
{

namespace srv
{

struct ResetError
{
  using Request = wujihand_msgs::srv::ResetError_Request;
  using Response = wujihand_msgs::srv::ResetError_Response;
  using Event = wujihand_msgs::srv::ResetError_Event;
};

}  // namespace srv

}  // namespace wujihand_msgs

#endif  // WUJIHAND_MSGS__SRV__DETAIL__RESET_ERROR__STRUCT_HPP_
