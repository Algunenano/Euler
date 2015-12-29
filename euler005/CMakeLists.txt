cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(Euler5)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wpedantic -Wextra -Weffc++ -g")

include_directories(include)
file(GLOB EULER5_SF "src/*")

add_library(euler5 SHARED ${EULER5_SF})

enable_testing()
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(Euler5Spec test/Euler5Spec.cpp)
target_link_libraries(Euler5Spec euler5 ${GTEST_BOTH_LIBRARIES})
