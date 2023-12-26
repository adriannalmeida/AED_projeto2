#ifndef INC_2PROJETO_MENU_H
#define INC_2PROJETO_MENU_H

#include <iostream>
#include <vector>
#include <unistd.h>
#include <termios.h>
using namespace std;

class menu {
    public:
    menu();
    void run();
    void mainMenu();
    void menuStatistics();
    void printMenu(vector<string> options, int size, int select);
    void nonBlockingEntrance();
    void restoreEntrace();
};


#endif //INC_2PROJETO_MENU_H
