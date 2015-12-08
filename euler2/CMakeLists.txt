cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(Euler2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wpedantic -Wextra -Weffc++")

include_directories(include)
file(GLOB EULER2_SF "src/*")

add_library(euler2 SHARED ${EULER2_SF})

enable_testing()
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(Euler2Spec test/Euler2Spec.cpp)
target_link_libraries(Euler2Spec euler2 ${GTEST_BOTH_LIBRARIES})
