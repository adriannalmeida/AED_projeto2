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

void menu:: printMenu(vector<string> options, int size, int select) {
    system("clear");  // Limpa a tela (Linux)
    cout << "__________________________________________\n";
    cout << "|                Menu                    |\n";
    cout << "|        Choose one of the options       |\n";
    cout << "|________________________________________|\n";
    for (int i = 0; i < size; ++i) {
        if (i == select) {
            cout << "      \033[1;31m> " << options[i] << " <\033[0m" << endl;  // Set text to red
        } else {
            cout << "       " << options[i] << " " << endl;
        }
    }
    cout << "|________________________________________|\n";
}
void menu:: auxprintMenu(vector<string> options, int & size, int &select){
    char keyStroke;
    do{
            printMenu(options, size, select);
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
    vector <string> options = {"Statistics ", "Best Flight Option", "Coisa ", "QUIT "};
    nonBlockingEntrance();
    auxprintMenu(options, size, select);
    restoreEntrace();
    switch (select){
        case 0:
            menuStatistics();
           // wait();
            break;
        case 1:
            //menuAirports();
             wait();
            break;
        case 2:
            cout << "wayayayayyayay" << endl;
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
    auxprintMenu(options,size,select);
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
    vector <string> options = {"Total Nº of Airports", "Nº of Flights per Airport", "Nº of countries", "No lay-over flights",
                               "Destinations with N lay-overs", "função 7 wtf", "Top Airports in traffic capacity","Essential Airports", "Go back"};
    nonBlockingEntrance();
    auxprintMenu(options,size,select);
    restoreEntrace();
    switch (select){
        case 0:
            std::cout << "The total number of airports in this network is \033[1;31m> " << NumberofAirports() << " <\033[0m" << std::endl;
            wait();
            break;
        case 1:{
            cout << "Enter the code of the Airport to look up: ";
            string code;
            cin >> code;
            auto a = airports[code];
            int airlines;
            int u = FlightsoutofAirport(*a,airlines);
            cout << airports[code]->getName() << "has " << u << " possible flights and works with " << airlines << " airlines" << endl;
            wait();
            break;}
        case 2:
        {
            string cin1;
            cin >> cin1;
            int u = DifferentFlightsto(*airports[cin1]);
            cout << "Nº of countries " << u << endl;
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
            int cin1;
            cin >> cin1;
            TopAirportsintrafficcapacity(cin1);
            wait();
            break;
        case 7:{
            auto x = articulationPoints();
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
    int size = 4, select = 0;
    vector <string> options = {"Number of Airports", "Number of Cities", "Number of Countries", "Go back"};
    nonBlockingEntrance();
    auxprintMenu(options,size,select);
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
        case 3:
            menuDestination();
    }

}
void menu :: menuFlightStatistics(){
    int size = 6, select = 0;
    vector <string> options = {"Total Flights", "Flights per City", "Flights per Airline", "Flights per City and Airline" ,"Flights from City X","Go back"};
    nonBlockingEntrance();
    auxprintMenu(options,size,select);
    restoreEntrace();
    switch (select){
        case 0:
            NumberofFlights();
            wait();
            break;
        case 1:
            {string city;
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
            break;
    }

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
    cout << "Enter the code of the Airport of interest: ";
    string code;
    cin >> code;
    Airport *a = airports.find(code)->second;
    cout << "Select one option:" << endl << "1- Search by nº of reachable countries " << endl;
    cout << "2- Search by nº of reachable cities" << endl << "3- Search by nº of reachable airports" << endl;
    int n = 0;
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
        auto airport = find(destAirports.begin(), destAirports.end(), adest.getCode());
        if (airport == destAirports.end())
            destAirports.push_back(adest.getName());
    }
    cin >> n;
    switch (n) {
        case 1: {
            cout << "From " << a->getName() << " there are " << destCountries.size()
                 << " reachable countries with direct flights" << endl;
            cout << "Press L for access the full list of Countries" << endl;
            string letter;
            cin >> letter;
            if (letter == "L" or letter == "l") {
                cout << endl;
                for (auto x: destCountries) {
                    cout << x << endl;
                }
            }
            break;
        }
        case 2: {
            cout << "From " << a->getName() << " there are " << destCities.size() << " reachable Cities with direct flights" << endl;
            cout << "Press L for access the full list of Cities" << endl;
            string letter;
            cin >> letter;
            if (letter == "L" or letter == "l") {
                cout << endl;
                for (auto x: destCities) {
                    cout << x << endl;
                }
            }
            break;
        }
        case 3:
            cout << "From " << a->getName() << " there are " << destAirports.size() << " reachable Airports with direct flights" << endl;
            cout << "Press L for access the full list of Airports" << endl;
            string letter;
            cin >> letter;
            if (letter == "L" or letter == "l") {
                cout << endl;
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
                    count += NumberofStopscities(u.getDest()->getInfo().getCode(), stop - 1, airportGraph, visitedCities);
                    if (visitedCities.find(u.getDest()->getInfo().getCountry().getCity()) != visitedCities.end()) {
                        count--;
                    }else{
                        visitedCities.insert(u.getDest()->getInfo().getCountry().getCity());
                    }
                }
            }
        }
    }

    return count;
}

int menu::NumberofStopscountries(string airport, int stop, Graph<Airport>& airportGraph, unordered_set<string>& visitedCountries) {
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
                    count += NumberofStopscountries(u.getDest()->getInfo().getCode(), stop - 1, airportGraph, visitedCountries);
                    if (visitedCountries.find(u.getDest()->getInfo().getCountry().getCountryName()) != visitedCountries.end()) {
                        count--;
                    }else{
                        visitedCountries.insert(u.getDest()->getInfo().getCountry().getCountryName());
                    }
                }
            }
        }
    }

    return count;
}

