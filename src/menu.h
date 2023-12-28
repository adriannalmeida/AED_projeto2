#ifndef INC_2PROJETO_MENU_H
#define INC_2PROJETO_MENU_H

#include <iostream>
#include "DataParser.h"
#include <vector>
#include <unistd.h>
#include <termios.h>
#include <algorithm>
using namespace std;

class menu {
    Graph<Airport> Travels;
    unordered_map<string, Airline *> airlines;
    unordered_map<string, Airport*> airports;
    public:
    menu();
    void run();
    void mainMenu();
    void menuStatistics();
    void menuAirportStatistics();
    void menuFlightStatistics();
    //void menuAirports();
    void wait();
    int NumberofAirports();
    int NumberofFlights();
    int FlightsoutofAirport(Airport& Flightsout, int& airlines);
    void printMenu(vector<string> options, int size, int select);
    void auxprintMenu(vector<string> options, int & size, int &select);
    void nonBlockingEntrance();
    void restoreEntrace();
    int NumberofFlightspercity(string city);
    int NumberofFlightsperairline(string air);
    int NumberofFlightsperCityandAir(string city, string air);
    void directFlights();
};


#endif //INC_2PROJETO_MENU_H
