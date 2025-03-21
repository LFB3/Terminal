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
    std::vector<std::string> userLogs;
    std::vector<std::string> logs;

    std::string userInput = "0";

    std::vector<std::string> userInputsplit;
    while (true) {
        // User Input
        std::cout << "run:";
        std::getline(std::cin, userInput);
        userLogs.push_back(userInput);
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



        try {
        // Versuche, die Eingabe in eine Zahl zu konvertieren
            std::stoi(userInputsplit[0]); 
            output = calculator(userInputsplit);
        } 
        catch (const std::invalid_argument& e) {
            // Die Eingabe war keine Zahl
            logs.push_back("Invalid Argument, the input was not a number");
        } 
        catch (const std::out_of_range& e) {
            // Die Zahl ist zu groß oder zu klein für einen int
            logs.push_back("Invalid Argument, Out of Range, the number was too big or too small for an int");
        }
        

        // End Output
        cout << output << endl;
        userInputsplit.clear();
        userInput.clear();
    }
}