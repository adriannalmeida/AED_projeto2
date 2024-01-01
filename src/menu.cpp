#include <limits>
#include "menu.h"
#include <algorithm>
menu:: menu(){}
void menu::run(){
    DataParser data = DataParser("dataset");
    data.read();
    this->Travels = data.getTravels();
    this->airlines = data.getAirlines();
    this->airports = data.getAirports();
    mainMenu();
}

void menu:: nonBlockingEntrance() {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~ICANON;
    t.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

void menu:: restoreEntrace() {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag |= ICANON;
    t.c_lflag |= ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

void menu::printMenu(vector<string> options, int size, int select, string menuName) {
    system("clear");
    int terminalWidth = 44;
    int menuIndentation = 22 - (menuName.size() / 2);
    std::cout << "_______________________________________________\n";
    std::cout << "" << std::setw(menuIndentation) << "" << menuName << std::setw(menuIndentation) << "" << "\n";
    std::cout << "|          Choose one of the options          |\n";
    std::cout << "|_____________________________________________|\n";

    int maxOptionLength = 0;
    for (const std::string& option : options) {
        maxOptionLength = std::max(maxOptionLength, static_cast<int>(option.length()));
    }
    for (int i = 0; i < size; ++i) {
        int indentation = (terminalWidth - maxOptionLength) / 2;
        if (i == select) {
            std::cout << setw(indentation) << "" << "\033[1;31m> " << options[i] << " <\033[0m\n"; // Set text to red
        } else {
            std::cout << setw(indentation) << "" << options[i] << "\n";
        }
    }
    std::cout << "|______________________________________________|\n";
}

void menu:: auxprintMenu(vector<string> options, int & size, int &select, string menuName){
    char keyStroke;
    do{
            printMenu(options, size, select, menuName);
            keyStroke = getchar();
            switch (keyStroke){
                case '\033':  // Tecla de escape, indica que uma sequência de controle está chegando
                    getchar();  // Descarta o '[' que segue a tecla de escape
                switch (getchar()) {  // Lê a tecla real
                    case 'A':  // Tecla para cima
                        select = (select - 1 + size) % size;
                        break;
                    case 'B':  // Tecla para baixo
                        select = (select + 1) % size;
                        break;
                }
                break;
            }
            //usleep(100000);  // Adiciona pequeno atraso
    }while (keyStroke != '\n');  // Enter pressionado
}

void menu::mainMenu(){
    int size = 4, select = 0;
    vector <string> options = {"Statistics ", "Best Flight Option", "Search With Filters", "QUIT "};
    nonBlockingEntrance();
    auxprintMenu(options, size, select, "Menu");
    restoreEntrace();
    switch (select){
        case 0:
            menuStatistics();
           // wait();
            break;
        case 1:
            menuAirports();
            //wait();
            break;
        case 2:
            menuAirports();
            break;
        case 3:
            cout << "GOOD BYE ;)" << endl;
            return;
    }
}

void menu::menuStatistics() {
    int size = 4, select = 0;
    vector <string> options = {"Airports Statistics", "Flights Statistics", "Go back", "QUIT "};
    nonBlockingEntrance();
    auxprintMenu(options,size,select, "Statistics");
    restoreEntrace();
    switch (select){
        case 0:
            menuAirportStatistics();
            //wait();
            break;
        case 1:
            menuFlightStatistics();
            //wait();
            break;
        case 2:
            mainMenu();
            break;
        case 3:
            cout << "GOOD BYE ;)" << endl;
            return;
    }

}

void menu:: menuAirportStatistics(){
    int size = 9, select = 0;
    vector <string> options = {"Total Nº of Airports", "Nº of Flights per Airport", "Destination countries", "No lay-over flights",
                               "Destinations with N lay-overs", "Longest Trip", "Top Airports in traffic capacity","Essential Airports", "Go back"};
    nonBlockingEntrance();
    auxprintMenu(options,size,select, "Airport Statistics");
    restoreEntrace();
    switch (select){
        case 0:
            std::cout << "The total number of airports in this network is \033[1;31m" << NumberofAirports() << "\033[0m" << std::endl;
            wait();
            break;
        case 1:{
            int f = 1; string code;
            do{cout << "Enter the code of the Airport of interest: ";
                cin >> code; f = 1;
                auto it =airports.find(code);
                if(it == airports.end()){
                    f = 0;
                    cout << "Invalid code" << endl;
                }
            }while (f == 0);
            auto a = airports[code];
            int airlines;
            int u = FlightsoutofAirport(*a,airlines);
            cout << airports[code]->getName() << "has \033[1;31m" << u << "\033[0m possible flights and works with \033[1;31m" << airlines << "\033[0m airlines" << endl;
            wait();
            break;}
        case 2:{
            int f = 1; string code;
            do{
                cout << "Enter the code of the Airport of interest: ";
                cin >> code; f = 1;
                auto it =airports.find(code);
                if(it == airports.end()){
                    f = 0;
                    cout << "Invalid code" << endl;
                }
            }while (f == 0);
            auto dest = DifferentFlightsto(*airports[code]);
            cout << airports[code]->getName() <<" flies to \033[1;31m" << dest.size() << "\033[0m different countries"<< endl;
            cout << "Do you want a full list of countries?"<< endl << "Enter Yes to access the list:";
            string ans;
            cin >> ans; transform(ans.begin(), ans.end(), ans.begin(), ::tolower);
            if(ans == "yes") for(auto y: dest) cout << y << endl;
            wait();
            break;}
        case 3:
            cout << "No lay-over flights: " << endl;
            directFlights();
            wait();
            break;
        case 4:
            menuDestination();
            break;
        case 5:
            findMaxStopsTrip();
            wait();
            break;
        case 6:
            cout << "Enter the number of Airports: " << endl;
            int cin1;
            cout << "Enter the number of airports you want to see: " << endl;
            cin >> cin1;
            TopAirportsintrafficcapacity(cin1);
            wait();
            break;
        case 7:{
            auto x = articulationPoints();
            sort(x.begin(), x.end());
            cout << "In this network " << x.size() << " airports are essential" << endl;
            cout << "Do you want a full list on the essential Airports?"<< endl << "Enter Yes to access the list:";
            string ans;
            cin >> ans; transform(ans.begin(), ans.end(), ans.begin(), ::tolower);
            if(ans == "yes") for(auto y: x) cout << y.getName() << endl;
            wait();
            break;}
        case 8:
            menuStatistics();
    }

}

void menu::menuDestination() {
    int size = 3, select = 0;
    vector <string> options = {"Number of Airports", "Number of Cities", "Number of Countries"};
    nonBlockingEntrance();
    auxprintMenu(options,size,select, "Destinations");
    restoreEntrace();
    switch (select){
        case 0:
        {Graph<Airport> airportGraph;
            string airport;
            int stop;
            cout << "Code of the starting airport:" << endl;
            getline(cin, airport);
            cout << "Number of lay-overs:" << endl;
            cin >> stop;
            int n = NumberofStopsairports(airport, stop, airportGraph);
            cout << n << endl;
            wait();
            break;}
        case 1:
        {Graph<Airport> airportGraph;
            unordered_set<string> visitedCities;
            string airport;
            int stop;
            cout << "Code of the starting airport:" << endl;
            getline(cin, airport);
            cout << "Number of lay-overs:" << endl;
            cin >> stop;
            int n = NumberofStopscities(airport, stop, airportGraph, visitedCities);
            cout << n << endl;
            wait();
            break;}
        case 2:
        {Graph<Airport> airportGraph;
            unordered_set<string> visitedCountries;
            string airport;
            int stop;
            cout << "Code of the starting airport:" << endl;
            getline(cin, airport);
            cout << "Number of lay-overs:" << endl;
            cin >> stop;
            int n = NumberofStopscountries(airport, stop, airportGraph, visitedCountries);
            cout << n << endl;
            wait();
            break;}

        //case 3:
            //menuAirportStatistics();
    }

}
void menu::menuFlightStatistics(){
    int size = 6, select = 0;
    vector <string> options = {"Total Flights", "Flights per City", "Flights per Airline", "Flights per City and Airline" ,"Flights from City X","Go back"};
    nonBlockingEntrance();
    auxprintMenu(options,size,select, "Flight Statistics");
    restoreEntrace();
    switch (select){
        case 0:
            NumberofFlights();
            wait();
            break;
        case 1:
            {string city;
            cout << "Enter the city of interest:" << endl;
            getline(cin, city);
            int count = NumberofFlightspercity(city);
            cout  << count << endl;
            wait();
            break;}
        case 2:
            {string air;
            cin >> air;
            int count = NumberofFlightsperairline(air);
            cout  << count << endl;
            wait();
            break;}
        case 3:
            {string city;
            string air;
            cout << "City:" << endl;
            getline(cin, city);
            cout << "Airline:" << endl;
            cin >> air;
            int count = NumberofFlightsperCityandAir(city, air);
            cout  << count << endl;
            wait();
            break;}
        case 4:
            cout << "not implemented" <<  endl;
            wait();
            break;
        case 5:
            menuStatistics();
    }

}
void menu::menuAirports() {
    int size = 3, select = 0;
    vector <string> options = {"Source and Destiny","Search With Filters", "Go back"};
    nonBlockingEntrance();
    auxprintMenu(options, size, select, "Menu Airports");
    restoreEntrace();
    switch (select){
        case 0:
        {vector<Airport*> srcAirports = SelectAirportSrc();
            vector<Airport*> destAirports = SelectAirportDest();
            findBestFlightOption(srcAirports, destAirports);
            wait();
            break;}
        case 1:
        {

            vector<Airport*> srcAirports = SelectAirportSrc();
            vector<Airport*> destAirports = SelectAirportDest();
            cout << "Airline:" << endl;
            string airlineStr;
            cin >> airlineStr;
            Airline* airline = airlines[airlineStr];
            findBestFlightOptionWithFilters(srcAirports, destAirports, airline);
            wait();
            break;}
        case 2:
            mainMenu();
            break;
    }
}
vector<Airport*> menu::SelectAirportSrc() {
    int size = 4, select = 0;
    vector <string> options = {"Airport code", "Airport name", "City", "Coordenates"};
    nonBlockingEntrance();
    auxprintMenu(options, size, select, "Source");
    restoreEntrace();

    vector<Airport*> selectedAirports;
    switch (select){
        case 0:
        {string airport;
            cout << "Source:" << endl;
            cin >> airport;
            selectedAirports.push_back(airports[airport]);
            return selectedAirports;}
        case 1:
        {string airport;
            cout << "Source:" << endl;
            cin >> airport;
            selectedAirports.push_back(UsingAirport(airport));
            return selectedAirports;}
        case 2:
        {string airport;
            cout << "Source:" << endl;
            cin >> airport;
            selectedAirports = UsingCity(airport);
            return selectedAirports;}
        case 3:
        {double latitude;
            double longitude;
            cout << "Source Latitude:" << endl;
            cin >> latitude;
            cout << "Source Longitude:" << endl;
            cin >> longitude;
            selectedAirports = UsingLocation(latitude, longitude);
            return selectedAirports;}
    }
    return selectedAirports;
}

vector<Airport*> menu::SelectAirportDest() {
    int size = 4, select = 0;
    vector <string> options = {"Airport code", "Airport name", "City", "Coordenates"};
    nonBlockingEntrance();
    auxprintMenu(options, size, select, "Dest");
    restoreEntrace();

    vector<Airport*> selectedAirports;
    switch (select){
        case 0:
        {string airport;
            cout << "Destiny:" << endl;
            cin >> airport;
            selectedAirports.push_back(airports[airport]);
            return selectedAirports;}
        case 1:
        {string airport;
            cout << "Destiny:" << endl;
            cin >> airport;
            selectedAirports.push_back(UsingAirport(airport));
            return selectedAirports;}
        case 2:
        {string airport;
            cout << "Destiny:" << endl;
            cin >> airport;
            selectedAirports = UsingCity(airport);
            return selectedAirports;}
        case 3:
        {double latitude;
            double longitude;
            cout << "Destiny Latitude:" << endl;
            cin >> latitude;
            cout << "Destiny Longitude:" << endl;
            cin >> longitude;
            selectedAirports = UsingLocation(latitude, longitude);
            return selectedAirports;}
    }
    return selectedAirports;
}
int menu::NumberofAirports() {
    int count = 0;
    for(auto i : Travels.getVertexSet()){
        count++;
    }
    return count;
}
int menu::NumberofFlights() {
    int count = 0;
    for(auto i : Travels.getVertexSet()){
        for(auto u : i->getAdj()){
            count++;
        }
    }
    cout  << count << endl;
    return count;
}
int menu::FlightsoutofAirport(Airport& Flightsout, int& airlines) {
    int count = 0;
    auto aux = Travels.findVertex(Flightsout);
    airlines = 0;
    std::unordered_set<string> uniqueAirlines;
    for (auto i : Travels.getVertexSet()) {
        if (i->getInfo().getCode() == Flightsout.getCode()) {


            for (auto u : i->getAdj()) {
                count++;

                // Use unordered_set's insert method to automatically handle uniqueness
                auto result = uniqueAirlines.insert(u.getAirline().getCode());

                // Check if the insertion took place (i.e., the airline code was unique)
                if (result.second) {
                    airlines++;
                }
            }
        }
    }
    return count;
}
void menu::wait() {
    cout << "Press ENTER to continue...";
    cin.get();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    mainMenu();
    // Chama o mainMenu() após pressionar Enter
}

int menu::NumberofFlightspercity(string city) {
    int count = 0;
    for(auto i : Travels.getVertexSet()){
        if(i->getInfo().getCountry().getCity() == city) {
            for (auto u: i->getAdj()) {
                count++;
            }
        }
        for (auto u: i->getAdj()) {
            if (u.getDest()->getInfo().getCountry().getCity() == city) {
                count++;
            }
        }
    }
    return count;
}

int menu::NumberofFlightsperairline(string air) {
    int count = 0;
    for(auto i : Travels.getVertexSet()){
        for (auto u: i->getAdj()) {
            if (u.getAirline().getCode() == air) {
                count++;
            }
        }
    }
    return count;
}

int menu::NumberofFlightsperCityandAir(string city, string air){
    int count = 0;
    for(auto i : Travels.getVertexSet()){
        if(i->getInfo().getCountry().getCity() == city) {
            for (auto u: i->getAdj()) {
                if (u.getAirline().getCode() == air) {
                    count++;
                }
            }
        }
        for (auto u: i->getAdj()) {
            if (u.getDest()->getInfo().getCountry().getCity() == city && u.getAirline().getCode() == air) {
                count++;
            }
        }
    }
    return count;
}


void menu::directFlights() {
    int size = 3, select = 0;
    vector <string> options = {"Search by nº of reachable countries", "Search by nº of reachable cities", "Search by nº of reachable airports"};
    nonBlockingEntrance();
    auxprintMenu(options,size,select, "");
    restoreEntrace();
    int f = 1; string code;
    do{cout << "Enter the code of the Airport of interest: " << endl;
        cin >> code; f = 1;
        auto it =airports.find(code);
        if(it == airports.end()){
            f = 0;
            cout << "Invalid code" << endl;
        }
    }while (f == 0);
    Airport *a = airports.find(code)->second;
    auto vertex = Travels.findVertex(*a);
    vector<string> destCountries, destCities, destAirports;
    for (auto x: vertex->getAdj()) {
        auto adest = x.getDest()->getInfo();
        auto city = find(destCities.begin(), destCities.end(), adest.getCountry().getCity());
        if (city == destCities.end())
            destCities.push_back(adest.getCountry().getCity());
        auto country = find(destCountries.begin(), destCountries.end(), adest.getCountry().getCountryName());
        if (country == destCountries.end())
            destCountries.push_back(adest.getCountry().getCountryName());
        auto airport = find(destAirports.begin(), destAirports.end(), adest.getName());
        if (airport == destAirports.end())
            destAirports.push_back(adest.getName());
    }

    switch (select) {
        case 0: {
            cout << "From " << a->getName() << "there are \033[1;31m" << destCountries.size()
                 << "\033[0m reachable countries with direct flights" << endl;
            cout << "Do you want a full list of countries?"<< endl << "Enter Yes to access the list:";
            string ans;
            cin >> ans; transform(ans.begin(), ans.end(), ans.begin(), ::tolower);
            if(ans == "yes"){
                cout << endl;
                sort(destCountries.begin(), destCountries.end());
                for (auto x: destCountries) {
                    cout << x << endl;
                }
            }
            break;
        }
        case 1: {
            cout << "From " << a->getName() << " there are \033[1;31m" << destCities.size() << "\033[0m reachable Cities with direct flights" << endl;
            cout << "Do you want a full list of countries?"<< endl << "Enter Yes to access the list:";
            string ans;
            cin >> ans; transform(ans.begin(), ans.end(), ans.begin(), ::tolower);
            if(ans == "yes"){
                cout << endl;
                sort(destCities.begin(), destCities.end());
                for (auto x: destCities) {
                    cout << x << endl;
                }
            }
            break;
        }
        case 2:
            cout << "From " << a->getName() << " there are \033[1;31m" << destAirports.size() << "\033[0m reachable Airports with direct flights" << endl;
            cout << "Do you want a full list of countries?"<< endl << "Enter Yes to access the list:";
            string ans;
            cin >> ans; transform(ans.begin(), ans.end(), ans.begin(), ::tolower);
            if(ans == "yes"){
                cout << endl;
                sort(destAirports.begin(), destAirports.end());
                for (auto y: destAirports) {
                    cout << y << endl;
                }
            }
    }
}

int menu::NumberofStopsairports(string airport, int stop, Graph<Airport>& airportGraph) {
    int count = 0;
    if (stop == 0) {
        return 0;
    }

    for (auto i : Travels.getVertexSet()) {
        if (i->getInfo().getCode() == airport) {
            for (auto u : i->getAdj()) {
                if(!airportGraph.findVertex(u.getDest()->getInfo())){
                    count++;
                    airportGraph.addVertex(u.getDest()->getInfo());
                    count += NumberofStopsairports(u.getDest()->getInfo().getCode(), stop - 1, airportGraph);
                }
            }
        }
    }

    return count;
}

int menu::NumberofStopscities(string airport, int stop, Graph<Airport>& airportGraph, unordered_set<string>& visitedCities) {
    if (stop == 0) {
        return 0;
    }

    for (auto i : Travels.getVertexSet()) {
        if (i->getInfo().getCode() == airport) {
            for (auto u : i->getAdj()) {
                if(!visitedCities.count(u.getDest()->getInfo().getCountry().getCountryName())){
                    airportGraph.addVertex(u.getDest()->getInfo());
                    NumberofStopscities(u.getDest()->getInfo().getCode(), stop - 1, airportGraph, visitedCities);
                    visitedCities.insert(u.getDest()->getInfo().getCountry().getCity());
                }
            }
        }
    }

    return visitedCities.size();
}

int menu::NumberofStopscountries(string airport, int stop, Graph<Airport>& airportGraph, unordered_set<string>& visitedCountries) {
    if (stop == 0) {
        return 0;
    }
    auto i = Travels.findVertex(*airports[airport]);
    for (auto u : i->getAdj()) {
        if(!visitedCountries.count(u.getDest()->getInfo().getCountry().getCountryName())){
            airportGraph.addVertex(u.getDest()->getInfo());
            NumberofStopscountries(u.getDest()->getInfo().getCode(), stop - 1, airportGraph, visitedCountries);
            visitedCountries.insert(u.getDest()->getInfo().getCountry().getCountryName());
        }
    }
    return visitedCountries.size();
}

void menu::findMaxStopsTrip() {
    int f = 1, maxStops = 0, temp = 0;
    string code;
    do {
        cout << "Enter the code of the Airport of interest: ";
        cin >> code;
        f = 1;
        auto it = airports.find(code);
        if (it == airports.end()) {
            f = 0;
            cout << "Invalid code" << endl;
        }
    } while (f == 0);

    vector<string> airportsCode;
    auto a1 = Travels.findVertex(*airports[code]);
    queue<Vertex<Airport> *> q;
    for (auto v : Travels.getVertexSet())
        v->setVisited(false);
    q.push(a1);
    a1->setVisited(true);
    int level = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int x = 0; x < size; x++){
            auto v = q.front();
            q.pop();
            for (auto & e : v->getAdj()) {
                auto w = e.getDest();
                if (! w->isVisited()) {
                    q.push(w);
                    w->setVisited(true);
                    //airportsCode.push_back(v->getInfo().getCode());
                }
            }
        }level++;
    }
    cout << "NOTE:" << endl;
    cout << "This option calculates the fastest way to get to the airport that requires teh biggest number of stops to get there" << endl <<
    " however have in mind that this calculates the best path and not a path with loops as it would useless to repeat airports" << endl <<
    " or travel to two airports when one might be enough to reach the final destination" << endl;
    cout << endl << "From " << airports[code]->getName() << " the trip with most stops passes through \033[1;31m" << level << "\033[0m airports " << endl;

}



