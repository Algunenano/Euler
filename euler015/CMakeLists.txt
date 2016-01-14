cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(Euler015)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wpedantic -Wextra -Weffc++ -g")

include_directories(include)
file(GLOB EULER015_SF "src/*")

add_library(euler015 SHARED ${EULER015_SF})

enable_testing()
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(Euler015Spec test/Euler015Spec.cpp)
target_link_libraries(Euler015Spec euler015 ${GTEST_BOTH_LIBRARIES})
