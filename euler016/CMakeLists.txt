cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(Euler016)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wpedantic -Wextra -Weffc++ -g -lgmpxx -lgmp")

include_directories(include)
file(GLOB EULER016_SF "src/*")

add_library(euler016 SHARED ${EULER016_SF})

enable_testing()
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(Euler016Spec test/Euler016Spec.cpp)
target_link_libraries(Euler016Spec euler016 ${GTEST_BOTH_LIBRARIES})
