#ifndef COURSE_WORK_FORD_FULKERSON_GRAPH_H
#define COURSE_WORK_FORD_FULKERSON_GRAPH_H

#include <fstream>

#include "../Exceptions/Exceptions.h"
#include "Vertex.h"

class Graph {
private:
    List<std::shared_ptr<Edge>> edges_;
    List<std::shared_ptr<Vertex>> vertexes_;
    std::shared_ptr<Vertex> startVertex_;
    std::shared_ptr<Vertex> finishVertex_;

    void process();

    void parseEdgesFromFile(const std::string &fileWithEdgesPath);
    void configListVertexes();
    void buildStartGraph();
    void algorithm();

public:
    Graph() = delete;
    ~Graph() = default;

    explicit Graph(const std::string &fileWithEdgesPath, const std::string &startVertex = "S",
                   const std::string &finishVertex = "T")
            : edges_(), startVertex_(std::make_shared<Vertex>(startVertex)),
              finishVertex_(std::make_shared<Vertex>(finishVertex)) {
        parseEdgesFromFile(fileWithEdgesPath);
        process();
    }

    List<std::shared_ptr<Edge>> &getEdges() { return edges_; }


};

#endif //COURSE_WORK_FORD_FULKERSON_GRAPH_H
