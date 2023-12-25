#ifndef INC_2PROJETO_FLIGHTS_H
#define INC_2PROJETO_FLIGHTS_H

#include "Airline.h"
using namespace std;
class Flights {
private:
    string src;
    string dest;
    Airline airline;
public:
    Flights(string src, string dest, Airline airline);
    string getsrc();
    string getdest();
    Airline getAirline();
};


#endif //INC_2PROJETO_FLIGHTS_H
