#include "menu.h"
menu:: menu(){}
void menu::run(){
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
    cout << "|                MainMenu                |\n";
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
            break;
        case 1:
            cout << " OMG OPÇÃO 2" << endl;
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