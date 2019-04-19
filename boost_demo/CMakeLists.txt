cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME boost_demo)
project(${PROJECT_NAME})

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})
add_executable(${PROJECT_NAME} 
  test/test_format.cpp 
  test/main.cpp)
target_link_libraries(${PROJECT_NAME} ${GTEST_BOTH_LIBRARIES})
