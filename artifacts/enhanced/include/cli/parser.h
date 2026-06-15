#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include "../core/task_service.h"


class Parser{
    private:
      TaskService taskService;

    static std::string trim(const std::string& text);
    static bool parsePositiveInt(const std::string& text, int& value);
    void printHelp() const;

    public:
        //Returns whether the parser should continue or exit the application
        enum class CommandResult {
            Continue,
            Exit
        };

    CommandResult parseInput(const std::string& input);
};


#endif