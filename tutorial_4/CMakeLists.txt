cmake_minimum_required(VERSION 3.13)

project(cmake_tutorial_4)

set(MYLIB_INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/mylib/include")

add_subdirectory(mylib)
add_subdirectory(tutorial_4)