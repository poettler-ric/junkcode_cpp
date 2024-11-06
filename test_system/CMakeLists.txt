cmake_minimum_required(VERSION 3.30)

project(test_system VERSION 0.1 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Boost 1.86.0 REQUIRED COMPONENTS process)

# if(Boost_FOUND)
#   include_directories (SYSTEM ${Boost_INCLUDE_DIR})
# endif()

add_executable(test_system src/main.cpp)
target_link_libraries(test_system PRIVATE Boost::process)

