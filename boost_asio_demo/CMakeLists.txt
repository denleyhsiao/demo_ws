cmake_minimum_required(VERSION 2.8)

project(boost_asio_demo)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
 
include_directories(include)
add_executable(boost_asio_demo 
  src/deadline_timer.cpp 
  src/delay_deadline_timer.cpp
  src/wake_deadline_timer.cpp
  src/main.cpp
  )
