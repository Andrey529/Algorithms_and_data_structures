#ifndef COURSE_WORK_FORD_FULKERSON_GRAPH_H
#define COURSE_WORK_FORD_FULKERSON_GRAPH_H

#include <fstream>

#include "../List/List.h"
#include "Edge.h"
#include "../Exceptions/Exceptions.h"

class Graph {
private:
    List<Edge> edges_;
public:
    Graph() : edges_() {}
    explicit Graph(const List<Edge> &edges) : edges_(edges) {}
    explicit Graph(List<Edge> &&edges) : edges_(std::move(edges)) {}
    explicit Graph(const std::string &fileWithEdgesPath) : edges_() {
        parseEdgesFromFile(fileWithEdgesPath);
    }

    void parseEdgesFromFile(const std::string &fileWithEdgesPath);

    List<Edge> &getEdges() { return edges_; }
};

#endif //COURSE_WORK_FORD_FULKERSON_GRAPH_H
