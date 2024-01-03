#ifndef INC_2PROJETO_MENU_H
#define INC_2PROJETO_MENU_H

#include <iostream>
#include "DataParser.h"
#include <vector>
#include <set>
#include <unordered_map>
#include <unistd.h>
#include <termios.h>
#include <algorithm>
#include <unordered_set>
#include <cmath>
#include <cctype>
#include <iomanip>
using namespace std;

class menu {
    Graph<Airport> Travels;
    unordered_map<string, Airline *> airlines;
    unordered_map<string, Airport*> airports;
    public:
    menu();
    /**
     * @brief void function to process data.
     *
     * This function initializes a DataParser with a dataset, reads data, and sets member variables.
     * It then calls the mainMenu function to interact with the processed data.
     *
     * Complexity: Will depend on the complexity of the read() member function of the class DataParser,
     * so it will have the complexity of readFlights(), O(N*A) where A is the number of airports and N the number of flights
     */
    void run();

    /**
     * @brief function that waits for user input to continue.
     * Complexity: O(1)
     * This function displays a message, waits for the user to press ENTER, and then calls the mainMenu function.
     *
     */
    void wait();

    /**
    * @brief function that displays the main menu and the handles user selection.
    * Complexity: depends on the complexity of the actions performed in the switch cases
    */
    void mainMenu();

    /**
     * @brief function that displays the statistics menu and handles the user selection
     *
     * Complexity: depends on the complexity of the actions performed in the switch cases
     */
    void menuStatistics();

    /**
    * @brief function that displays the Airport statistics menu and handles the user selection
    *
    * Complexity: depends on the complexity of the actions performed in the switch cases
    */
    void menuAirportStatistics();

    /**
    * @brief function that displays the Destination menu and handles the user selection
    *
    * Complexity: depends on the complexity of the actions performed in the switch cases
    */
    void menuDestination();

    /**
    * @brief function that displays the Flight statistics menu and handles the user selection
    *
    * Complexity: depends on the complexity of the actions performed in the switch cases
    */
    void menuFlightStatistics();

    /**
    * @brief function that displays the Airports menu and handles the user selection
    *
    * Complexity: depends on the complexity of the actions performed in the switch cases
    */
    void menuAirports();

    /**
    * @brief function that displays the Source Airports sub menu and handles the user selection
    *
    * Complexity: depends on the complexity of the actions performed in the switch cases
    */
    vector<Airport*> SelectAirportSrc();

    /**
    * @brief function that displays the Destination Airports sub menu and handles the user selection
    *
    * Complexity: depends on the complexity of the actions performed in the switch cases
    */
    vector<Airport*> SelectAirportDest();

    /**
    * @brief function that calculates the total number of airports in the network.
    * Complexity: O(N)
    * This function calculates and returns the total number of airports in the network by iterating through
    * the vertices of the airport graph.
    *
    * @return int
    */
    int NumberofAirports();

    /**
    * @brief function that calculates the set of different countries to which the airport has flights.
    * Complexity: O(N)
    * This function returns a set of country names representing the different countries to which the given airport
    * has flights. It iterates through the adjacent airports of the specified airport and collects unique country names.
    *
    * @param airport The airport for which to find the destination countries.
    * @return set<string>
    */
    set<string> DifferentFlightsto(Airport& airport);

    /**
    * @brief Function that display the top airports based on their traffic capacity.
    * Complexity: O(N +(N*E)) where E is the number of edges and N the number of vertices
     *
    * This function calculates and displays the top N airports based on their traffic capacity.
    * The traffic capacity of an airport is determined by the total number of incoming and outgoing flights.
    *
    * @param n The number of top airports to display.
    */
    void TopAirportsintrafficcapacity(int n);

    /**
    * @brief Calculate and display the total number of flights in the network.
    * Complexity: O(N * E), where N is the number of vertices and E the number of edges
    * This function traverses the graph and counts the total number of flights present in the network.
    * It then displays the count to the console.
    *
    * @return int
    */
    int NumberofFlights();

    /**
    * @brief function that calculate and displays the number of flights departing from a specific airport.
    * Complexity O(N)
    * This function takes an airport as input and counts the number of flights departing from that airport.
    * It then displays the count to the console.
    *
    * @param airport The airport for which the number of departing flights is to be calculated.
    * @param[out] airlinesCount Reference to an integer variable to store the count of associated airlines.
    *
    * @return int
    */
    int FlightsoutofAirport(Airport& Flightsout, int& airlines);

