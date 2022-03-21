cmake_minimum_required(VERSION 3.9 FATAL_ERROR)


set(SOURCE_FILES
  include/hint_history.h
  include/hint.h
  src/hint_history.cpp
  src/hint.cpp
)
add_library(hints STATIC ${SOURCE_FILES})

target_include_directories(hints PUBLIC include PRIVATE src)
set_target_properties(hints PROPERTIES LINKER_LANGUAGE CXX)
