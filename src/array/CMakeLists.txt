cmake_minimum_required(VERSION 3.10)

project(Array)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(array array.c)
target_compile_options(array PRIVATE -fno-stack-protector)
