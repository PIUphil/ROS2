cmake_minimum_required(VERSION 3.19)
project(ScoreGrade10)

set(CMAKE_CXX_STANDARD 14)

add_executable(ScoreGrade10 main.cpp Handle.h Core.cpp Grad.cpp grade.cpp Student_info.cpp)
