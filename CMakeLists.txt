cmake_minimum_required(VERSION 4.1)
project(photoreal CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE MAIN_SOURCES src/*.cpp)
file(GLOB_RECURSE TEST_SOURCES tests/*.cpp)

add_executable(photoreal main.cpp ${MAIN_SOURCES})
add_executable(unittest tests/main.cpp ${TEST_SOURCES})

target_include_directories(photoreal PRIVATE include/ external/)
target_include_directories(unittest PRIVATE include/ external/)

enable_testing()
add_test(NAME unittest COMMAND unittest)
