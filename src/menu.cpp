#include <limits>
#include "menu.h"
menu:: menu(){}
void menu::run(){

    //for(auto i : data.getTravels().getVertexSet()){
    //    for (auto u : i->getAdj()){
    //        cout << u.getAirline().getName();
    //    }
    //}

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


void menu::mainMenu(){
    int size = 4, select = 0;
    vector <string> options = {"Statistics ", "Airports ", "Coisa ", "QUIT "};
    nonBlockingEntrance();
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

    restoreEntrace();
    switch (select){
        case 0:
            menuStatistics();
            wait();
            break;
        case 1:
            menuAirports();
            wait();
            break;
        case 2:
            cout << "wayayayayyayay" << endl;
            break;
        case 3:
            cout << "GOOD BYE ;)" << endl;
    }

}

void menu::menuStatistics() {
    cout << "Entraste-te no Menu ESTATISTICAS !!" << endl;

}
void menu:: menuAirports(){
    int size = 4, select = 0;
    vector <string> options = {"NumberofAirports/Flights", "Flightsout", "Functions3", "QUIT "};
    char keyStroke;
    nonBlockingEntrance();
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
        usleep(100000);  // Adiciona pequeno atraso
    }while (keyStroke != '\n');  // Enter pressionado

    restoreEntrace();
    switch (select){
        case 0:
            NumberofAirports();
            NumberofFlights();
            break;
        case 1:
        {string cin1;
            cin >> cin1;
            auto a = airports[cin1];
            int airlines;
            int u = FlightsoutofAirport(*a,airlines);
            cout << "O Aeroporto de Lisboa tem " << u << " voos e " << airlines << " companhias aereas" << endl;
            //wait();
            break;}
        case 2:
            cout << "Entraste no Menu Functions3" << endl;
            break;
        case 3:
            cout << "GOOD BYE ;)" << endl;
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
