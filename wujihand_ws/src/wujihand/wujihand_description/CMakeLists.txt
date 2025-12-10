cmake_minimum_required(VERSION 3.8)
project(wujihand_description)

find_package(ament_cmake REQUIRED)

# Install URDF, meshes and rviz files
install(DIRECTORY urdf meshes rviz
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
