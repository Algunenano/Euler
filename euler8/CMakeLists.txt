cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(Euler8)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wpedantic -Wextra -Weffc++ -g")

include_directories(include)
file(GLOB EULER8_SF "src/*")

add_library(euler8 SHARED ${EULER8_SF})

enable_testing()
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(Euler8Spec test/Euler8Spec.cpp)
target_link_libraries(Euler8Spec euler8 ${GTEST_BOTH_LIBRARIES})