    /**
    * @brief function that displays a menu with a list of options and highlight the selected option.
    * Complexity O(N)
    * This function takes a vector of strings representing menu options, the size of the menu, the index of the selected option,
    * and the name of the menu. It then formats and prints the menu to the console, highlighting the selected option.
    *
    * @param options A vector of strings representing menu options.
    * @param size The number of options in the menu.
    * @param select The index of the selected option to be highlighted.
    * @param menuName The name of the menu to be displayed at the top.
    */
    void printMenu(vector<string> options, int size, int select, string menuName);
    /**
    * @brief auxiliary function to print an interactive menu and handle user input.
    * Complexity O(N)
     *
    * This function displays a menu with the provided options and allows the user to navigate
    * through the options using arrow keys. It continuously listens for user input until the Enter
    * key is pressed. The selected option is updated in the 'select' parameter.
    *
    * @param options A vector of strings representing the menu options.
    * @param size The number of options in the menu.
    * @param select A reference to the variable storing the index of the currently selected option.
    * @param menuName The name of the menu to be displayed.
    */
    void auxprintMenu(vector<string> options, int & size, int &select, string menuName);

    /**
    * @brief function that sets non-blocking entrance mode for terminal input.
    *
    * This function configures the terminal to enable non-blocking entrance mode
    * for keyboard input. It turns off canonical mode and echo to allow immediate
    * processing of single characters without waiting for Enter.
    *
    * Complexity: O(1), it involves terminal configuration operations.
    */
    void nonBlockingEntrance();

    /**
     * @brief function that restore normal entrance mode for terminal input.
     *
     *Complexity: O(1), it involves terminal configuration operations.
     *
     * This function restores the terminal to normal entrance mode by turning on
     * canonical mode and echo for keyboard input.
     */
    void restoreEntrace();
    /**
    * @brief function that calculates the total number of flights related to a specific city.
    * Complexity O(N +E) where E is the number of Edges and N the number of vertices.
    *
    * This function counts the number of flights involving the specified city. It considers both
    * incoming and outgoing flights from airports located in the given city.
    *
    * @param city The name of the city for which the flight count is calculated.
    *
    * @return int.
    */
    int NumberofFlightspercity(string city);

    /**
    * @brief function that calculates the total number of flights operated by a specific airline.
    * Complexity O(N +E) where E is the number of Edges and N the number of vertices.
    *
    * This function counts the number of flights operated by the specified airline across
    * all airports in the network.
    *
    * @param air The airline code for which the flight count is calculated.
    *
    * @return int
    */
    int NumberofFlightsperairline(string air);

    /**
    * @brief function that calculates the total number of flights operated by a specific airline to or from a given city.
    * Complexity O(N +E) where E is the number of Edges and N the number of vertices.
    *
    * This function counts the number of flights operated by the specified airline to or from the
    * specified city across all airports in the network.
    *
    * @param city The name of the city.
    * @param air The airline code for which the flight count is calculated.
    *
    * @return int
    */
    int NumberofFlightsperCityandAir(string city, string air);

    /**
    * @brief function that searchs for direct flights from a specified airport and display reachable destinations.
    * Complexity O(E * log(V)) where E is the number of edges and V the number of vertices of the graph
    * This function allows the user to select a specific airport and then choose the criteria (countries, cities, or airports)
    * for searching reachable destinations with direct flights. The function then displays the total number of reachable destinations
    * and optionally provides a full list based on user input.
    *
    * @param select The user's choice of criteria for searching destinations.
    */
    void directFlights();

    /**
    * @brief function that calculates the number of airports reachable from a specified airport within a certain number of stops.
    * Complexity O(N * E) where E is the number of Edges and N the number of vertices.
    * This recursive function calculates the number of airports that can be reached from a specified airport within a certain
    * number of stops. It uses a depth-first search approach to explore adjacent airports and count unique destinations.
    * The function involves traversing the graph using depth-first search (DFS) to explore adjacent vertices.
    *
    * @param airport The code of the starting airport.
    * @param stop The maximum number of stops allowed in the search.
    * @param airportGraph A graph to store visited airports and track unique destinations.
    * @return int
    */
    int NumberofStopsairports(string airport, int stop, Graph<Airport>& airportGraph);

    /**
    * @brief function that calculates the number of cities reachable from a specified airport within a certain number of stops.
    *Complexity O(N * E) where E is the number of Edges and N the number of vertices.

    * This recursive function calculates the number of cities that can be reached from a specified airport within a certain
    * number of stops. It uses a depth-first search (DFS) approach to explore adjacent airports and count unique destination cities.
    * @param airport The code of the starting airport.
    * @param stop The maximum number of stops allowed in the search.
    * @param airportGraph A graph to store visited airports and track unique destinations.
    * @param visitedCities An unordered set to keep track of visited city names.
    * @return int
    */
    int NumberofStopscities(string airport, int stop, Graph<Airport>& airportGraph, unordered_set<string>& visitedCities);

