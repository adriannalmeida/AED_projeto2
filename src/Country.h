#ifndef INC_2PROJETO_COUNTRY_H
#define INC_2PROJETO_COUNTRY_H

#include <iostream>
#include <string>
using namespace std;
class Country {
private:
    string countryName;
    string city;
public:
    /**
    * @brief Default constructor for the Country class.
    * Complexity: O(1)
    */
    Country();
    /**
     * @brief Parameterized constructor for the Country class.
     * Complexity: O(1)
     * Initializes a Country object with the specified country name and city.
     *
     * @param countryName Name of the country.
     * @param city Name of the city.
     */
    Country(string countryName, string city);
    /**
     * @brief Getter function for the CountryName.
     * Complexity: O(1)
     * @return std::string.
     */
    string getCountryName();
    /**
     * @brief Getter function for the City.
     * Complexity: O(1)
     * @return std::string.
     */
    string getCity();

};


#endif //INC_2PROJETO_COUNTRY_H
