cmake_minimum_required(VERSION 3.21)
project(Lab1_Associative_array__map_)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        Lab1_Associative_array__map_ main.cpp
        headers/AssociativeArray/AssociativeArray.h src/AssociativeArray/AssociativeArray.cpp
        headers/RedBlackTree/RedBlackTree.h src/RedBlackTree/RedBlackTree.cpp
        headers/RedBlackTree/ElemOfRedBlackTree.h src/RedBlackTree/ElemOfRedBlackTree.cpp
        headers/iterator/Iterator.h
        headers/DataPair/DataPair.h
        headers/Queue/Queue.h src/Queue/Queue.cpp
        headers/List/List.h src/List/List.cpp
        headers/iterator/RedBlackTreeBreadthFirstTraverseIterator.h src/iterator/RedBlackTreeBreadthFirstTraverseIterator.cpp
)
add_subdirectory(Google_tests)