#ifndef LAB3_FLOYD_WARSHALL_FLIGHT_H
#define LAB3_FLOYD_WARSHALL_FLIGHT_H

#include <string>

class Flight {
private:
    std::string departure_;
    std::string arrival_;
    double firstFlight_{};
    double secondFlight_{};
public:
    Flight() = default;

    Flight(const std::string &departure, const std::string &arrival, const double &firstFlight,
           const double &secondFlight)
            : departure_(departure), arrival_(arrival), firstFlight_(firstFlight), secondFlight_(secondFlight) { }

    Flight(std::string &&departure, std::string &&arrival, const double &firstFlight,
           const double &secondFlight)
            : departure_(std::move(departure)), arrival_(std::move(arrival)), firstFlight_(firstFlight), secondFlight_(secondFlight) { }


    std::string &getDeparture() { return departure_; }
    void setDeparture(const std::string &departure) { departure_ = departure; }
    std::string &getArrival() { return arrival_; }
    void setArrival(const std::string &arrival) { arrival_ = arrival; }
    double &getFirstFlight() { return firstFlight_; }
    void setFirstFlight(const double &firstFlight) { firstFlight_ = firstFlight; }
    double &getSecondFlight() { return secondFlight_; }
    void setSecondFlight(const double &secondFlight) { secondFlight_ = secondFlight; }
};

#endif //LAB3_FLOYD_WARSHALL_FLIGHT_H
