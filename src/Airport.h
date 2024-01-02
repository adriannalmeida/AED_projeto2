#ifndef INC_2PROJETO_AIRPORT_H
#define INC_2PROJETO_AIRPORT_H

#include <iostream>
#include "Country.h"
#include "Coordinates.h"
using namespace std;

class Airport {

    string code;
    string name;
    Country country;
    Coordinates coordinates;

public:
    Airport(string code, string name, Country country, Coordinates coordinates);
    string getCode();
    string getName();
    Country getCountry();
    Coordinates getCoordinates();
    bool operator==(const Airport& other) const;
    bool operator < (const Airport &other) const;

};


#endif //INC_2PROJETO_AIRPORT_H
