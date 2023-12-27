#ifndef INC_2PROJETO_DATAPARSER_H
#define INC_2PROJETO_DATAPARSER_H


#include <string>
#include <unordered_map>
#include <map>
#include "Graph.h"
#include "Airport.h"
#include "Flights.h"
#include "Airline.h"
#include "Country.h"
#include "Coordinates.h"

class DataParser {
    Graph<Airport> Travels;
    std::string path;
    unordered_map<string, Airline *> airlines;
    unordered_map<string, Airport*> airports;


    /**
     * @brief This function reads the airports.csv file
     */

    /**
     * @brief This function reads the flights.csv file
     */

public:

    DataParser(std::string path);
    void read();
    void readAirports();
    void readAirlines();
    void readFlights();
    Vertex<Airport> getAirport();
    Edge<Flights> getFlightsGraph();
    Graph<Airport> getTravels();
    unordered_map<string, Airline *> getAirlines();
    unordered_map<string, Airport*> getAirports();
};


#endif //INC_2PROJETO_DATAPARSER_H