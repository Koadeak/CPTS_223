cmake_minimum_required(VERSION 3.16)
project(MA1_Project)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_BUILD_TYPE Debug)

add_executable(MA1_exe main.cpp Queue.hpp TestQueue.hpp TestQueue.cpp)
