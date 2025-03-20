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
    std::string userInputstd = "0";

    std::vector<std::string> userInputsplit;
    std::vector<std::string> userInputsplitstd;
    while (true) {
        // User Input
        std::cout << endl << "run:";
        std::getline(std::cin, userInputstd);
        logs.push_back(userInputstd);
        // User Input to Lowercase
        userInput = userInputstd;
        transform(userInputstd.begin(), userInputstd.end(), userInput.begin(), ::tolower);

        // Splitting the standart string
        std::stringstream ss(userInputstd);
        std::string word;
        while (ss >> word) {
            userInputsplitstd.push_back(word);
        }
        // Splitting the lowercase string
        std::stringstream sss(userInput);
        while (sss >> word) {
            userInputsplit.push_back(word);
        }

        // Using User Input

        // Close the Terminal
        if (userInput == "exit") {
            close;
        }

        // Calculator with
        // Calc or Calculator at beginning

        if (userInputsplit[0] == "calc" || userInputsplit[0] == "calculator") {
            output = calculator(userInputsplit);
        }
        cout << endl << output;
    }
}
