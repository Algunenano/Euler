cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(Euler9)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wpedantic -Wextra -Weffc++ -g")

include_directories(include)
file(GLOB EULER9_SF "src/*")

add_library(euler9 SHARED ${EULER9_SF})

enable_testing()
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(Euler9Spec test/Euler9Spec.cpp)
target_link_libraries(Euler9Spec euler9 ${GTEST_BOTH_LIBRARIES})
