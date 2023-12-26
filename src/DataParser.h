//
// Created by eloy_mm2004 on 25-12-2023.
//

#ifndef INC_2PROJETO_DATAPARSER_H
#define INC_2PROJETO_DATAPARSER_H


#include <string>
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
    map<string, Airline *> airlines;
    map<string, Airport*> airports;

    void readAirlines();
    /**
     * @brief This function reads the airports.csv file
     */
    void readAirports();
    /**
     * @brief This function reads the flights.csv file
     */
    void readFlights();
public:

    explicit DataParser(std::string path);

    Vertex<Airport> getAirport() const;

    Edge<Flights> getFlightsGraph() const;
};


#endif //INC_2PROJETO_DATAPARSER_H