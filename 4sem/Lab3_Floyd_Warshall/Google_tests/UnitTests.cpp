#include "gtest/gtest.h"

#include "../headers/Flights/FlightsGraph.h"

TEST(algorithm, algorithm) {
    FlightsGraph graph("/home/andrey/Projects/Algorithms_and_data_structures/4sem/Lab3_Floyd_Warshall/Google_tests/flights.txt");

    auto listFlights = graph.getListFlights();
    ASSERT_EQ(10, graph.calculatePath(listFlights.at(0).getDeparture() , listFlights.at(0).getArrival()));
    ASSERT_EQ(20, graph.calculatePath(listFlights.at(0).getArrival() , listFlights.at(0).getDeparture()));
    ASSERT_EQ(34, graph.calculatePath(listFlights.at(1).getDeparture() , listFlights.at(1).getArrival()));
    ASSERT_EQ(35, graph.calculatePath(listFlights.at(1).getArrival() , listFlights.at(1).getDeparture()));
    ASSERT_EQ(14, graph.calculatePath(listFlights.at(2).getDeparture() , listFlights.at(2).getArrival()));
    ASSERT_EQ(55, graph.calculatePath(listFlights.at(2).getArrival() , listFlights.at(2).getDeparture()));
    ASSERT_EQ(13, graph.calculatePath(listFlights.at(3).getDeparture() , listFlights.at(3).getArrival()));
    ASSERT_EQ(8, graph.calculatePath(listFlights.at(3).getArrival() , listFlights.at(3).getDeparture()));
    ASSERT_EQ(68, graph.calculatePath(listFlights.at(4).getDeparture() , listFlights.at(4).getArrival()));
    ASSERT_EQ(20, graph.calculatePath(listFlights.at(4).getArrival() , listFlights.at(4).getDeparture()));
}