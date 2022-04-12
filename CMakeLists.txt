cmake_minimum_required(VERSION 3.21)
project(Arrays VERSION 1.0.0 )
set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES src/array.cpp)

add_library(${PROJECT_NAME} ${SOURCE_FILES})