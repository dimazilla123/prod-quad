cmake_minimum_required(VERSION 3.1)

project(quad-solve)
include_directories(src include)

set(SRC 
    src/main.c
    src/double_utils.c
    )

add_executable(quad ${SRC})
target_link_libraries(quad m)