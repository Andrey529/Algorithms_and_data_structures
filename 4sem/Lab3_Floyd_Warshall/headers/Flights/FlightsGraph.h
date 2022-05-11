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
    explicit FlightsGraph(
            const std::string &pathForInputFile = "/home/andrey/Projects/Algorithms_and_data_structures/4sem/Lab3_Floyd_Warshall/flights.txt")
            :
            pathForInputFile_(pathForInputFile), flightsList_() {}

    explicit FlightsGraph(
            std::string &&pathForInputFile = "/home/andrey/Projects/Algorithms_and_data_structures/4sem/Lab3_Floyd_Warshall/flights.txt")
            :
            pathForInputFile_(pathForInputFile), flightsList_() {}


};




#endif //LAB3_FLOYD_WARSHALL_FLIGHTSGRAPH_H
