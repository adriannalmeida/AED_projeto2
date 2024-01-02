#ifndef INC_2PROJETO_AIRLINE_H
#define INC_2PROJETO_AIRLINE_H

#include <iostream>
#include <string>
using namespace std;
class Airline {
private:
    string code;
    string name;
    string callSign;
    string countryName;

public:
    /**
     * @brief Default constructor for the Airline class.
     *
     * Initializes an empty Airline object.
     */
    Airline();
    /**
   * @brief Parameterized constructor for the Airline class.
   * Complexity: O(1)
   *
   * Initializes an Airline object with the specified parameters.
   *
   * @param code The code of the airline.
   * @param name The name of the airline.
   * @param callSign The call sign of the airline.
   * @param countryName The country name of the airline.
   */
    Airline(string code, string name, string callSign, string countryName);
    /**
     * @brief Getter function for the code of the airline.
     * Complexity: O(1)
     * @return std::string.
     */
    string getCode();
    /**
     * @brief Getter function for the name of the airline.
     * Complexity: O(1)
     * @return std::string.
     */
    string getName();
    /**
        * @brief Gettter function for the Callsign
        * Complexity: O(1)
        *
        * @return std::string
        */
    string getCallSign();
    /**
   * @brief Getter function for the country name of the airline.
   * Complexity: O(1)
   * @return std::string.
   */
    string getcountryName();

};

#endif //INC_2PROJETO_AIRLINE_H
