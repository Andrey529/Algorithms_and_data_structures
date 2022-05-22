#include "../../headers/Graph/Graph.h"

void Graph::parseEdgesFromFile(const std::string &fileWithEdgesPath) {
    std::fstream f;
    f.open(fileWithEdgesPath, std::ios::in);
    if (f.bad()) {
        throw Exception("Bad file", 1);
    }
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
