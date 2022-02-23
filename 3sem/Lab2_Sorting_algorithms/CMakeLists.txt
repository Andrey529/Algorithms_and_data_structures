cmake_minimum_required(VERSION 3.21)
project(Lab2_Sorting_algorithms)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab2_Sorting_algorithms main.cpp src/functions.cpp src/functions.h)
add_subdirectory(Google_tests)