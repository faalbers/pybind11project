cmake_minimum_required(VERSION 3.4)
project(pybind11project)
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(franklib)

add_subdirectory(extern/pybind11)
add_subdirectory(frank)