    /**
    * @brief function that calculates the number of countries reachable from a specified airport within a certain number of stops.
    * Complexity O(N * E) where E is the number of Edges and N the number of vertices.
    * This recursive function calculates the number of countries that can be reached from a specified airport within a certain
    * number of stops. It uses a depth-first search (DFS) approach to explore adjacent airports and count unique destination countries.
    *
    * @param airport The code of the starting airport.
    * @param stop The maximum number of stops allowed in the search.
    * @param airportGraph A graph to store visited airports and track unique destinations.
    * @param visitedCountries An unordered set to keep track of visited country names.
    * @return int
    */
    int NumberofStopscountries(string airport, int stop, Graph<Airport>& airportGraph, unordered_set<string>& visitedCountries);

    /**
    * @brief function that finds the trip with the maximum number of stops from a specified airport.
    * Complexity: O(N + E), where E is the number of Edges and N the number of vertices
    * This function performs a breadth-first search (BFS) to find the trip with the maximum number of stops from a specified airport.
    * It calculates the maximum stops required to reach any airport within the network from the given starting airport.
    *
    * The function involves a breadth-first search (BFS) on the graph to find the maximum number of stops.
     */
    void findMaxStopsTrip();

    /**
    * @brief function that finds articulation points in the airport network.
    * Complexity: O(N + E), where E is the number of Edges and N the number of vertices
    * This function identifies articulation points in the airport network, considering the airports as vertices in an undirected graph.
    * An articulation point is a vertex whose removal increases the number of connected components in the graph.
    * The function uses a depth-first search (DFS) to find articulation points in the undirected graph representation.
    *
    * @return vector<Airport>
    */
    vector<Airport> articulationPoints();

    /**
    * @brief Helper function for finding articulation points in the airport network.
    *
    * This function is a recursive helper for the articulationPoints function. It performs a depth-first search (DFS) to find articulation points
    * in the undirected graph representation of the airport network.
    *
    * @param v The current vertex being processed.
    * @param articulation A vector to store the identified articulation points.
    * @param dTime The current discovery time during the DFS.
    */
    void auxArticulationPoints(Vertex<Airport> *v, vector<Airport> & articulation,int dTime) const;
    void aux(Vertex<Airport> *v, vector<Airport> & articulation,int dTime) const;

    /**
    * @brief Helper function to find trips with the maximum number of stops in the airport network.
    * Complexity: O(N + E), where E is the number of Edges and N the number of vertices
    * This function is a recursive helper used to find trips with the maximum number of stops in the airport network.
    * It explores all possible flights from the current airport, avoiding revisiting already visited airports in the current trip.
    * The maximum number of stops and the current trip information are updated accordingly.
    *
     * @param currentAirport The current airport being processed.
     * @param maxStops Reference to the maximum number of stops in the trips.
     * @param currentTrip Reference to the vector storing the current trip information.
    * @param printedTrips A set to store unique trip pairs that have been printed.
    * @param visitedAirports An unordered set to keep track of visited airports in the current trip.
    */
    void findMaxStopsTripHelper(Vertex<Airport> *currentAirport, int &maxStops, vector<pair<string, string>> &currentTrip, set<pair<string, string>> &printedTrips, unordered_set<string> &visitedAirports);
    /**
    * @brief function that finds an airport based on its name.
    * Complexity: O(N)
    * This function searches for an airport in the airport network using its name.
    * If the airport is found, a pointer to the corresponding Airport object is returned.
    * If the airport is not found, a null pointer is returned.
    *
    * @param airport The name of the airport to search for.
    * @return Airport*.
     */
    Airport* UsingAirport(string airport);

    /**
    * @brief function that finds airports based on the city they are located in.
    * Complexity: O(N)
    * This function searches for airports in the airport network based on the specified city.
    * It returns a vector of pointers to Airport objects that are located in the given city.
    *
    * @param city The name of the city to search for.
    * @return A vector of pointers to Airport objects in the specified city.
    *
    * @complexity The time complexity is O(V), where V is the number of vertices (airports) in the network.
    */
    vector<Airport*> UsingCity(const string& city);

    /**
    * @brief function that finds airports based on geographic coordinates.
    * Complexity: O(N)
    * This function searches for airports in the airport network based on the specified latitude and longitude.
    * It calculates the Haversine Distance between the given coordinates and the coordinates of each airport
    * to determine proximity. Airports within a certain threshold distance are included in the result.
    *
    * @param latitude The latitude of the target location.
    * @param longitude The longitude of the target location.
    * @return A vector of pointers to Airport objects within the specified proximity.
    */
    vector<Airport*> UsingLocation(double latitude, double longitude);

