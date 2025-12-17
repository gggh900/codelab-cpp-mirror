cmake_minimum_required (VERSION 2.6)
set (CMAKE_PROJ_NAME "p229")
set (proj_name ${CMAKE_PROJ_NAME})
project (${proj_name})

# The version number.

set (test_VERSION_MAJOR 1)
set (test_VERSION_MINOR 0)
set(CMAKE_CXX_COMPILER hipcc)
include_directories("${PROJECT_BINARY_DIR}")

add_executable(${proj_name} ${proj_name}.cpp)
