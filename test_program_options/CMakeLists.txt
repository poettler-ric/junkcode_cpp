cmake_minimum_required(VERSION 3.30)

project(test_program_options VERSION 0.1 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Boost 1.86.0 REQUIRED COMPONENTS program_options)

add_executable(test_program_options src/main.cpp)
target_link_libraries(test_program_options PRIVATE Boost::program_options)

