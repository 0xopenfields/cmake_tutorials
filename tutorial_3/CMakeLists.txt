cmake_minimum_required(VERSION 3.13)

project(cmake_tutorial_3)

# 変数
set(VAR_VALUE       1)
set(VAR_STR         "文字列")
set(VAR_BOOL        ON)
set(VAR_ENV         $ENV{PATH})

# デバッグ
message(STATUS  "VAR_VALUE=${VAR_VALUE}")
message(STATUS  "VAR_STR=${VAR_STR}") 
message(STATUS  "VAR_BOOL=${VAR_BOOL}")

# 環境変数
message(STATUS  "PATH=$ENV{PATH})")

# 分岐
if(VAR＿FLAG)
    message(STATUS "VAR_FLAG is TRUE")
else()
    message(STATUS "VAR_FLAG is FALSE")
endif()

# ファイル・リスト
file(GLOB_RECURSE SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cxx)

# ループ
foreach(file ${SOURCES})
    message(STATUS ${file})
endforeach()

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE include)