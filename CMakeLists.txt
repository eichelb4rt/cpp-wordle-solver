cmake_minimum_required(VERSION 3.9 FATAL_ERROR)
project(main VERSION 0.1.0 LANGUAGES CXX)

add_subdirectory(test)
include(CTest)

add_subdirectory(src/trivial)

add_executable(main src/main.cpp)
target_link_libraries(main PUBLIC trivial)

target_compile_options(main PRIVATE -Ofast -march=native)