void menu::findMaxStopsTripHelper(Vertex<Airport> *currentAirport,
                                  int &maxStops, vector<pair<string, string>> &currentTrip,
                                  set<pair<string, string>> &printedTrips,
                                  unordered_set<string> &visitedAirports) {
    currentAirport->setVisited(true);

    for (auto &edge : currentAirport->getAdj()) {
        auto destAirport = edge.getDest();
        if (!destAirport->isVisited() && currentAirport->getInfo().getCode() != destAirport->getInfo().getCode()) {
            visitedAirports.insert(destAirport->getInfo().getCode());
            currentTrip.push_back({currentAirport->getInfo().getCode(), destAirport->getInfo().getCode()});
            cout << destAirport->getInfo().getCode();
            findMaxStopsTripHelper(destAirport, maxStops, currentTrip, printedTrips, visitedAirports);

            currentTrip.pop_back();
            visitedAirports.erase(destAirport->getInfo().getCode());
        }
    }

    currentAirport->setVisited(false);

    if (currentTrip.size() == maxStops) {
        pair<string, string> tripPair = {currentTrip.front().first, currentTrip.back().second};
        if (printedTrips.find(tripPair) == printedTrips.end()) {
            printedTrips.insert(tripPair);
        }
    } else if (currentTrip.size() > maxStops) {
        maxStops = currentTrip.size();
        printedTrips.clear();
        printedTrips.insert({currentTrip.front().first, currentTrip.back().second});
    }
}

