cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
add_compile_options(-std=c++11)

project(my_ddynamic_package)

find_package(catkin REQUIRED COMPONENTS
  ddynamic_reconfigure
  roscpp
)

catkin_package()

include_directories(${catkin_INCLUDE_DIRS})

add_executable(my_dynamic_node src/my_node.cpp)
target_link_libraries(my_dynamic_node ${catkin_LIBRARIES})
