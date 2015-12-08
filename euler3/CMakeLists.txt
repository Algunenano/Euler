cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(Euler3)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wpedantic -Wextra -Weffc++")

include_directories(include)
file(GLOB EULER3_SF "src/*")

add_library(euler3 SHARED ${EULER3_SF})

enable_testing()
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(Euler3Spec test/Euler3Spec.cpp)
target_link_libraries(Euler3Spec euler3 ${GTEST_BOTH_LIBRARIES})
