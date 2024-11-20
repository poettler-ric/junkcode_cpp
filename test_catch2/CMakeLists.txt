cmake_minimum_required(VERSION 3.30)

project(test_catch2 VERSION 0.1 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Catch2 3 REQUIRED)
# These tests can use the Catch2-provided main
add_executable(test src/lib.cpp)
target_link_libraries(test PRIVATE Catch2::Catch2WithMain)

add_library(add src/lib.hpp src/lib.cpp)
target_link_libraries(add PRIVATE Catch2::Catch2)

add_executable(test_catch2 src/main.cpp)
target_link_libraries(test_catch2 PRIVATE add)