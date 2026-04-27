cmake_minimum_required(VERSION 3.20)
project(brick_sort)

# Set Variables
set(PROF_LIB "prof_lib")

# Adding subdirectories
add_subdirectory(src/lib)
add_subdirectory(src/main)

# Linking the libraries with the program
target_link_libraries(
    ${PROJECT_NAME}
    ${PROF_LIB}
)

# Realocatiing the executable to the main folder
set_target_properties(
    ${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)

# Command to run a test right after the executable is compiled
add_custom_target(
    run_test
    COMMAND ${PROJECT_NAME}
)