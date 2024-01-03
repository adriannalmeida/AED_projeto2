#ifndef INC_2PROJETO_FLIGHTS_H
#define INC_2PROJETO_FLIGHTS_H

#include "Airline.h"
#include <string>
using namespace std;
class Flights {
private:
    string src;
    string dest;
    Airline airline;
public:
    /**
    * @brief Constructor for the Flights class.
    * Complexity: O(1)
    *
    * @param src Source airport code.
    * @param dest Destination airport code.
    * @param airline object Airline associated.
    */
    Flights(string src, string dest, Airline airline);

    /**
    * @brief Getter function for the source airport code.
     * Complexity: O(1)
    * @return std::string
    */
    string getsrc();
    /**
    * @brief Getter function for the source airport name.
     * Complexity: O(1)
    * @return std::string
    */
    string getdest();
    /**
    * @brief Getter function for the source airline.
     * Complexity: O(1)
    * @return Airline
    */
    Airline getAirline();
};


#endif //INC_2PROJETO_FLIGHTS_H
