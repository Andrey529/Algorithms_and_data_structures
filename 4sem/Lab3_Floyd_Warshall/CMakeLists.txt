cmake_minimum_required(VERSION 3.22)
project(Lab3_Floyd_Warshall)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab3_Floyd_Warshall main.cpp headers/Flights/Flight.h headers/Flights/FlightsGraph.h headers/List/List.h src/List/List.cpp src/Flights/FlightsGraph.cpp headers/Exceptions/Exceptions.h)
add_subdirectory(Google_tests)

