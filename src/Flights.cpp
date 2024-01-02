#include "Flights.h"
Flights::Flights (std::string src, std::string dest, Airline airline) {
    this->src = src;
    this->dest = dest;
}

string Flights:: getsrc() const {
    return this->src;
}
string Flights:: getdest() const {
    return this-> dest;
}
Airline Flights:: getAirline() const {
    return this->airline;
}