set<string> menu::DifferentFlightsto(Airport& airport){
    set<string> visitedCountries;
    //for (auto i: airport)
    auto i = Travels.findVertex(airport);
    for (auto u: i->getAdj()) {
        if (!visitedCountries.count(u.getDest()->getInfo().getCountry().getCountryName())) {
            visitedCountries.insert(u.getDest()->getInfo().getCountry().getCountryName());
                }
            }
    return visitedCountries;
}
void menu::TopAirportsintrafficcapacity(int n) {
    for(auto i : Travels.getVertexSet()){
       i->setNum(0);
    }
    for(auto i: Travels.getVertexSet()){
        for(auto u : i->getAdj()){
            i->setNum(i->getNum()+1);
            u.getDest()->setNum(u.getDest()->getNum()+1);
        }
    }
    for(int k = 0; k<n; k++){
        int max = 0;
        Vertex<Airport>* aux;
        for(auto i : Travels.getVertexSet()){
            if(i->getNum() > max){
                max = i->getNum();
                aux = i;
            }
        }
        cout << aux->getInfo().getCode() << " " << aux->getNum() << endl;
        aux->setNum(0);
    }
}

//master
void menu::EssencialAirports(){
    unordered_set<Vertex<Airport>*> aux;

    for (auto i : Travels.getVertexSet()) {
        i->setNum(0);
        i->setVisited(false);
    }

    cout << "Essential Airports: " << endl;

    for (auto i : Travels.getVertexSet()) {
        if (!i->isVisited()) {
            Travels.DFSAUXILIAR(i, aux);
        }
    }

    for (auto i : aux) {
        cout << i->getInfo().getCode() << endl;
    }

    cout << "Number of airports: " << aux.size() << endl;
}
Airport* menu::UsingAirport(string airport){
    for(auto i : Travels.getVertexSet()){
        if (i->getInfo().getName() == airport){
            return airports[i->getInfo().getCode()];
        }
    }
    return NULL;
}
vector<Airport*> menu::UsingCity(const string& city) {
    vector<Airport*> selectedAirports;
    for(auto i : Travels.getVertexSet()){
        if (i->getInfo().getCountry().getCity() == city){
            selectedAirports.push_back(airports[i->getInfo().getCode()]);
        }
    }
    return selectedAirports;
}
vector<Airport*> menu::UsingLocation(double latitude, double longitude) {
    const double thresholdDistance = 100.0;  // Adjust the threshold as needed

    vector<Airport*> closestAirports;

    for (auto& pair : airports) {
        Airport* airport = pair.second;

        double airportLat = airport->getCoordinates().getLatitude();
        double airportLon = airport->getCoordinates().getLongitude();

        // Calculate Haversine Distance
        double distance = haversineDistance(latitude, longitude, airportLat, airportLon);

        // Check if the distance is below the threshold
        if (distance < thresholdDistance) {
            closestAirports.push_back(airport);
        }
    }

    return closestAirports;
}
void menu::findBestFlightOption(const vector<Airport*>& srcAirports, const vector<Airport*>& destAirports) {
    vector<vector<Vertex<Airport>*>> bestPaths;
    size_t minStops = numeric_limits<size_t>::max();

    for (auto srcAirport : srcAirports) {
        for (auto destAirport : destAirports) {
            vector<Vertex<Airport>*> currentPath = findMinStopsTripHelper(srcAirport, destAirport);

            if (currentPath.size() < minStops) {
                minStops = currentPath.size();
                bestPaths = {move(currentPath)};
            } else if (currentPath.size() == minStops) {
                bestPaths.push_back(move(currentPath));
            }
        }
    }

    printBestFlights(bestPaths);
}

