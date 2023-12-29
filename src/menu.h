#ifndef INC_2PROJETO_MENU_H
#define INC_2PROJETO_MENU_H

#include <iostream>
#include "DataParser.h"
#include <vector>
#include <set>
#include <unordered_set>
#include <unistd.h>
#include <termios.h>
#include <unordered_set>
using namespace std;

class menu {
    Graph<Airport> Travels;
    unordered_map<string, Airline *> airlines;
    unordered_map<string, Airport*> airports;
    public:
    menu();
    void run();
    void wait();
    void mainMenu();
    void menuStatistics();
    void menuAirportStatistics();
    void menuDestination();
    void menuFlightStatistics();
    void menuAirports();
    void EssencialAirports();
    int NumberofAirports();
    int DifferentFlightsto(Airport& airport);
    void TopAirportsintrafficcapacity(int n);
    int NumberofFlights();
    int FlightsoutofAirport(Airport& Flightsout, int& airlines);
    void printMenu(vector<string> options, int size, int select);
    void auxprintMenu(vector<string> options, int & size, int &select);
    void nonBlockingEntrance();
    void restoreEntrace();
    int NumberofFlightspercity(string city);
    int NumberofFlightsperairline(string air);
    int NumberofFlightsperCityandAir(string city, string air);
    int NumberofStopsairports(string airport, int stop, Graph<Airport>& airportGraph);
    int NumberofStopscities(string airport, int stop, Graph<Airport>& airportGraph, unordered_set<string>& visitedCities);
    int NumberofStopscountries(string airport, int stop, Graph<Airport>& airportGraph, unordered_set<string>& visitedCountries);
    void findMaxStopsTrip();
    void findMaxStopsTripHelper(Vertex<Airport> *currentAirport, int &maxStops, vector<pair<string, string>> &currentTrip, set<pair<string, string>> &printedTrips, unordered_set<string> &visitedAirports);
};


#endif //INC_2PROJETO_MENU_H
