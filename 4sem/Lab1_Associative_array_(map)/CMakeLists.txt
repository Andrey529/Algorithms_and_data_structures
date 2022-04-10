cmake_minimum_required(VERSION 3.21)
project(Lab1_Associative_array__map_)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        Lab1_Associative_array__map_ main.cpp
        headers/associativeArray/associativeArray.h src/associativeArray/associativeArray.cpp
        headers/redBlackTree/redBlackTree.h src/redBlackTree/redBlackTree.cpp
        headers/redBlackTree/elemOfRedBlackTree.h src/redBlackTree/elemOfRedBlackTree.cpp
        headers/iteretor/iterator.h
        headers/dataPair/dataPair.h headers/Queue/Queue.h src/Queue/Queue.cpp headers/List/List.h src/List/List.cpp headers/iteretor/RedBlackTreeBreadthFirstTraverseIterator.h)
add_subdirectory(Google_tests)