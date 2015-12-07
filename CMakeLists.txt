cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(Euler10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wpedantic -Wextra -Weffc++")

include_directories(include)
file(GLOB EULER10_SF "src/*")

add_library(euler10 SHARED ${EULER10_SF})

enable_testing()
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(Euler10Spec test/Euler10Spec.cpp)
target_link_libraries(Euler10Spec euler10 ${GTEST_BOTH_LIBRARIES})
