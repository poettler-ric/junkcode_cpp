cmake_minimum_required(VERSION 3.30)

project(test_fortran VERSION 0.1 LANGUAGES C CXX Fortran)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(out src/out.f90)
add_executable(in src/in.cpp)

