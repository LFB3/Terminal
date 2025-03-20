#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> logs;
    std::string userInput = "0";
    while (true) {
        std::cout << "Run:";
        std::cin >> userInput;
        logs.push_back(userInput);
        if (userInput == "exit") {
            break;
        }
        
    }
}
