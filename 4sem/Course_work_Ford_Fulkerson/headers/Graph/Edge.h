#ifndef COURSE_WORK_FORD_FULKERSON_EDGE_H
#define COURSE_WORK_FORD_FULKERSON_EDGE_H

#include <string>

struct Edge {
    std::string start_;
    std::string finish_;
    size_t capacity_;

    Edge() : start_(), finish_(), capacity_{} {}
    Edge(const std::string &start, const std::string &finish, const size_t &capacity) : start_(start),
                                                                                        finish_(finish),
                                                                                        capacity_(capacity) {}

    Edge(std::string &&start, std::string &&finish, const size_t &capacity) : start_(std::move(start)),
                                                                              finish_(std::move(finish)),
                                                                              capacity_(capacity) {}

    Edge(const Edge &other) : start_(other.start_), finish_(other.finish_), capacity_(other.capacity_) {}
    Edge(Edge &&other)  noexcept : start_(std::move(other.start_)), finish_(std::move(other.finish_)), capacity_(other.capacity_) {}

    Edge& operator=(const Edge &other) & {
        if (this == &other) {
            return *this;
        }
        start_ = other.start_;
        finish_ = other.finish_;
        capacity_ = other.capacity_;
        return *this;
    }
    Edge& operator=(Edge &&other) & noexcept {
        if (this == &other) {
            return *this;
        }
        start_ = std::move(other.start_);
        finish_ = std::move(other.finish_);
        capacity_ = other.capacity_;
        return *this;
    }

    bool operator==(const Edge& other) const {
        if (start_ == other.start_ && finish_ == other.finish_ && capacity_ == other.capacity_) {
            return true;
        } else return false;
    }

    bool operator!=(const Edge& other) const {
        if (start_ != other.start_ && finish_ != other.finish_ && capacity_ != other.capacity_) {
            return true;
        } else return false;
    }

    friend std::ostream& operator<< (std::ostream &out, const Edge &edge) {
        out << edge.start_ << ' ' << edge.finish_ << ' ' << edge.capacity_ << std::endl;
        return out;
    }

};


#endif //COURSE_WORK_FORD_FULKERSON_EDGE_H
