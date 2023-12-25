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
    Country(string countryName, string city);
    string getCountryName();
    string getCity();

};


#endif //INC_2PROJETO_COUNTRY_H
