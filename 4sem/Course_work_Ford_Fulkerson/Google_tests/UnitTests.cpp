#include "gtest/gtest.h"

#include "../headers/Graph/Graph.h"

TEST(test1, test1) {
    Graph graph("/home/andrey/Projects/Algorithms_and_data_structures/4sem/Course_work_Ford_Fulkerson/Google_tests/data1.txt");
    ASSERT_EQ(5, graph.getMaxFlow());
}

TEST(test2, test2) {
    Graph graph("/home/andrey/Projects/Algorithms_and_data_structures/4sem/Course_work_Ford_Fulkerson/Google_tests/data2.txt");
    ASSERT_EQ(9, graph.getMaxFlow());
}

TEST(test3, test3) {
    Graph graph("/home/andrey/Projects/Algorithms_and_data_structures/4sem/Course_work_Ford_Fulkerson/Google_tests/data3.txt");
    ASSERT_EQ(10, graph.getMaxFlow());
}