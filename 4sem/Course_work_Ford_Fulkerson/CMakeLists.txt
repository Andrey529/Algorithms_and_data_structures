cmake_minimum_required(VERSION 3.22)
project(Course_work_Ford_Fulkerson)

set(CMAKE_CXX_STANDARD 20)

add_executable(Course_work_Ford_Fulkerson main.cpp headers/List/List.h src/List/List.cpp headers/Exceptions/Exceptions.h headers/Graph/Graph.h headers/Graph/Edge.h src/Graph/Graph.cpp headers/Graph/Vertex.h)
add_subdirectory(Google_tests)
