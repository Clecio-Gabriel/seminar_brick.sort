cmake_minimum_required(VERSION 3.20)
project(brick_sort)

set(PROF_LIB "prof_lib")
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(
    ${PROJECT_NAME}
    ${PROF_LIB}
)

add_subdirectory(lib)

add_custom_target(
    run_test
    COMMAND ${PROJECT_NAME}
)