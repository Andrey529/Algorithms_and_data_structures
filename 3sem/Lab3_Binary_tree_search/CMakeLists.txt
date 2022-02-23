cmake_minimum_required(VERSION 3.17)
project(Lab3_Binary_tree_search)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab3_Binary_tree_search main.cpp headers/queue/queue.h headers/queue/elemOfQueue.h headers/stack/stack.h headers/stack/elemOfStack.h headers/iterators/iterator.h headers/binaryTreeSearch/binaryTreeSearch.h headers/binaryTreeSearch/elemOfBinaryTreeSearch.h headers/iterators/binaryTreeSearchDepthFirstTraverseIterator.h headers/iterators/binaryTreeSearchBreadthFirstTraverseIterator.h src/stack/stack.cpp src/stack/elemOfStack.cpp src/queue/queue.cpp src/queue/elemOfQueue.cpp src/iterators/binaryTreeSearchDepthFirstTraverseIterator.cpp src/iterators/binaryTreeSearchBreadthFirstTraverseIterator.cpp src/binaryTreeSearch/binaryTreeSearch.cpp src/binaryTreeSearch/elemOfBinaryTreeSearch.cpp)
add_subdirectory(Google_tests)