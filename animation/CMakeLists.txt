cmake_minimum_required(VERSION 4.0)

project(SORTL_ANIM CXX)

set(SORTL "sortl")

include_directories(${CMAKE_SOURCE_DIR}/src/include)
add_subdirectory(src/main)

target_link_libraries(${SORTL} 
    ${CMAKE_SOURCE_DIR}/lib/libsfml-graphics.so
    ${CMAKE_SOURCE_DIR}/lib/libsfml-graphics.so.3.1
    ${CMAKE_SOURCE_DIR}/lib/libsfml-window.so
    ${CMAKE_SOURCE_DIR}/lib/libsfml-window.so.3.1
    ${CMAKE_SOURCE_DIR}/lib/libsfml-system.so
    ${CMAKE_SOURCE_DIR}/lib/libsfml-system.so.3.1
)

set_target_properties(
    ${SORTL} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)