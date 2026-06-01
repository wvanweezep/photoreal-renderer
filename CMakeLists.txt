cmake_minimum_required(VERSION 4.1)
project(photoreal CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE MAIN_SOURCES src/*.c)
add_executable(photoreal main.cpp ${MAIN_SOURCES})

target_include_directories(photoreal PRIVATE include/)
