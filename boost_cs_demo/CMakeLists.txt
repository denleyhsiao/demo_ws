cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME boost_cs_demo)
project(${PROJECT_NAME})

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(include)
add_executable(client_demo src/client.cpp src/client_demo.cpp)
add_executable(server_demo src/server.cpp src/server_demo.cpp)