    /**
    * @brief Find the best flight options between specified source and destination airports.
    *
    * This function searches for the best flight options between a set of source airports and a set of destination airports.
    * It considers the minimum number of stops required for each possible trip and identifies paths with the fewest stops.
    * The result is a set of all optimal paths with the same minimum number of stops.
    *
    * @param srcAirports A vector of pointers to source airports.
    * @param destAirports A vector of pointers to destination airports.
     */
    void findBestFlightOption(const vector<Airport*>& srcAirports, const vector<Airport*>& destAirports);

    /**
    * @brief function that finds the best flight options between specified source and destination airports with filtering by airline.
    * This function searches for the best flight options between a set of source airports and a set of destination airports,
    * considering the minimum number of stops required for each possible trip. Additionally, it allows filtering the results
    * based on a specified airline. The result is a set of all optimal paths with the same minimum number of stops, meeting the
    * airline filtering criteria.
    *
    * @param srcAirports A vector of pointers to source airports.
    * @param destAirports A vector of pointers to destination airports.
    * @param airline A pointer to the airline used for filtering the results. Pass nullptr to disable airline filtering.
    */
    void findBestFlightOptionWithFilters(const vector<Airport*>& srcAirports, const vector<Airport*>& destAirports, Airline* airline);

    /**
    * @brief function that finds all paths with the minimum number of stops between a source and destination airport.
    * Complexity: O(N + E), where E is the number of Edges and N the number of vertices
    * This function explores all paths between a source airport and a destination airport in the airport network,
    * considering the minimum number of stops required for each path. It utilizes a depth-first search algorithm with
    * a stack to traverse the graph and identify all paths with the same minimum number of stops.
    *
    * @param src A pointer to the source airport.
    * @param dest A pointer to the destination airport.
    *
    * @return A vector of vectors, where each inner vector represents a path (sequence of vertices) from the source to the destination.
    */
    vector<vector<Vertex<Airport>*>> findMinStopsTripHelper(Airport* src, Airport* dest);

    /**
    * @brief function that prints the best flight options based on a set of paths between source and destination airports.
    *
    * This function takes a set of paths between source and destination airports and prints the corresponding flight options,
    * including source and destination codes and the associated airline codes. It extracts information from the airport network,
    * such as airline details, to provide a clear display of the best flight options.
    *
    * @param bestPaths A set of vectors, where each vector represents a path (sequence of vertices) between source and destination airports.
    */
    void printBestFlights(const set<vector<Vertex<Airport>*>>& bestPaths) const;

    /**
    * @brief function that prints the best flight options based on a set of paths between source and destination airports, filtered by airline.
    *
    * This function takes a set of paths between source and destination airports, filters the options based on a specified airline,
    * and prints the corresponding flight options. It extracts information from the airport network, such as airline details, to provide
    * a clear display of the best flight options meeting the specified criteria.
    *
    * @param bestPaths A set of vectors, where each vector represents a path (sequence of vertices) between source and destination airports.
    * @param airline The airline object used as a filter. Only paths with segments operated by this airline are considered.
    */
    void printBestFlightsWithFilters(const set<vector<Vertex<Airport>*>>& bestPaths, Airline* airline) const;

    /**
    * @brief function that calculates the Haversine distance between two geographical points specified by latitude and longitude.
    * Complexity O(1)
    * The Haversine formula is used to calculate the shortest distance between two points on a sphere, given their latitudinal and longitudinal coordinates.
    *
    * @param lat1 Latitude of the first point in degrees.
    * @param lon1 Longitude of the first point in degrees.
    * @param lat2 Latitude of the second point in degrees.
    * @param lon2 Longitude of the second point in degrees.
    * @return double
    */
    double haversineDistance(double lat1, double lon1, double lat2, double lon2);

    /**
   * @brief compares distances of two vertices.
   * @param lhs The left-hand side vertex.
   * @param rhs The right-hand side vertex.
   * @return True if the distance of lhs is greater than the distance of rhs; otherwise, false.
   */
    template<typename T>
    struct CompareDist {
        bool operator()(const Vertex<T>* lhs, const Vertex<T>* rhs) const {
            return lhs->getDistance() > rhs->getDistance();
        }
    };

    /**
    * @brief function that creates an undirected graph based on the existing graph of airport travels.
    * Complexity: O(N)
    * The function creates a new undirected graph by duplicating the existing graph of airport travels and ensuring that each directed edge is represented as an undirected edge.
    *
    * @return An undirected graph based on the existing graph of airport travels.
    */
    Graph<Airport> undirectedGraph();
};


#endif //INC_2PROJETO_MENU_H
