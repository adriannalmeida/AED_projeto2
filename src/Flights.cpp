#include "Flights.h"

// wtf parser
//Flights::Flights(std::string src, std::string dest, Airline airline): airline (airline) {
//master
Flights::Flights (std::string src, std::string dest, Airline airline) {
    this->src = src;
    this->dest = dest;
}

string Flights:: getsrc(){
    return this->src;
}
string Flights:: getdest(){
    return this-> dest;
}
Airline Flights:: getAirline(){
    return this->airline;
}
