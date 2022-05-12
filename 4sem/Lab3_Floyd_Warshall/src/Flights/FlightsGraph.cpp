#include "../../headers/Flights/FlightsGraph.h"

void FlightsGraph::parseFile() {

    setlocale(LC_ALL,"ru_RU.UTF-8");
    std::wfstream f;
    f.open(pathForInputFile_, std::ios::in);
    if (f.bad()) {
        throw std::runtime_error("Bad input file");
    }
    f.imbue(std::locale("ru_RU.UTF-8"));

    wchar_t symbol = '\0';
    while (true) {
        int countDelimeters = 0;
        auto flight = Flight();
        std::string firstFlight, secondFlight;
        while (true) {
            symbol = f.get();
            if (f.eof()) break;
            if (symbol == '\n') break;

            if (symbol == ';') {
                ++countDelimeters;
                continue;
            }

            if (countDelimeters == 0) {
                flight.getDeparture() += symbol;
            } else if (countDelimeters == 1) {
                flight.getArrival() += symbol;
            } else if (countDelimeters == 2) {
                firstFlight += symbol;
            } else {
                secondFlight += symbol;
            }

        }
        if (firstFlight == "N/A") {
            flight.setFirstFlight(-1);
        } else {
            flight.setFirstFlight(std::stoi(firstFlight));
        }
        if (secondFlight == "N/A") {
            flight.setSecondFlight(-1);
        } else {
            flight.setSecondFlight(std::stoi(secondFlight));
        }
        flightsList_.pushBack(flight);
        if (f.eof()) break;
    }
}