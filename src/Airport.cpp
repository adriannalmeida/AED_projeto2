#include "Airport.h"

Airport ::Airport(std::string code, std::string name, Country country, Coordinates coordinates) {
    this->code = code;
    this->name = name;
    this->country = country;
    this->coordinates = coordinates;
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


