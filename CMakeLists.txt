cmake_minimum_required(VERSION 3.12)
project(MyClockProject C)
set(CMAKE_C_COMPILER gcc)
set(MAIN_FILE "main.c")
file(GLOB_RECURSE SOURCE_FILES "${PROJECT_SOURCE_DIR}/src/*.c")

include_directories("${PROJECT_SOURCE_DIR}/include")

set(CMAKE_C_STANDARD 99)
set(C_STANDARD_REQUIRED true)

add_library(LogicLib ${SOURCE_FILES})
add_executable(Main ${MAIN_FILE})

target_link_libraries(Main PUBLIC LogicLib)

target_compile_options(Main PRIVATE -Wall -g)
