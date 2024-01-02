#ifndef INC_2PROJETO_COORDINATES_H
#define INC_2PROJETO_COORDINATES_H

#include <iostream>
using namespace std;
class Coordinates {
private:
    double latitude;
    double longitude;
public:
    /**
    * @brief Default constructor for the Coordinates class.
    * Complexity: O(1)
    */
    Coordinates();
    /**
    * @brief Parameterized constructor for the Coordinates class.
    * Complexity: O(1)
    * Initializes a Coordinates object with the specified latitude and longitude values.
    * @param latitude The latitude value.
    * @param longitude The longitude value.
    */
    Coordinates(double latitude, double longitude);
    /**
     * @brief Getter function for the latitude value.
     * Complexity: O(1)
     * @return double.
     */
    double getLatitude();
    /**
     * @brief Getter function for the longitude value.
     * Complexity: O(1)
     * @return double.
     */
    double getLongitude();
};


#endif //INC_2PROJETO_COORDINATES_H
