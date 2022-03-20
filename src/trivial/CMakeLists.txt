cmake_minimum_required(VERSION 3.9 FATAL_ERROR)

find_package(OpenMP REQUIRED)

add_library(trivial STATIC include/add.h)
target_link_libraries(trivial OpenMP::OpenMP_CXX)

target_include_directories(trivial PUBLIC include)
set_target_properties(trivial PROPERTIES LINKER_LANGUAGE CXX)
