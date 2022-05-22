#ifndef COURSE_WORK_FORD_FULKERSON_GRAPH_H
#define COURSE_WORK_FORD_FULKERSON_GRAPH_H

#include <fstream>

#include "../Exceptions/Exceptions.h"
#include "Vertex.h"

class Graph {
private:
    List<Edge> edges_;
    List<Vertex> vertexes_;
    Vertex startVertex_;
    Vertex finishVertex_;


    void buildStartGraph();
    void configListVertexes();
public:
    Graph() : startVertex_("S"), finishVertex_("T") {}

    explicit Graph(const List<Edge> &edges, const std::string &startVertex = "S", const std::string &finishVertex = "F")
            : edges_(edges), startVertex_(startVertex), finishVertex_(finishVertex) {
        process();
    }

    explicit Graph(List<Edge> &&edges, const std::string &startVertex = "S", const std::string &finishVertex = "F")
            : edges_(std::move(edges)), startVertex_(startVertex), finishVertex_(finishVertex) {
        process();
    }

    explicit Graph(const std::string &fileWithEdgesPath, const std::string &startVertex = "S",
                   const std::string &finishVertex = "F")
            : edges_(), startVertex_(startVertex), finishVertex_(finishVertex) {
        parseEdgesFromFile(fileWithEdgesPath);
        process();
    }

    List<Edge> &getEdges() { return edges_; }

    void parseEdgesFromFile(const std::string &fileWithEdgesPath);
    void clear();
    void process();

};

#endif //COURSE_WORK_FORD_FULKERSON_GRAPH_H
