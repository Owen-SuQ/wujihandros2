// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from wujihand_msgs:msg/HandState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "wujihand_msgs/msg/hand_state.hpp"


#ifndef WUJIHAND_MSGS__MSG__DETAIL__HAND_STATE__STRUCT_HPP_
#define WUJIHAND_MSGS__MSG__DETAIL__HAND_STATE__STRUCT_HPP_

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
# define DEPRECATED__wujihand_msgs__msg__HandState __attribute__((deprecated))
#else
# define DEPRECATED__wujihand_msgs__msg__HandState __declspec(deprecated)
#endif

namespace wujihand_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct HandState_
{
  using Type = HandState_<ContainerAllocator>;

  explicit HandState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->handedness = "";
      this->system_temperature = 0.0f;
      this->input_voltage = 0.0f;
      std::fill<typename std::array<double, 20>::iterator, double>(this->actual_positions.begin(), this->actual_positions.end(), 0.0);
      std::fill<typename std::array<double, 20>::iterator, double>(this->target_positions.begin(), this->target_positions.end(), 0.0);
      std::fill<typename std::array<float, 20>::iterator, float>(this->joint_temperatures.begin(), this->joint_temperatures.end(), 0.0f);
      std::fill<typename std::array<uint32_t, 20>::iterator, uint32_t>(this->error_codes.begin(), this->error_codes.end(), 0ul);
      std::fill<typename std::array<bool, 20>::iterator, bool>(this->enabled.begin(), this->enabled.end(), false);
    }
  }

  explicit HandState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    handedness(_alloc),
    actual_positions(_alloc),
    target_positions(_alloc),
    joint_temperatures(_alloc),
    error_codes(_alloc),
    enabled(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->handedness = "";
      this->system_temperature = 0.0f;
      this->input_voltage = 0.0f;
      std::fill<typename std::array<double, 20>::iterator, double>(this->actual_positions.begin(), this->actual_positions.end(), 0.0);
      std::fill<typename std::array<double, 20>::iterator, double>(this->target_positions.begin(), this->target_positions.end(), 0.0);
      std::fill<typename std::array<float, 20>::iterator, float>(this->joint_temperatures.begin(), this->joint_temperatures.end(), 0.0f);
      std::fill<typename std::array<uint32_t, 20>::iterator, uint32_t>(this->error_codes.begin(), this->error_codes.end(), 0ul);
      std::fill<typename std::array<bool, 20>::iterator, bool>(this->enabled.begin(), this->enabled.end(), false);
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _handedness_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _handedness_type handedness;
  using _system_temperature_type =
    float;
  _system_temperature_type system_temperature;
  using _input_voltage_type =
    float;
  _input_voltage_type input_voltage;
  using _actual_positions_type =
    std::array<double, 20>;
  _actual_positions_type actual_positions;
  using _target_positions_type =
    std::array<double, 20>;
  _target_positions_type target_positions;
  using _joint_temperatures_type =
    std::array<float, 20>;
  _joint_temperatures_type joint_temperatures;
  using _error_codes_type =
    std::array<uint32_t, 20>;
  _error_codes_type error_codes;
  using _enabled_type =
    std::array<bool, 20>;
  _enabled_type enabled;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__handedness(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->handedness = _arg;
    return *this;
  }
  Type & set__system_temperature(
    const float & _arg)
  {
    this->system_temperature = _arg;
    return *this;
  }
  Type & set__input_voltage(
    const float & _arg)
  {
    this->input_voltage = _arg;
    return *this;
  }
  Type & set__actual_positions(
    const std::array<double, 20> & _arg)
  {
    this->actual_positions = _arg;
    return *this;
  }
  Type & set__target_positions(
    const std::array<double, 20> & _arg)
  {
    this->target_positions = _arg;
    return *this;
  }
  Type & set__joint_temperatures(
    const std::array<float, 20> & _arg)
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
  Type & set__enabled(
    const std::array<bool, 20> & _arg)
  {
    this->enabled = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    wujihand_msgs::msg::HandState_<ContainerAllocator> *;
  using ConstRawPtr =
    const wujihand_msgs::msg::HandState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<wujihand_msgs::msg::HandState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<wujihand_msgs::msg::HandState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      wujihand_msgs::msg::HandState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<wujihand_msgs::msg::HandState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      wujihand_msgs::msg::HandState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<wujihand_msgs::msg::HandState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<wujihand_msgs::msg::HandState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<wujihand_msgs::msg::HandState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__wujihand_msgs__msg__HandState
    std::shared_ptr<wujihand_msgs::msg::HandState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__wujihand_msgs__msg__HandState
    std::shared_ptr<wujihand_msgs::msg::HandState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HandState_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->handedness != other.handedness) {
      return false;
    }
    if (this->system_temperature != other.system_temperature) {
      return false;
    }
    if (this->input_voltage != other.input_voltage) {
      return false;
    }
    if (this->actual_positions != other.actual_positions) {
      return false;
    }
    if (this->target_positions != other.target_positions) {
      return false;
    }
    if (this->joint_temperatures != other.joint_temperatures) {
      return false;
    }
    if (this->error_codes != other.error_codes) {
      return false;
    }
    if (this->enabled != other.enabled) {
      return false;
    }
    return true;
  }
  bool operator!=(const HandState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HandState_

// alias to use template instance with default allocator
using HandState =
  wujihand_msgs::msg::HandState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace wujihand_msgs

#endif  // WUJIHAND_MSGS__MSG__DETAIL__HAND_STATE__STRUCT_HPP_
