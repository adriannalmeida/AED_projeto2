#ifndef INC_2PROJETO_COORDINATES_H
#define INC_2PROJETO_COORDINATES_H

#include <iostream>
using namespace std;
class Coordinates {
private:
    double latitude;
    double longitude;
public:
    Coordinates();
    Coordinates(double latitude, double longitude);
    double getLatitude();
    double getLongitude();
};


#endif //INC_2PROJETO_COORDINATES_H
