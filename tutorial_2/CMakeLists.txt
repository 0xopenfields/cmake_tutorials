cmake_minimum_required(VERSION 3.13)

project(cmake_tutorial_2)

add_executable(cmake_tutorial_2
                src/tutorial_2.cc
                src/add.cc)

target_include_directories(cmake_tutorial_2 PRIVATE include)