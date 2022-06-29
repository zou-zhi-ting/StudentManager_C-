cmake_minimum_required(VERSION 3.15)
project(demo_student)

set(CMAKE_CXX_STANDARD 14)

add_executable(demo_student main.cpp Student.h Grade01.cpp Grade01.h Grade02.cpp Grade02.h Grade03.cpp Grade03.h Grade04.cpp Grade04.h StudentManager.cpp StudentManager.h)