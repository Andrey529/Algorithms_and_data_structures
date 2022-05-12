#ifndef LAB3_FLOYD_WARSHALL_FLIGHT_H
#define LAB3_FLOYD_WARSHALL_FLIGHT_H

#include <string>

class Flight {
private:
    std::wstring departure_;
    std::wstring arrival_;
    double firstFlight_{};
    double secondFlight_{};
public:
    Flight() = default;

    Flight(const std::wstring &departure, const std::wstring &arrival, const double &firstFlight,
           const double &secondFlight)
            : departure_(departure), arrival_(arrival), firstFlight_(firstFlight), secondFlight_(secondFlight) { }

    Flight(std::wstring &&departure, std::wstring &&arrival, const double &firstFlight,
           const double &secondFlight)
            : departure_(std::move(departure)), arrival_(std::move(arrival)), firstFlight_(firstFlight), secondFlight_(secondFlight) { }


    std::wstring &getDeparture() { return departure_; }
    void setDeparture(const std::wstring &departure) { departure_ = departure; }
    std::wstring &getArrival() { return arrival_; }
    void setArrival(const std::wstring &arrival) { arrival_ = arrival; }
    double &getFirstFlight() { return firstFlight_; }
    void setFirstFlight(const double &firstFlight) { firstFlight_ = firstFlight; }
    double &getSecondFlight() { return secondFlight_; }
    void setSecondFlight(const double &secondFlight) { secondFlight_ = secondFlight; }
};

#endif //LAB3_FLOYD_WARSHALL_FLIGHT_H
