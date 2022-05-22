#include "../../headers/Graph/Graph.h"

void Graph::parseEdgesFromFile(const std::string &fileWithEdgesPath) {
    std::fstream f;
    f.open(fileWithEdgesPath, std::ios::in);
    if (f.bad()) {
        throw Exception("Bad file", 1);
    }
    this->clear();
    char symbol = '\0';
    while (true) {
        int countDelimeters = 0;
        auto edge = Edge();
        while (true) {
            symbol = f.get();

            if (f.eof()) break;
            if (symbol == '\n') break;
            if (symbol == ' ') {
                ++countDelimeters;
                continue;
            }
            if (countDelimeters == 0) {
                edge.start_ = symbol;
            } else if (countDelimeters == 1) {
                edge.finish_ = symbol;
            } else {
                std::string tempStr;
                tempStr.push_back(symbol);
                edge.capacity_ = std::stoi(tempStr);
            }
        }

        edges_.pushBack(edge);
        if (f.eof()) break;
    }

    f.close();
}

void Graph::clear() {
    if (!edges_.isEmpty()) {
        edges_.clear();
    }
}

void Graph::process() {
    configListVertexes();
    buildStartGraph();
}

void Graph::configListVertexes() {
    for (auto itEdges = edges_.cbegin(); itEdges != edges_.cend(); ++itEdges) {
        Vertex vertex1(itEdges.operator*().start_);
        Vertex vertex2(itEdges.operator*().finish_);
        if (!vertexes_.contains(vertex1)) {
            vertexes_.pushBack(vertex1);
        }
        if (!vertexes_.contains(vertex2)) {
            vertexes_.pushBack(vertex2);
        }
    }
}

void Graph::buildStartGraph() {

}




