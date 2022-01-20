project(cmake_tutorial_4)

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/tutorial_4.cc)

add_dependencies(${PROJECT_NAME} mylib)

target_include_directories(${PROJECT_NAME} PRIVATE ${MYLIB_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} mylib)