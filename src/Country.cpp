#include "Country.h"

Country::Country() {}
Country:: Country(string countryName, string city){
    this->countryName = countryName;
    this-> city = city;
}

string Country:: getCountryName(){
    return this->countryName;
}

string Country:: getCity(){
    return this->city;
}

