cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(Euler012)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wpedantic -Wextra -Weffc++ -g")

include_directories(include)
file(GLOB EULER012_SF "src/*")

add_library(euler012 SHARED ${EULER012_SF})

enable_testing()
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(Euler012Spec test/Euler012Spec.cpp)
target_link_libraries(Euler012Spec euler012 ${GTEST_BOTH_LIBRARIES})
