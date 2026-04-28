cmake_minimum_required(VERSION 3.10)
project(ANIMA VERSION 1.0)

set(TEST_ANI "animate")

include_directories(${CMAKE_SOURCE_DIR}/src/include)

add_executable(${TEST_ANI} src/main/teste.cpp)

target_link_libraries(${TEST_ANI} 
    ${CMAKE_SOURCE_DIR}/src/lib/libsfml-graphics.so
    ${CMAKE_SOURCE_DIR}/src/lib/libsfml-graphics.so.3.1
    ${CMAKE_SOURCE_DIR}/src/lib/libsfml-window.so
    ${CMAKE_SOURCE_DIR}/src/lib/libsfml-window.so.3.1
    ${CMAKE_SOURCE_DIR}/src/lib/libsfml-system.so
    ${CMAKE_SOURCE_DIR}/src/lib/libsfml-system.so.3.1
)

set_target_properties(
    ${TEST_ANI} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)

add_custom_target(
    run_test
    COMMAND ${TEST_ANI}
)