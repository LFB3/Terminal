#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::string iostream() {
    std::string input = "";
    
    std::cout << "run: ";
    std::getline(std::cin, input);
    return input;
}

int main() {
    while (true) {
        std::string input = iostream();
        std::istringstream iss(input);
        std::string commmand;
        if (iss >> commmand) {
        }
        if (commmand == "exit" || commmand == "quit") {
            std::cout << "Exiting the program, Goodbye." << std::endl;
            break;
        }
    }
}