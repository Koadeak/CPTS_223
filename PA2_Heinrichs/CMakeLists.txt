cmake_minimum_required(VERSION 3.16)
project(CPTS_223_PA2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_BUILD_TYPE Debug)

add_executable(PA2_exe main.cpp main.cpp AVLNode.hpp AVLTree.hpp Tests.hpp)