void menu::findBestFlightOptionWithFilters(const vector<Airport*>& srcAirports, const vector<Airport*>& destAirports, Airline* airline) {
    vector<vector<Vertex<Airport>*>> bestPaths;
    size_t minStops = numeric_limits<size_t>::max();


    for (auto srcAirport : srcAirports) {
        for (auto destAirport : destAirports) {
            vector<Vertex<Airport>*> currentPath = findMinStopsTripHelper(srcAirport, destAirport);

            if (currentPath.size() < minStops) {
                minStops = currentPath.size();
                bestPaths = {move(currentPath)};
            } else if (currentPath.size() == minStops) {
                bestPaths.push_back(move(currentPath));
            }
        }
    }

    printBestFlightsWithFilters(bestPaths, airline);
}
vector<Vertex<Airport> *> menu::findMinStopsTripHelper(Airport* src, Airport* dest) {
    priority_queue<Vertex<Airport>*, vector<Vertex<Airport>*>, CompareDist<Airport>> pq;
    unordered_set<Vertex<Airport>*> visited;

    // Reset distances and previous pointers
    for (auto vertex : Travels.getVertexSet()) {
        vertex->setDistance(numeric_limits<double>::infinity());
        vertex->setPrevious(nullptr);
    }

    Travels.findVertex(*src)->setDistance(0);
    pq.push(Travels.findVertex(*src));

    while (!pq.empty()) {
        Vertex<Airport>* current = pq.top();
        pq.pop();

        if (current->getInfo() == *dest) {
            break;
        }

        if (visited.count(current) == 0) {
            visited.insert(current);

            for (const Edge<Airport>& edge : current->getAdj()) {
                Vertex<Airport>* neighbor = edge.getDest();
                double newDistance = current->getDistance() + edge.getDistance();

                if (newDistance < neighbor->getDistance()) {
                    neighbor->setDistance(newDistance);
                    neighbor->setPrevious(current);
                    pq.push(neighbor);
                }
            }
        }
    }

    vector<Vertex<Airport>*> shortestPath;
    Vertex<Airport>* current = Travels.findVertex(*dest);
    while (current != nullptr) {
        shortestPath.insert(shortestPath.begin(), current);
        current = current->getPrevious();
    }

    return shortestPath;
}

