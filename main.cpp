#include <iostream>
#include <random>
#include "src/menu.h"


std::vector<std::string> phrases = {
        "Why was the new IT official hospitalized? He accidentally touched the firewall.",
        "Why are the insurance and premiums for all app developers enormously high? Because they are always crashing down!",
        "There are 10 types of people in the world. Those who understand binary and those who don't.",
        "Why are computers bad at boxing? Their barks are always worse than their bytes!",
        "How does a computer science major pick up girls? \"Oh, shit thought this was Google!\"",
        "What do you call it when computer science majors make fun of each other? Cyber Boolean.",
        "What do you call a creepy Computer Science teacher? A PDF file.",
        "What do you call a nap in computer science class? A CS-ta.",
        "Why did the transgender person fail computer science? Because they were non-binary.",
        "What do you call it when two computer scientists come simultaneously? An andgasm."
};

int main() {
    srand(static_cast<unsigned>(time(0)));
    int index = rand() % phrases.size();
    cout << phrases[index] << endl;
    menu menu1;
    menu1.run();
    return 0;
}
