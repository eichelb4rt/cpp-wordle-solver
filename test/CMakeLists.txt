cmake_minimum_required(VERSION 3.9 FATAL_ERROR)
project(tests VERSION 0.1.0 LANGUAGES CXX)


# get Catch2
Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.0-preview3
)

FetchContent_MakeAvailable(Catch2)


# These tests can use the Catch2-provided main
set(SOURCE_FILES
  test_add.cpp
  test_hint.cpp
  test_hint_history.cpp
)
add_executable(tests ${SOURCE_FILES})
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain PRIVATE trivial hints)


# enable automatic test registration
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(Catch)
include(CTest)
catch_discover_tests(tests)
