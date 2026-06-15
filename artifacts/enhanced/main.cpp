//Entry point for program
#include <iostream>
#include "include/cli/parser.h"


int main() {
    //Create parser object
    Parser parser;
    std::string input;

    std::cout << "Task Manager Application" << std::endl;
    std::cout << "Type 'help' to view commands." << std::endl;

    //Main application loop
    while (true) {
        std::cout << "> ";

        //Reads user input & stores it as a string
        if (!std::getline(std::cin, input)) {
            break;
        }

        //Send input to the parser
        if (parser.parseInput(input) == Parser::CommandResult::Exit) {
            break;
        }
    }

    std::cout << "Exiting Application" << std::endl;
    return 0;
}