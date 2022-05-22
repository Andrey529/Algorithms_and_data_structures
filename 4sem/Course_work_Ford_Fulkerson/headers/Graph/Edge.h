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

    friend std::ostream& operator<< (std::ostream &out, const Edge &edge) {
        out << edge.start_ << ' ' << edge.finish_ << ' ' << edge.capacity_ << std::endl;
    }

};


#endif //COURSE_WORK_FORD_FULKERSON_EDGE_H
