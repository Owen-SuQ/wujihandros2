// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from wujihand_msgs:msg/HandCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "wujihand_msgs/msg/hand_command.hpp"


#ifndef WUJIHAND_MSGS__MSG__DETAIL__HAND_COMMAND__STRUCT_HPP_
#define WUJIHAND_MSGS__MSG__DETAIL__HAND_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__wujihand_msgs__msg__HandCommand __attribute__((deprecated))
#else
# define DEPRECATED__wujihand_msgs__msg__HandCommand __declspec(deprecated)
#endif

namespace wujihand_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct HandCommand_
{
  using Type = HandCommand_<ContainerAllocator>;

  explicit HandCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 20>::iterator, double>(this->target_positions.begin(), this->target_positions.end(), 0.0);
    }
  }

  explicit HandCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    target_positions(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 20>::iterator, double>(this->target_positions.begin(), this->target_positions.end(), 0.0);
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _target_positions_type =
    std::array<double, 20>;
  _target_positions_type target_positions;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__target_positions(
    const std::array<double, 20> & _arg)
  {
    this->target_positions = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    wujihand_msgs::msg::HandCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const wujihand_msgs::msg::HandCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<wujihand_msgs::msg::HandCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<wujihand_msgs::msg::HandCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      wujihand_msgs::msg::HandCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<wujihand_msgs::msg::HandCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      wujihand_msgs::msg::HandCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<wujihand_msgs::msg::HandCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<wujihand_msgs::msg::HandCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<wujihand_msgs::msg::HandCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__wujihand_msgs__msg__HandCommand
    std::shared_ptr<wujihand_msgs::msg::HandCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__wujihand_msgs__msg__HandCommand
    std::shared_ptr<wujihand_msgs::msg::HandCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HandCommand_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->target_positions != other.target_positions) {
      return false;
    }
    return true;
  }
  bool operator!=(const HandCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HandCommand_

// alias to use template instance with default allocator
using HandCommand =
  wujihand_msgs::msg::HandCommand_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace wujihand_msgs

#endif  // WUJIHAND_MSGS__MSG__DETAIL__HAND_COMMAND__STRUCT_HPP_
