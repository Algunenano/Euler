cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(Euler11)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wpedantic -Wextra -Weffc++ -g")

include_directories(include)
file(GLOB EULER11_SF "src/*")

add_library(euler11 SHARED ${EULER11_SF})

enable_testing()
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(Euler11Spec test/Euler11Spec.cpp)
target_link_libraries(Euler11Spec euler11 ${GTEST_BOTH_LIBRARIES})
