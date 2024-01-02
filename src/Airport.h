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
    /**
     * @brief Constructor for the Airport class.
     * Complexity: O(1)
     * Initializes an Airport object with the specified parameters.
     *
     * @param code Airport code.
     * @param name Airport name.
     * @param country The object Country associated to the airport.
     * @param coordinates The object Coordinates associated to the airport.
     */
    Airport(string code, string name, Country country, Coordinates coordinates);
    /**
     * @brief Getter function for the code of the airport.
     * Complexity: O(1)
     * @return std::string.
     */
    string getCode();
    /**
     * @brief Getter function for the name of the airport.
     *  Complexity: O(1)
     * @return std::string.
     */
    string getName();
    /**
     * @brief Getter function for the Country object of the airport.
     *  Complexity: O(1)
     * @return Country.
     */
    Country getCountry();
    /**
     * @brief Getter function for the Coordinates object of the airport.
     *  Complexity: O(1)
     * @return Coordinates.
     */
    Coordinates getCoordinates();
    /**
     * @brief Overloaded equality operator.
     * Complexity: O(1)
     * @param other The other Airport object to compare.
     * @return True if the airports are equal, false otherwise.
     */
    bool operator==(const Airport& other) const;
    /**
     * @brief Overloaded less-than operator.
     * Complexity: O(1)
     * @param other The other Airport object to compare.
     * @return True if this airport's name is less than the other, false otherwise.
     */
    bool operator < (const Airport &other) const;

};


#endif //INC_2PROJETO_AIRPORT_H
