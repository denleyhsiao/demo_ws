cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME boost_asio_demo)
project(${PROJECT_NAME})

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
 
include_directories(include)
add_executable(${PROJECT_NAME} 
  src/deadline_timer.cpp 
  src/delay_deadline_timer.cpp
  src/wake_deadline_timer.cpp
  src/main.cpp
  )