void menu::findMaxStopsTrip() {
    int maxStops = 0;
    vector<pair<string, string>> currentTrip;
    set<pair<string, string>> printedTrips;
    Graph<Airport> airportGraph;

    unordered_set<string> visitedAirports;

    for (auto u : Travels.getVertexSet()) {
        if (!visitedAirports.count(u->getInfo().getCode())) {
            visitedAirports.insert(u->getInfo().getCode());
            findMaxStopsTripHelper(u, airportGraph, maxStops, currentTrip, printedTrips, visitedAirports);
            visitedAirports.erase(u->getInfo().getCode());
        }
    }

    cout << "Maximum stops trip(s):" << endl;
    for (const auto &trip : printedTrips) {
        cout << "From " << trip.first << " to " << trip.second << "/" << printedTrips.size() << endl;
    }
}

void menu::findMaxStopsTripHelper(Vertex<Airport> *currentAirport, Graph<Airport> &airportGraph,
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
            findMaxStopsTripHelper(destAirport, airportGraph, maxStops, currentTrip, printedTrips, visitedAirports);

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

int menu::DifferentFlightsto(Airport& airport){
    int count = 0;
    for(auto i : Travels.getVertexSet()){
        for(auto u : i->getAdj()){
            if(u.getDest()->getInfo().getCountry().getCity() == airport.getCountry().getCity()){
                count++;
            }
        }
    }
    return count;
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



vector<Airport> menu::articulationPoints() const {
    vector<Airport> articulation;
    for (auto v : Travels.getVertexSet()){
        v->setProcessing(false);
        v->setLow(0);
        v->setNum(0);
    }
    int dTime = 1;
    for (auto v : Travels.getVertexSet())
        if (! v->isVisited()){
            aux(v, articulation, dTime);
        }
    return articulation;
}

void menu::aux(Vertex<Airport> *v, vector<Airport> & articulation,int dTime) const {
    v->setNum(dTime);
    v->setLow(dTime);
    v->setProcessing(true);
    int tree = 0;
    for (auto w: v->getAdj()){
        if(w.getDest()->getNum() == 0){
            tree++;
            aux(w.getDest(), articulation, dTime +1);
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

