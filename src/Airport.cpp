#include "Airport.h"

Airport::Airport(string code, string name, Country country,Coordinates coordinates)
        : coordinates(coordinates), country(country) {
    this->code = code;
    this->name = name;
}

string Airport::getCode() {
    return this-> code;
}
string Airport::getName() {
    return this-> name;
}

Country Airport::getCountry() {
    return this->country;
}

Coordinates Airport::getCoordinates() {
    return this->coordinates;
}

bool Airport::operator==(const Airport& other) const {
    return (code == other.code) && (name == other.name);
}

bool Airport::operator < (const Airport &other) const {
    if(name < other.name)
        return true;
    return false;
}
