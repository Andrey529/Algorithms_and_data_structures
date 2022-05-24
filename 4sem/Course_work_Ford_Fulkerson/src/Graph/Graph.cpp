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

        edges_.pushBack(std::make_shared<Edge>(edge));
        if (f.eof()) break;
    }

    f.close();
}


void Graph::process() {
    configListVertexes();
    buildStartGraph();
//    algorithm();
}

void Graph::configListVertexes() {
    for (auto itEdges = edges_.cbegin(); itEdges != edges_.cend(); ++itEdges) {
        auto vertex1 = std::make_shared<Vertex>(itEdges.operator*()->start_);
        auto vertex2 = std::make_shared<Vertex>(itEdges.operator*()->finish_);

        bool notContainsVertex1 = true;
        bool notContainsVertex2 = true;
        if (vertexes_.isEmpty()) {
            vertexes_.pushBack(vertex1);
        }
        for (auto itVertexes = vertexes_.begin(); itVertexes != vertexes_.end(); ++itVertexes) {
            if (itVertexes.operator*()->name_ == vertex1->name_) {
                notContainsVertex1 = false;
            } else if (itVertexes.operator*()->name_ == vertex2->name_) {
                notContainsVertex2 = false;
            }
            if (!notContainsVertex1 && !notContainsVertex2) break;
        }
        if (notContainsVertex1) {
            vertexes_.pushBack(vertex1);
        }
        if (notContainsVertex2) {
            vertexes_.pushBack(vertex2);
        }
    }
}

void Graph::buildStartGraph() {
    for (auto itVertexes = vertexes_.begin(); itVertexes != vertexes_.end(); ++itVertexes) {
        for (auto itEdges = edges_.begin(); itEdges != edges_.end(); ++itEdges) {
            if (itEdges.operator*()->start_ == itVertexes.operator*()->name_) {
                itVertexes.operator*()->edgesForward_.pushBack(*itEdges);
                for (auto itVertexes2 = vertexes_.begin(); itVertexes2 != vertexes_.end(); ++itVertexes2) {
                    if (itVertexes2.operator*()->name_ == itEdges.operator*()->finish_) {
                        itVertexes.operator*()->vertexesForward_.pushBack(*itVertexes2);
                    }
                }
            }
        }
    }

    for (auto it = vertexes_.begin(); it != vertexes_.end(); ++it) {
        if (it.operator*()->name_ == startVertex_->name_) {
            startVertex_ = *it;
        } else if (it.operator*()->name_ == finishVertex_->name_) {
            finishVertex_ = *it;
        }
    }
}

//void Graph::algorithm() {
//
//    while (true) {
//        List<Edge> wayEdges;
//        List<Vertex> wayVertexes;
//        auto currentVertex = startVertex_; // ??
//        size_t flow = INT64_MAX;
//        while (currentVertex.name_ != finishVertex_.name_) {
//            if (currentVertex.edgesForward_.isEmpty()) {
//                break;
//            }
//            if (currentVertex.edgesForward_.at(0).capacity_ < flow) {
//                flow = currentVertex.edgesForward_.at(0).capacity_;
//            }
//            wayEdges.pushBack(currentVertex.edgesForward_.at(0));
//            wayVertexes.pushBack(currentVertex);
//            for(auto it = vertexes_.begin(); it != vertexes_.end(); ++it) {
//                if (it.operator*().name_ == currentVertex.edgesForward_.at(0).finish_) { //?? .at(0).finish_
//                    currentVertex = *it;
//                    break;
//                }
//            }
//        }
//
//        if (currentVertex.name_ == finishVertex_.name_) {
//            for (auto itEdges = edges_.begin(); itEdges != edges_.end(); ++itEdges) {
//                for (auto itWayEdges = wayEdges.begin(); itWayEdges != wayEdges.end(); ++itWayEdges) {
//                    if (itEdges.operator*().start_ == itWayEdges.operator*().start_ &&
//                        itEdges.operator*().finish_ == itWayEdges.operator*().finish_) {
//                        // ?????????????
//                    }
//                }
//            }
//        }
//
//        if (currentVertex.edgesForward_.isEmpty() && currentVertex == startVertex_) {
//            break;
//        }
//    }
//}




