cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(Euler6)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wpedantic -Wextra -Weffc++ -g")

include_directories(include)
file(GLOB EULER6_SF "src/*")

add_library(euler6 SHARED ${EULER6_SF})

enable_testing()
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(Euler6Spec test/Euler6Spec.cpp)
target_link_libraries(Euler6Spec euler6 ${GTEST_BOTH_LIBRARIES})
