#include "Coordinates.h"

Coordinates::Coordinates() {}

Coordinates::Coordinates(double latitude, double longitude){
    this-> latitude = latitude;
    this-> longitude = longitude;
}

double Coordinates:: getLatitude(){
    return this->latitude;
}

double Coordinates:: getLongitude(){
    return this-> longitude;
}
