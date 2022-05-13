#ifndef LAB3_FLOYD_WARSHALL_FLIGHTSGRAPH_H
#define LAB3_FLOYD_WARSHALL_FLIGHTSGRAPH_H

#include <fstream>
#include <limits>

#include "Flight.h"
#include "../List/List.h"
#include "../Exceptions/Exceptions.h"


class FlightsGraph {
private:
    std::string pathForInputFile_;
    List<Flight> flightsList_;
    List<std::wstring> uniqueCities_;
    List<List<int>> matrix_;

    void process();
    void parseFile();
    void searchUniqueCityies();
    void configStartMatrix();
    void algorithm();
public:
    FlightsGraph() :
            pathForInputFile_(
                    "/home/andrey/Projects/Algorithms_and_data_structures/4sem/Lab3_Floyd_Warshall/flights.txt") {
        process();
    }

    explicit FlightsGraph(const std::string &pathForInputFile) :
            pathForInputFile_(pathForInputFile) {
        process();
    }

    explicit FlightsGraph(std::string &&pathForInputFile) :
            pathForInputFile_(pathForInputFile) {
        process();
    }

    List<Flight> &getListFlights() { return flightsList_; }
    int calculatePath(const std::wstring &city1, const std::wstring &city2);
};


#endif //LAB3_FLOYD_WARSHALL_FLIGHTSGRAPH_H
