cmake_minimum_required(VERSION 3.22)
project(Lab2_Huffmon_coding)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab2_Huffmon_coding
        main.cpp
        src/AssociativeArray/AssociativeArray.cpp
        headers/DataPair/DataPair.h
        headers/Iterator/Iterator.h
        headers/Iterator/RedBlackTreeBreadthFirstTraverseIterator.h
        src/Iterator/RedBlackTreeBreadthFirstTraverseIterator.cpp
        headers/List/List.h src/List/List.cpp
        headers/Queue/Queue.h src/Queue/Queue.cpp
        headers/RedBlackTree/RedBlackTree.h src/RedBlackTree/RedBlackTree.cpp
        headers/RedBlackTree/ElemOfRedBlackTree.h src/RedBlackTree/ElemOfRedBlackTree.cpp
        headers/HuffmanCode/HuffmanCode.h src/HuffmanCode/HuffmanCode.cpp headers/HuffmanCode/HuffmanTree.h)
add_subdirectory(Google_tests)
