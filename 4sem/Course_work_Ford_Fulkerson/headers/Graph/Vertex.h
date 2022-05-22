#ifndef COURSE_WORK_FORD_FULKERSON_VERTEX_H
#define COURSE_WORK_FORD_FULKERSON_VERTEX_H

#include <string>
#include "../List/List.h"
#include "Edge.h"

struct Vertex {
    std::string name_;
    List<Edge> edgesForward_;
    List<Edge> edgesBack_;

    Vertex() = default;

    explicit Vertex(const std::string &name) : name_(name) {}

    Vertex(const std::string &name, const List<Edge> &edgesForward, const List<Edge> &edgesBack)
            : name_(name), edgesForward_(edgesForward), edgesBack_(edgesBack) {}

    Vertex(const Vertex &other) : name_(other.name_), edgesForward_(other.edgesForward_),
                                  edgesBack_(other.edgesBack_) {}

    Vertex(Vertex &&other)  noexcept : name_(std::move(other.name_)), edgesForward_(std::move(other.edgesForward_)),
                             edgesBack_(std::move(other.edgesBack_)) {}

    Vertex &operator=(const Vertex &other) &{
        if (this == &other) {
            return *this;
        }
        name_ = other.name_;
        edgesForward_ = other.edgesForward_;
        edgesBack_ = other.edgesBack_;
        return *this;
    }

    Vertex &operator=(Vertex &&other) & noexcept {
        if (this == &other) {
            return *this;
        }
        name_ = std::move(other.name_);
        edgesForward_ = std::move(other.edgesForward_);
        edgesBack_ = std::move(other.edgesBack_);
        return *this;
    }

    bool operator==(const Vertex& other) {
        if (name_ == other.name_ && edgesForward_ == other.edgesForward_ && edgesBack_ == other.edgesBack_) {
            return true;
        } else return false;
    }

};

#endif //COURSE_WORK_FORD_FULKERSON_VERTEX_H
