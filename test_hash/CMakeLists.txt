cmake_minimum_required(VERSION 3.30)

project(test_hash VERSION 0.1 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Boost 1.86.0 REQUIRED)

include_directories("${Boost_INCLUDE_DIRS}")

add_executable(test_hash src/main.cpp)
# target_link_libraries(test_hash PRIVATE Boost::container_hash)

