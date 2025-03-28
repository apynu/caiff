cmake_minimum_required(VERSION 3.10)

project(DynamicArray)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(dynamic_array dynamic_array.cpp)
add_executable(stack_dynamic_array stack_dynamic_array.cpp)
target_compile_options(stack_dynamic_array PRIVATE -fno-stack-protector)
