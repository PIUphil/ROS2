cmake_minimum_required(VERSION 3.19)
project(RefCount)

set(CMAKE_CXX_STANDARD 14)

add_executable(RefCount main.cpp RefCount.cpp RefCount.h)