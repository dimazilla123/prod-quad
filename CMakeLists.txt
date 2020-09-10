cmake_minimum_required(VERSION 3.1)

project(quad-solve)
include_directories(src include)

set(SRC 
    src/main.c
    src/double_utils.c
    src/solver.c
    )

add_executable(quad ${SRC})
add_executable(test_double_utils src/test_double_utils.c src/double_utils.c)
target_link_libraries(quad m)
target_link_libraries(test_double_utils m)
