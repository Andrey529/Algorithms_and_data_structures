cmake_minimum_required(VERSION 3.17)
project(Lab1_List)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab1_List main.cpp headers/data.h headers/listOfInts.h)

add_subdirectory(Google_tests)