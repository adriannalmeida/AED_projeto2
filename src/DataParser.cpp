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

    unordered_map<string, Airport*> airportMap;
    unordered_map<string, Airline*> airlineMap;

    // Preencher os mapas de aeroportos e companhias aéreas
    for (const auto &airport : airports) {
        airportMap[airport.second->getCode()] = airport.second;
    }

    for (const auto &airline : airlines) {
        airlineMap[airline.second->getCode()] = airline.second;
    }

    while (getline(csv, line, '\n')) {
        stringstream tmp(line);
        string source, target, airline;

        getline(tmp, source, ',');
        getline(tmp, target, ',');
        getline(tmp, airline);

        Airport* src = airportMap[source];
        Airport* dest = airportMap[target];
        Airline* air = airlineMap[airline];

        double distance = 1;  // chamar função para calcular distância
        if (src && dest && air) {
            Travels.addEdge(*src, *dest, distance, *air);
        } else {
            cerr << "Error: Airport or Airline not found for a flight." << endl;
        }
    }
}

void DataParser:: read(){

    readAirports();
    readAirlines();
    readFlights();

}
Graph<Airport> DataParser::getTravels() {
    return Travels;
}
unordered_map<string, Airline *> DataParser::getAirlines() {
    return airlines;
}
unordered_map<string, Airport*> DataParser::getAirports() {
    return airports;
}