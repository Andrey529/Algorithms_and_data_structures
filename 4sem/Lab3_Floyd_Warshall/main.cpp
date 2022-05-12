#include <iostream>

#include "headers/Flights/FlightsGraph.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    FlightsGraph flights;
    List<Flight> list = flights.getListFlights();
//    std::wcout << list << std::endl;
    for (int i = 0; i < list.getSize(); ++i) {
        auto flight = list.at(i);
        std::wcout << flight.getDeparture() << ';' << flight.getArrival() << ';'
            << flight.getFirstFlight() << ';' << flight.getSecondFlight() << std::endl;
    }
    std::string str("впasfa");
    std::cout << str << std::endl;
    return 0;
}
