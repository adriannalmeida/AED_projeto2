#include <fstream>
#include <sstream>
#include "DataParser.h"



DataParser::DataParser(std::string path) {
    this->path = path;
}

void DataParser::readAirports() {

    ifstream csv(path + "/airports.csv");
    if (!csv.is_open()) {
        cerr << "Error opening flights.csv" << endl;
        return;
    }
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
        //Vertex<Airport>* vertex = new Vertex<Airport>(airport);
        Travels.addVertex(airport);
        airports[code] = new Airport(code, name, country1, coordinates);
    }
}

void DataParser::readAirlines() {

    ifstream csv(path + "/airlines.csv");
    if (!csv.is_open()) {
        cerr << "Error opening flights.csv" << endl;
        return;
    }
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


void DataParser::readFlights() {

    ifstream csv(path + "/flights.csv");
    if (!csv.is_open()) {
        cerr << "Error opening flights.csv" << endl;
        return;
    }
    string line;
    getline(csv, line, '\n'); // Ignore Header

    while (getline(csv, line, '\n')) {

        string source, target, airline;
        stringstream tmp(line);

        getline(tmp, source, ',');
        getline(tmp, target, ',');
        getline(tmp, airline);

        Airport* src;
        Airport* dest;

        for(auto & airport : airports){
            if(airport.second->getCode() == source){
                src = airport.second;

            }
            if(airport.second->getCode() == target){
                dest = airport.second;
            }
        }
        Airline* air;
        for(auto & airline1 : airlines){
            if(airline1.second->getCode() == airline){
                 air = airline1.second;
            }
        }
        double distance = 1;
        //distance = chamar função para calcular distância
        Travels.addEdge(*src, *dest, distance,*air);
    }
}

void DataParser:: read(){

    readAirports();
    readAirlines();
    readFlights();
    cout << "HELP" << endl;

}
Graph<Airport> DataParser::getTravels() {
    return Travels;
}