#include <iostream>
#include <random>
#include <thread>
#include "src/menu.h"


void loadingAnimation(int durationSeconds) {
    int width = 50;
    for (int i = 0; i < durationSeconds * 10; ++i) {
        int pos = i % width;

        std::cout << "\r[";
        for (int j = 0; j < width; ++j) {
            if (j < pos) std::cout << "=";
            else if (j == pos) std::cout << ">";
            else std::cout << " ";
        }
        std::cout << "] " << int((float)i / (durationSeconds * 10) * 100.0) << "% " << std::flush;

        std::this_thread::sleep_for(std::chrono::milliseconds(180));
    }

    std::cout << "\r              \r";
}

int main() {
    system("clear");
    int durationSeconds = 5;
    std::cout << "                       LOADING...\n";

    // Cria uma thread para a animação de carregamento
    std::thread loadingThread(loadingAnimation, durationSeconds);

    // Executa o menu simultaneamente
    menu menu1;
    menu1.run();

    // Aguarda a conclusão da thread de carregamento
    loadingThread.join();

    return 0;
}