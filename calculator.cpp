#include "calculator.h"

#include <vector>
#include <string>
#include <algorithm>

std::string calculator(std::vector<std::string> userInput) {
    int output = 0;

    if (userInput[0] == "calc" || userInput[0] == "calculator") {
        userInput.erase(userInput.begin());
    }
    
    for (size_t i = 0; i < userInput.size(); i++) {
        std::string lowerCase = userInput[i];
        std::transform(lowerCase.begin(), lowerCase.end(), lowerCase.begin(), ::tolower);
        if (userInput[i] == "*" || userInput[i] == "x" || userInput[i] == "multiply") {
            userInput[i] = std::to_string(std::stoi(userInput[i - 1]) * std::stoi(userInput[i + 1]));
            userInput.erase(userInput.begin() + i - 1);
            userInput.erase(userInput.begin() + i);
        }
    }
    for (size_t i = 0; i < userInput.size(); i++) {
        std::string lowerCase = userInput[i];
        std::transform(lowerCase.begin(), lowerCase.end(), lowerCase.begin(), ::tolower);
        if (userInput[i] == ":" || userInput[i] == "/" || userInput[i] == "divide") {
            userInput[i] = std::to_string(std::stoi(userInput[i - 1]) / std::stoi(userInput[i + 1]));
            userInput.erase(userInput.begin() + i - 1);
            userInput.erase(userInput.begin() + i);
        }
    }
    for (size_t i = 0; i < userInput.size(); i++) {
        std::string lowerCase = userInput[i];
        std::transform(lowerCase.begin(), lowerCase.end(), lowerCase.begin(), ::tolower);
        if (userInput[i] == "-" || userInput[i] == "subtract") {
            userInput[i] = std::to_string(std::stoi(userInput[i - 1]) - std::stoi(userInput[i + 1]));
            userInput.erase(userInput.begin() + i - 1);
            userInput.erase(userInput.begin() + i);
        }
    }
    for (size_t i = 0; i < userInput.size(); i++) {
        std::string lowerCase = userInput[i];
        std::transform(lowerCase.begin(), lowerCase.end(), lowerCase.begin(), ::tolower);
        if (userInput[i] == "+" || userInput[i] == "add") {
            userInput[i] = std::to_string(std::stoi(userInput[i - 1]) + std::stoi(userInput[i + 1]));
            userInput.erase(userInput.begin() + i - 1);
            userInput.erase(userInput.begin() + i);
        }
    }

    return userInput[0];
}