//
// Created by adriana on 12/25/23.
//

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
    //ou faz se um construtor só com country name na classe country? ou fica string aqui
    string countryName;

public:
    Airline(string code, string name, string callSign, string countryName);
    string getCode();
    string getName();
    string getCallSign();
    string getcountryName();




};


#endif //INC_2PROJETO_AIRLINE_H
