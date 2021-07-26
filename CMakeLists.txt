cmake_minimum_required(VERSION 3.4)
project(pybind11project)
enable_testing()

set(CMAKE_CXX_STANDARD 11)

execute_process(COMMAND git submodule update --init --recursive
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

find_package (Python3 COMPONENTS Interpreter Development)
add_subdirectory(extern/pybind11)

add_subdirectory(franklib)
add_subdirectory(frank)
add_subdirectory(tests)

