#ifndef COURSE_WORK_FORD_FULKERSON_VERTEX_H
#define COURSE_WORK_FORD_FULKERSON_VERTEX_H

#include <string>
#include "../List/List.h"
#include "Edge.h"

struct Vertex {
    std::string name_;
    List<std::shared_ptr<Edge>> edgesForward_;
    List<std::shared_ptr<Vertex>> vertexesForward_;

    Vertex() = default;
    ~Vertex() = default;

    explicit Vertex(const std::string &name) : name_(name) {}

    Vertex(const std::string &name, const List<std::shared_ptr<Edge>> &edgesForward,
           const List<std::shared_ptr<Vertex>> &vertexesForward)
            : name_(name), edgesForward_(edgesForward), vertexesForward_(vertexesForward) {}

    Vertex(const Vertex &other) : name_(other.name_), edgesForward_(other.edgesForward_),
                                  vertexesForward_(other.vertexesForward_) {}

    Vertex &operator=(const Vertex &other) &{
        if (this == &other) {
            return *this;
        }
        name_ = other.name_;
        edgesForward_ = other.edgesForward_;
        vertexesForward_ = other.vertexesForward_;
        return *this;
    }

    bool operator==(const Vertex &other) {
        if (name_ == other.name_ && edgesForward_ == other.edgesForward_ && vertexesForward_ == other.vertexesForward_) {
            return true;
        } else return false;
    }

    bool operator!=(const Vertex &other) {
        return !(*this == other);
    }

    void clear() {
        name_ = "";
        edgesForward_.clear();
        vertexesForward_.clear();
    }


};

#endif //COURSE_WORK_FORD_FULKERSON_VERTEX_H
