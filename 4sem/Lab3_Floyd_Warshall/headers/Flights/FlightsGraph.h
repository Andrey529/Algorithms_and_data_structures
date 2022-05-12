#ifndef LAB3_FLOYD_WARSHALL_FLIGHTSGRAPH_H
#define LAB3_FLOYD_WARSHALL_FLIGHTSGRAPH_H

#include <fstream>

#include "Flight.h"
#include "../List/List.h"
#include "../Exceptions/Exceptions.h"

class FlightsGraph {
private:
    std::string pathForInputFile_;
    List<Flight> flightsList_;

    void parseFile();

public:
    FlightsGraph() :
            pathForInputFile_(
                    "/home/andrey/Projects/Algorithms_and_data_structures/4sem/Lab3_Floyd_Warshall/flights.txt"),
            flightsList_() {
        parseFile();
    }

    explicit FlightsGraph(const std::string &pathForInputFile) :
            pathForInputFile_(pathForInputFile), flightsList_() {
        parseFile();
    }

    explicit FlightsGraph(std::string &&pathForInputFile) :
            pathForInputFile_(pathForInputFile), flightsList_() {
        parseFile();
    }

    List<Flight> &getListFlights() { return flightsList_; }
};


#endif //LAB3_FLOYD_WARSHALL_FLIGHTSGRAPH_H