void menu::printBestFlights(const vector<vector<Vertex<Airport>*>>& bestPaths) const {
    cout << "Best Flight Options:" << endl;

    for (const auto& path : bestPaths) {
        for (size_t i = 0; i < path.size() - 1; ++i) {
            string src = path[i]->getInfo().getCode();
            string dest = path[i + 1]->getInfo().getCode();

            for (auto u : Travels.getVertexSet()) {
                if (u->getInfo().getCode() == src) {
                    for (auto edge : u->getAdj()) {
                        if (edge.getDest()->getInfo().getCode() == dest) {
                            auto it = airlines.find(edge.getAirline().getCode());
                            if (it != airlines.end()) {
                                Flights flight(src, dest, *it->second);
                                cout << "From: " << flight.getsrc() << " To: " << flight.getdest() << " Airline: " << it->second->getCode() << endl;
                            }
                        }
                    }
                }
            }
        }
        cout << "----------------------------" << endl;
    }
}


void menu::printBestFlightsWithFilters(const vector<vector<Vertex<Airport>*>>& bestPaths, Airline* airline) const {
    cout << "Best Flight Options:" << endl;
    vector<Flights> flights;
    for (const auto& path : bestPaths) {
        for (size_t i = 0; i < path.size() - 1; ++i) {
            string src = path[i]->getInfo().getCode();
            string dest = path[i + 1]->getInfo().getCode();

            for (auto u : Travels.getVertexSet()) {
                if (u->getInfo().getCode() == src) {
                    for (auto edge : u->getAdj()) {
                        if (edge.getDest()->getInfo().getCode() == dest) {
                            auto it = airlines.find(edge.getAirline().getCode());
                            if (it != airlines.end() && it->second == airline) {
                                Flights flight(src, dest, *it->second);
                                flights.push_back(flight);
                            }
                            else if(it != airlines.end() && it->second != airline){
                                flights.clear();
                            }
                        }
                    }
                }
            }
        }

    }
    for(auto i : flights){
        cout << "From: " << i.getsrc() << " To: " << i.getdest() << endl;
    }
    cout << "----------------------------" << endl;
}

