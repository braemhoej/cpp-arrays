cmake_minimum_required(VERSION 3.21)
project(arrays)
project(arrays VERSION 1.0.0 )
set(CMAKE_CXX_STANDARD 20)
include(GNUInstallDirs)
add_library(arrays SHARED src/array.cpp include/array.h)

target_include_directories(arrays PRIVATE include)
target_include_directories(arrays PRIVATE src)

set_target_properties(arrays PROPERTIES PUBLIC_HEADER include/arrays.h)
set_target_properties(arrays PROPERTIES VERSION ${PROJECT_VERSION})

install(TARGETS arrays
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})