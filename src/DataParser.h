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
/**
 * @brief The DataParser class is responsible for parsing and managing airport, airline, and flight data.
 *
 * This class reads data from CSV files and populates a graph with airports and flights.
 */
class DataParser {
    Graph<Airport> Travels;
    std::string path;
    unordered_map<string, Airline *> airlines;
    unordered_map<string, Airport*> airports;
public:

    /**
     * @brief Constructor for the DataParser class.
     * Complexity: O(1)
     * Initializes a DataParser object with the specified path to CSV files.
     * @param path The path to the directory containing CSV files.
     */
    DataParser(std::string path);

    /**
     * @brief Reads all data (airports, airlines, and flights) from the CSV files.
     * Complexity: has the complexity of readFlights function has that is with higher complexity.
     */
    void read();
    /**
     * @brief Reads airport data from the "airports.csv" file and populates the graph.
     * Complexity: O(N)
     */
    void readAirports();
    /**
     * @brief Reads airline data from the "airlines.csv" file.
     * Complexity: O(N)
     */
    void readAirlines();
    /**
   * @brief Reads flight data from the "flights.csv" file and populates the graph.
   * Complexity: in the worst case, the function has a time complexity of O(N*A) where A is the number of Airports
   */
    void readFlights();
    /**
     * @brief Getter function for the Travels graph.
     * Complexity: O(N)
     * @return Graph<Airport>
     */
    Graph<Airport> getTravels();
    /**
     * @brief Getter function for the airlines hash table.
     * @return unordered_map<string, Airline *>
     */
    unordered_map<string, Airline *> getAirlines();
    /**
     * @brief Getter function for the Airports hash table.
     * @return unordered_map<string, Airport*>
     */
    unordered_map<string, Airport*> getAirports();
};


#endif //INC_2PROJETO_DATAPARSER_H