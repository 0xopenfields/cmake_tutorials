project(mylib)

add_library(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/mylib.cc)

target_include_directories(${PROJECT_NAME} PRIVATE
                            ${MYLIB_INCLUDE_DIRS})