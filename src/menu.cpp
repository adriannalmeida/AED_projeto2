#include "menu.h"
menu:: menu(){

}
void menu::run(){
    DataParser* dataPtr = new DataParser("../dataset");
    DataParser data = *dataPtr;
    for(auto i : data.getTravels().getVertexSet()){
        for (auto u : i->getAdj()){
            cout << u.getAirline().getName();
        }
    }
    mainMenu();
}

void menu::mainMenu(){
    char op;
    cout << "__________________________________________\n";
    cout << "|                MainMenu                |\n";
    cout << "|        Choose one of the options       |\n";
    cout << "|________________________________________|\n";
    cout << "|      1. STUDENTS:                      |\n";
    cout << "|      2. SCHEDULE:                      |\n";
    cout << "|      3. REGISTERED STUDENTS:           |\n";
    cout << "|      4. REQUEST:                       |\n";
    cout << "|      \033[30m5. SAVE AND QUIT:\033[0m                 |\n";
    cout << "|      \033[31m6. QUIT WITHOUT SAVING:\033[0m           |\n";
    cout << "|________________________________________|\n";
    cout << "Your option:";
    cin >> op;
    switch(op) {
        case 1: {
            //menu_Airport();
            cout << "iiiiii" << endl;
            break;
        }

        default:
            cout << "piiiiiiii" << endl;
    }
}