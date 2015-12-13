cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(Euler4)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wpedantic -Wextra -Weffc++ -g")

include_directories(include)
file(GLOB EULER4_SF "src/*")

add_library(euler4 SHARED ${EULER4_SF})

enable_testing()
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(Euler4Spec test/Euler4Spec.cpp)
target_link_libraries(Euler4Spec euler4 ${GTEST_BOTH_LIBRARIES})
