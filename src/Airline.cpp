#include "Airline.h"

Airline::Airline(){}
Airline:: Airline (string code, string name, string callSign, string countryName){

    this->code = code;
    this->name = name;
    this->callSign = callSign;
    this->countryName = countryName;
}
string Airline:: getCode(){
    return this-> code;
}
string Airline:: getName(){
    return this-> name;
}
string Airline :: getCallSign(){
    return this-> callSign;
}
string Airline:: getcountryName(){
    return this->countryName;
}
