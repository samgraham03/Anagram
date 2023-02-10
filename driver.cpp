#include "Anagram.hpp"
#include <iostream>

// g++ driver.cpp Anagram.cpp

void introduction() {
    std::cout << "Enter \"ANAGRAM\" to begin testing strings" << std::endl;
    std::cout << "Enter \"END\" to stop program" << std::endl;
}

int main() {
    Anagram * anagram = new Anagram();
    
    introduction();

    std::string cmd;
    std::string * stringSequence = new std::string[2]; // Temp placeholder for dynamic approach

    while (std::cin >> cmd) {
        if (cmd == "ANAGRAM" || cmd == "Anagram" || cmd == "anagram") {
            for (int i = 0; i < 2; i++) { // Temp placeholder for dynamic approach
                std::cout << "Enter string " << i + 1 << ": ";
                std::cin >> stringSequence[i];
            }
            
            try {
                std::cout << (anagram->compare(stringSequence[0], stringSequence[1]) ? "Anagram found!" : "Not an anagram") << std::endl;
            }
            catch(std::invalid_argument& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }

            std::cout << std::endl;
            introduction();
        }
        else if (cmd == "END" || cmd == "End" || cmd == "end") {
            std::cout << "Goodbye!";
            break;
        }
    }

    delete[] stringSequence;  // Temp placeholder for dynamic approach
    stringSequence = nullptr;

    delete anagram;
    anagram = nullptr;

    return 0;
}