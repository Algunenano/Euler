cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(Euler013)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wpedantic -Wextra -Weffc++ -g -lgmpxx -lgmp")

include_directories(include)
file(GLOB EULER013_SF "src/*")

add_library(euler013 SHARED ${EULER013_SF})

enable_testing()
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(Euler013Spec test/Euler013Spec.cpp)
target_link_libraries(Euler013Spec euler013 ${GTEST_BOTH_LIBRARIES})
