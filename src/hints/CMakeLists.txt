cmake_minimum_required(VERSION 3.9 FATAL_ERROR)

add_library(hints STATIC include/hints.h src/hints.cpp)

target_include_directories(hints PUBLIC include PRIVATE hints.cpp)
set_target_properties(hints PROPERTIES LINKER_LANGUAGE CXX)
