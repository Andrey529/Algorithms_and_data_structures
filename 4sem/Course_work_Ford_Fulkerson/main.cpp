#include <iostream>

#include "headers/Graph/Graph.h"

int main() {

    Graph graph("/home/andrey/Projects/Algorithms_and_data_structures/4sem/Course_work_Ford_Fulkerson/data.txt");
    std::cout << graph.getEdges() << std::endl;

    return 0;
}
