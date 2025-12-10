cmake_minimum_required(VERSION 3.8)
project(wujihand_example)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(wujihand_msgs REQUIRED)

add_executable(wujihand_example src/wujihand_example.cpp)
ament_target_dependencies(wujihand_example rclcpp wujihand_msgs)

install(TARGETS wujihand_example
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME})

ament_package()