double menu::haversineDistance(double lat1, double lon1, double lat2, double lon2) {
    // distance between latitudes
    // and longitudes
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;

    // convert to radians
    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;

    // apply formulae
    double a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    return rad * c;
}

Graph<Airport> menu :: undirectedGraph(){
    Graph<Airport> undirectedTRavels = Travels;
    for (auto vertex:  Travels.getVertexSet()){
        for(auto edge: vertex-> getAdj()){
            auto destVertex = edge.getDest();
            int f = 0;
            for (auto v: destVertex->getAdj()){
                if(v.getDest() == vertex)
                    f = 1;
            }
            if(f == 0){
                Airline a;
                Edge<Airport> k = Edge(vertex, 0, a );
                auto adj = destVertex->getAdj();
                adj.push_back(k);
                destVertex->setAdj(adj);
            }
        }
    }
    return undirectedTRavels;
}

//vector<Airport> menu::articulationPoints() const {
vector<Airport> menu::articulationPoints() {
    vector<Airport> articulation;
    Graph<Airport> undirectedTravels = undirectedGraph();
    for (auto v : undirectedTravels.getVertexSet()){
        v->setProcessing(false);
        v->setLow(0);
        v->setNum(0);
    }
    int dTime = 1;
    for (auto v : undirectedTravels.getVertexSet())
        if (! v->isVisited()){
            auxArticulationPoints(v, articulation, dTime);
        }
    return articulation;
}

void menu::auxArticulationPoints(Vertex<Airport> *v, vector<Airport> & articulation,int dTime) const {
    v->setNum(dTime);
    v->setLow(dTime);
    v->setProcessing(true);
    int tree = 0;
    for (auto w: v->getAdj()){
        if(w.getDest()->getNum() == 0){
            tree++;
            auxArticulationPoints(w.getDest(), articulation, dTime +1);
            v->setLow(min(v->getLow(), w.getDest()->getLow()));
            if((w.getDest()->getLow() >= v->getNum() and v->getNum()!= 1) or (v->getNum() == 1 and tree > 1)){
                auto it = find(articulation.begin(), articulation.end(), v->getInfo());
                if (it == articulation.end()) {
                    articulation.push_back(v->getInfo());
                }
            }
        }
        else if( v->isProcessing()){
            v->setLow(min(v->getLow(), w.getDest()->getNum()));
        }
    }
    v->setProcessing(false);


}

