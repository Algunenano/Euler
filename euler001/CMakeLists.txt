cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(Euler1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wpedantic -Wextra -Weffc++")

include_directories(include)
file(GLOB EULER1_SF "src/*")

add_library(euler1 SHARED ${EULER1_SF})

enable_testing()
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(Euler1Spec test/Euler1Spec.cpp)
target_link_libraries(Euler1Spec euler1 ${GTEST_BOTH_LIBRARIES})
