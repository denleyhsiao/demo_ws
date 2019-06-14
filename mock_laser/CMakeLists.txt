cmake_minimum_required(VERSION 2.8)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(PROJECT_NAME mock_laser)
project(${PROJECT_NAME})

include_directories(${CMAKE_SOURCE_DIR}/vendor/websocketpp)
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} sfw_lib)
