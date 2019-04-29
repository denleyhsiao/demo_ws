cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME boost_demo)
project(${PROJECT_NAME})
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Boost REQUIRED thread)
include_directories(${Boost_INCLUDE_DIR})
add_executable(${PROJECT_NAME}
  src/third.cpp
)
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})
add_executable(${PROJECT_NAME}_test
  test/test_format.cpp
  test/main.cpp)
target_link_libraries(${PROJECT_NAME}_test ${GTEST_BOTH_LIBRARIES})
