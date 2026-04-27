add_library(${PROF_LIB} lib.cpp)

target_include_directories(
    ${PROF_LIB}
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)