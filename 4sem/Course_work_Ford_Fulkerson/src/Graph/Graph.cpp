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
        std::string capacity;
        while (true) {
            symbol = f.get();

            if (symbol == '\n' || f.eof()) {
                edge.capacity_ = std::stoi(capacity);
                edge.flow_ = 0;
                break;
            }
            if (symbol == ' ') {
                ++countDelimeters;
                continue;
            }
            if (countDelimeters == 0) {
                edge.start_ = symbol;
            } else if (countDelimeters == 1) {
                edge.finish_ = symbol;
            } else {
                capacity.push_back(symbol);
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
    algorithmFordFulkerson();
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


void Graph::algorithmFordFulkerson() {

    List<std::shared_ptr<Edge>> wayEdges;
    List<std::shared_ptr<Vertex>> wayVertexes;

    while (true) {
        wayEdges.clear();
        wayVertexes.clear();
        int currentFlow = dfs(startVertex_, INT32_MAX, wayEdges, wayVertexes);
        if (currentFlow > 0) {
            maxFlow_ += currentFlow;
        } else {
            break;
        }
    }
}

int Graph::dfs(std::shared_ptr<Vertex> vertex, int flow, List<std::shared_ptr<Edge>> wayEdges,
               List<std::shared_ptr<Vertex>> wayVertexes) {
    if (wayVertexes.contains(vertex)) {
        wayEdges.popBack();
        return 0;
    }
    wayVertexes.pushBack(vertex);
    if (vertex == finishVertex_) {
        return flow;
    }
    for (auto itEdges = vertex->edgesForward_.begin(); itEdges != vertex->edgesForward_.end(); ++itEdges) {
        if (itEdges.operator*()->flow_ < itEdges.operator*()->capacity_) {
            for (auto itVertexes = vertexes_.begin(); itVertexes != vertexes_.end(); ++itVertexes) {
                if (itVertexes.operator*()->name_ == itEdges.operator*()->finish_) {
                    if (!wayEdges.isEmpty()) {
                        bool contains = false;
                        for (auto it = wayEdges.begin(); it != wayEdges.end(); ++it) {
                            if (it.operator*()->start_ == itEdges.operator*()->finish_ && it.operator*()->finish_ == itEdges.operator*()->start_) {
                                contains = true;
                                break;
                            }
                        }
                        if (contains) continue;
                    }

                    wayEdges.pushBack(*itEdges);
                    flow = dfs(*itVertexes, std::min(flow, itEdges.operator*()->capacity_ - itEdges.operator*()->flow_),
                               wayEdges, wayVertexes);
                    if (flow <= 0) {
                        int size = wayEdges.getSize();
                        auto edje = wayEdges.at(size-1);
                        if (edje->start_ == startVertex_->name_ || edje->finish_ == startVertex_->name_) {
                            flow = INT32_MAX;
                        }
                        wayEdges.popBack();
                    } else if (flow > 0) {
                        itEdges.operator*()->flow_ += flow;
                        if (itVertexes.operator*()->edgesForward_.isEmpty()) {
                            if (*itVertexes == finishVertex_) {
                                return flow;
                            } else return 0;
                        }
                        for (auto itEdgesForward = itVertexes.operator*()->edgesForward_.begin();
                             itEdgesForward != itVertexes.operator*()->edgesForward_.end(); ++itEdgesForward) {
                            if (itEdgesForward.operator*()->start_ == itEdges.operator*()->finish_
                                && itEdgesForward.operator*()->finish_ == itEdges.operator*()->start_) {
                                itEdgesForward.operator*()->flow_ += flow;
                                return flow;
                            }
                        }
                        itVertexes.operator*()->edgesForward_.pushBack(
                                std::make_shared<Edge>(itEdges.operator*()->finish_, itEdges.operator*()->start_,
                                                       itEdges.operator*()->capacity_, itEdges.operator*()->capacity_ - flow));
                        return flow;
                    }
                    break;
                }
            }
        }
    }
    return 0;
}





