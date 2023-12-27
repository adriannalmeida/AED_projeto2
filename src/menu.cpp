#include <limits>
#include "menu.h"
menu:: menu(){}
void menu::run(){
    DataParser data = DataParser("dataset");
    data.read();
    this->Travels = data.getTravels();
    this->airlines = data.getAirlines();
    this->airports = data.getAirports();
    /*for (auto x: Travels.getVertexSet()){
        cout << x->getInfo().getName() << endl;
    }*/
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
            wait();
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
            wait();
            break;
        case 1:
            menuFlightStatistics();
            wait();
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
    int size = 8, select = 0;
    vector <string> options = {"Total Nº of Airports", "Nº of Flights per Airport", "Nº of countries", "No lay-over flights",
                               "Destinations with N lay-overs", "função 7 wtf", "Top Airports in traffic capacity","Go back"};
    nonBlockingEntrance();
    auxprintMenu(options,size,select);
    restoreEntrace();
    switch (select){
        case 0:
            NumberofAirports();
            wait();
            break;
        case 1:
        {string cin1;
            cin >> cin1;
            auto a = airports[cin1];
            int airlines;
            int u = FlightsoutofAirport(*a,airlines);
            cout << "O Aeroporto de Lisboa tem " << u << " voos e " << airlines << " companhias aereas" << endl;
            wait();
            break;}
        case 2:
            cout << "nº of countries ..."<< endl;
            wait();
            break;
        case 3:
            cout << "No lay-over flights: " << endl;
            wait();
            break;
        case 4:
            cout << "Max destinations with N lay-overs" << endl;
            wait();
            break;
        case 5:
            cout << "função 7!~" << endl;
            wait();
            break;
        case 6:
            cout << "TOp airports in traffic capacity" << endl;
            wait();
            break;
        case 7:
            menuStatistics();
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
            cin >> city;
            int count = NumberofFlightspercity(city);
            cout  << count << endl;
            wait();
            break;}
        case 2:
            {string air;
            cin >> air;
            int count = NumberofFlightspercity(air);
            cout  << count << endl;
            wait();
            break;}
        case 3:
            {string city;
            string air;
            cout << "City:" << endl;
            cin >> city;
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
    cout << count << endl;
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
    vector<string> airlineslist;

    for (auto i: Travels.getVertexSet()) {
        if (i->getInfo().getCode() == Flightsout.getCode()) {
            for (auto u: i->getAdj()) {
                count++;
                if(airlineslist.empty()){
                    airlineslist.push_back(u.getAirline().getCode());
                    airlines++;
                }
                /*int a = airlineslist.size();
                for (auto k = 0; k<a;k++) {
                    if (airlineslist[k] == u.getAirline().getCode()) {
                        continue;
                    } else {
                        airlineslist.push_back(u.getAirline().getCode());
                        airlines++;
                    }

                }*/

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
