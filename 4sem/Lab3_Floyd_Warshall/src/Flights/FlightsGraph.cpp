#ifndef LAB3_FLOYD_WARSHALL_FLIGHTSGRAPH_CPP
#define LAB3_FLOYD_WARSHALL_FLIGHTSGRAPH_CPP

#include "../../headers/Flights/FlightsGraph.h"

void FlightsGraph::process() {
    parseFile();
    searchUniqueCityies();
    configStartMatrix();
    algorithm();
}

void FlightsGraph::parseFile() {

    setlocale(LC_ALL, "ru_RU.UTF-8");
    std::wfstream f;
    f.open(pathForInputFile_, std::ios::in);
    if (f.bad()) {
        throw Exception("Bad file", 2);
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
            flight.setFirstFlight(INT32_MAX / 3 * 2);
        } else {
            flight.setFirstFlight(std::stoi(firstFlight));
        }
        if (secondFlight == "N/A") {
            flight.setSecondFlight(INT32_MAX / 3 * 2);
        } else {
            flight.setSecondFlight(std::stoi(secondFlight));
        }
        flightsList_.pushBack(flight);
        if (f.eof()) break;
    }

    f.close();
}

void FlightsGraph::searchUniqueCityies() {
    for (auto it = flightsList_.begin(); it != flightsList_.end(); ++it) {
        if (!uniqueCities_.contains(it.operator*().getDeparture())) {
            uniqueCities_.pushBack(it.operator*().getDeparture());
        }
        if (!uniqueCities_.contains(it.operator*().getArrival())) {
            uniqueCities_.pushBack(it.operator*().getArrival());
        }
    }
}

void FlightsGraph::configStartMatrix() {
    for (int i = 0; i < uniqueCities_.getSize(); ++i) {
        matrix_.pushBack(List<int>());
        for (int j = 0; j < uniqueCities_.getSize(); ++j) {
            matrix_.at(i).pushBack(INT32_MAX / 3 * 2);
        }
    }

    for (int i = 0; i < matrix_.getSize(); ++i) {
        for (int j = 0; j < matrix_.at(i).getSize(); ++j) {

            if (i == j) {
                matrix_.at(i).at(j) = 0;
            } else {
                for (auto itFlights = flightsList_.begin(); itFlights != flightsList_.end(); ++itFlights) {
                    if ((*itFlights).getDeparture() == uniqueCities_.at(i) &&
                        (*itFlights).getArrival() == uniqueCities_.at(j)) {
                        matrix_.at(j).at(i) = itFlights.operator*().getFirstFlight();
                        matrix_.at(i).at(j) = itFlights.operator*().getSecondFlight();
                    }

                }
            }
        }
    }
}

void FlightsGraph::algorithm() {
    for (int k = 0; k < uniqueCities_.getSize(); k++) {
        for (int i = 0; i < uniqueCities_.getSize(); i++) {
            for (int j = 0; j < uniqueCities_.getSize(); j++) {
                matrix_.at(j).at(i) = std::min(matrix_.at(j).at(i), matrix_.at(j).at(k) + matrix_.at(k).at(i));
            }
        }
    }
}

int FlightsGraph::calculatePath(const std::wstring &city1, const std::wstring &city2) {
    for (int i = 0; i < uniqueCities_.getSize(); i++) {
        for (int j = 0; j < uniqueCities_.getSize(); j++) {
            if (city1 == uniqueCities_.at(i) && city2 == uniqueCities_.at(j)) {
                auto result = matrix_.at(j).at(i);
                if (result == INT32_MAX / 3 * 2) {
                    return INT32_MAX;
                } else {
                    return result;
                }
            }
        }
    }
    throw Exception("No given path", 1);
}

#endif //LAB3_FLOYD_WARSHALL_FLIGHTSGRAPH_CPP
