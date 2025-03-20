#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

#include "close.h"
#include "calculator.h"

using namespace std;


int main() {
    // Variables
    std::string output = "0";
    std::vector<std::string> logs;

    std::string userInput = "0";

    std::vector<std::string> userInputsplit;
    while (true) {
        // User Input
        std::cout << "run:";
        std::getline(std::cin, userInput);
        logs.push_back(userInput);
        transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);

        // Splitting the user input
        std::string s = "";
        for (int i = 0; i < userInput.size(); i++) {
            if (userInput[i] == ' ') {
                userInputsplit.push_back(s);
                s.clear();
                continue;
            }
            s += userInput[i];
        }
        userInputsplit.push_back(s);


        // Commands
        if (userInput == "exit") {
            close;
        }
        if (userInputsplit[0] == "calc"|| userInputsplit[0] == "calculator") {
            output = calculator(userInputsplit);
        }
    }
}