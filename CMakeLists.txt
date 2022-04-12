cmake_minimum_required(VERSION 3.21)
project(Arrays VERSION 1.0.0 )
set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES src/array.hpp)

add_library(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE src)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})