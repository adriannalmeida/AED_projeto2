#include <fstream>
#include <sstream>
#include "DataParser.h"



DataParser::DataParser(std::string path) {
    this->path = path;
    readAirlines();
    readAirports();
    readFlights();
}


void DataParser::readAirlines() {

    ifstream csv(path + "/airlines.csv");
    string line;
    getline(csv, line, '\n'); // Ignore Header

    while (getline(csv, line, '\n')) {

        string code, name, callsign, country;
        stringstream tmp(line);

        getline(tmp, code, ',');
        getline(tmp, name, ',');
        getline(tmp, callsign, ',');
        getline(tmp, country);

        airlines[code] = new Airline(code, name, callsign, country);
    }
}
void DataParser::readAirports() {

    ifstream csv(path + "airports.csv");
    string line;
    getline(csv, line, '\n'); // Ignore Header

    while (getline(csv, line, '\n')) {

        string code, name, city, country, latitude, longitude;
        stringstream tmp(line);

        getline(tmp, code, ',');
        getline(tmp, name, ',');
        getline(tmp, city, ',');
        getline(tmp, country, ',');
        getline(tmp, latitude, ',');
        getline(tmp, longitude, ',');

        Coordinates coordinates(stod(latitude), stod(longitude));
        Country country1(country, city);
        Airport airport(code, name,country1, coordinates);
        Vertex<Airport>* vertex = new Vertex<Airport>(airport);
        Travels.setVertexSet(vertex);
        airports[code] = new Airport(code, name, country1, coordinates);
    }
}

void DataParser::readFlights() {

    ifstream csv(path + "flights.csv");
    string line;
    getline(csv, line, '\n'); // Ignore Header

    while (getline(csv, line, '\n')) {

        string source, target, airline;
        stringstream tmp(line);

        getline(tmp, source, ',');
        getline(tmp, target, ',');
        getline(tmp, airline);

        Airport* i;
        Airport* u;

        for(auto & airport : airports){
            if(airport.second->getCode() == source){
                i = airport.second;

            }
            if(airport.second->getCode() == target){
                u = airport.second;
            }
        }
        Airline* q;
        for(auto & airline1 : airlines){
            if(airline1.second->getCode() == airline){
                 q = airline1.second;
            }
        }

        Travels.addEdge(*i, *u, *q);
    }}