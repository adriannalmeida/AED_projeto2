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
#include <cctype>
#include <iomanip>
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
    void EssencialAirports();
    int NumberofAirports();
    set<string> DifferentFlightsto(Airport& airport);
    void TopAirportsintrafficcapacity(int n);
    int NumberofFlights();
    int FlightsoutofAirport(Airport& Flightsout, int& airlines);
    void printMenu(vector<string> options, int size, int select, string menuName);
    void auxprintMenu(vector<string> options, int & size, int &select, string menuName);
    void nonBlockingEntrance();
    void restoreEntrace();
    int NumberofFlightspercity(string city);
    int NumberofFlightsperairline(string air);
    int NumberofFlightsperCityandAir(string city, string air);
    void directFlights();
    int NumberofStopsairports(string airport, int stop, Graph<Airport>& airportGraph);
    int NumberofStopscities(string airport, int stop, Graph<Airport>& airportGraph, unordered_set<string>& visitedCities);
    int NumberofStopscountries(string airport, int stop, Graph<Airport>& airportGraph, unordered_set<string>& visitedCountries);
    void findMaxStopsTrip();
    vector<Airport> articulationPoints() const;
    void auxArticulationPoints(Vertex<Airport> *v, vector<Airport> & articulation,int dTime) const;
    void findMaxStopsTripHelper(Vertex<Airport> *currentAirport, int &maxStops, vector<pair<string, string>> &currentTrip, set<pair<string, string>> &printedTrips, unordered_set<string> &visitedAirports);
    void auxMaxStop(Vertex<Airport> *v, int &maxStops, int &temp, vector<pair<string, string>>& vetor);
};


#endif //INC_2PROJETO_MENU_H
