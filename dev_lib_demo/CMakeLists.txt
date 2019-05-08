cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME dev_lib_demo)
project(${PROJECT_NAME})
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Boost REQUIRED filesystem)
include_directories(
  ../vendor/dev_lib/include
  ${Boost_INCLUDE_DIR}
  )
add_executable(${PROJECT_NAME}
  src/get_lines.cpp
  ../vendor/dev_lib/src/dev_helper.cpp
  ../vendor/dev_lib/src/boost_helper.cpp
  ../vendor/dev_lib/src/linux_os_helper.cpp
)
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
