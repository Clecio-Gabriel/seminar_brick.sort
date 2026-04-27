cmake_minimum_required(VERSION 3.20)
project(brick_sort)

set(PROF_LIB "prof_lib")

add_subdirectory(src/lib)
add_subdirectory(src/main)

target_link_libraries(
    ${PROJECT_NAME}
    ${PROF_LIB}
)

set_target_properties(
    ${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)

add_custom_target(
    run_test
    COMMAND ${PROJECT_NAME}
)