#include <iostream>

#include "headers/Flights/FlightsGraph.h"

int main() {
    FlightsGraph flights;
    std::wstring city1;
    std::wstring city2;

    std::cout << "Input first city ";
    std::wcin >> city1;
    std::cout << "Input second city ";
    std::wcin >> city2;

    std::cout << flights.calculatePath(city1,city2) << std::endl;
    return 0;
}
