cmake_minimum_required(VERSION 3.6)
project(matrix)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Matrix.cpp Matrix.h operators.cpp)
add_executable(matrix ${SOURCE_FILES})