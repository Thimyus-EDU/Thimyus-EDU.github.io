//Parser for commands/arguments
#include "../../include/cli/parser.h"
#include <cstddef>
#include <stdexcept>
#include <string>
#include <limits>


std::string Parser::trim(const std::string& text) {
    const auto first = text.find_first_not_of(" \t\n\r");

    //If no text is entered the parser should ignore it
    if (first == std::string::npos) {
        return "";
    }

    const auto last = text.find_last_not_of(" \t\n\r");
    return text.substr(first, last + 1);
}

bool Parser::parsePositiveInt(const std::string &text, int &value) {
    std::string trimmedText = trim(text);

    if (trimmedText.empty()) {
        return false;
    }

    for (char character : trimmedText) {
        if (!std::isdigit(static_cast<unsigned char>(character))) {
            return false;
        }
    }

    try {
        value = std::stoi(trimmedText);
    }
    catch (...) {
        return false;
    }

    return value > 0;
}

void Parser::printHelp() const {
    std::cout << "\nAvailable commands:\n"
    << "            add                   Add a new task\n"
    << "            list                  List all tasks\n"
    << "            list active           List all incomplete tasks\n"
    << "            list completed        List all completed tasks\n"
    << "            search <keyword>      Search tasks by title or description\n"
    << "            sort priority         Sort Tasks by priority\n"
    << "            sort due              Sort tasks by due date\n"
    << "            next                  Show the highest priority active task\n"
    << "            complete <task id>    Mark a task as complete\n"
    << "            delete <task id>      Delete a task\n"
    << "            help                  Show this help menu\n"
    << "            exit                  Exit the program\n";
}

//Dispaly helper
static void printTaskList(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks found." << std::endl;
        return;
    }

    for (const Task& task : tasks) {
        std::cout << task.id << "> ["
                  << (task.completed ? 'x' : ' ')
                  << "] " << task.title
                  << " | Priority " << task.priority
                  << " | Due Date " << task.dueDate
                  << std::endl;

        std::cout << "   Description: " << task.description << std::endl;
    }
}

Parser::CommandResult Parser::parseInput(const std::string& input) {
    const std::string cleanInput = trim(input);

    if (cleanInput.empty()) {
        return CommandResult::Continue;
    }

    const std::size_t space = cleanInput.find(' ');
    const std::string command = cleanInput.substr(0, space);
    const std::string arguments = (space == std::string::npos) ? "" : trim(cleanInput.substr(space + 1));

    //add command
    if (command == "add") {
        std::string title;
        std::string description;
        std::string dueDate;
        int priority = 3;

        std::cout << "Enter task title: ";
        std::getline(std::cin, title);

        title = trim(title);

        if (title.empty()) {
            std::cout << "Task title cannot be empty" << std::endl;
            return CommandResult::Continue;
        }

        std::cout << "Enter task description: ";
        std::getline(std::cin, description);

        if (description.empty()) {
            std::cout << "Task description cannot be empty." << std::endl;
            return CommandResult::Continue;
        }

        std::cout << "Enter priority (1 = High, 2 = Medium, 3 = Low): ";

        if (!(std::cin >> priority)) {
            std::cout << "Priority must be a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return CommandResult::Continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (priority < 1 || priority > 3) {
            std::cout << "Priority must be 1, 2, or 3." << std::endl;
            return CommandResult::Continue;
        }

        std::cout << "Enter due date (MM-DD-YYYY): ";
        std::getline(std::cin, dueDate);

        dueDate = trim(dueDate);

        if (dueDate.empty()) {
            std::cout << "Due date cannot be empty." << std::endl;
            return CommandResult::Continue;
        }

        if (taskService.addTask(title, description, priority, dueDate)) {
            std::cout << "Task added." << std::endl;
        }
        else {
            std::cout << "Unable to add task. Please check the task details and try again." << std::endl;
        }
    }

    //list command
    else if (command == "list") {
        if (arguments == "active") {
            const std::vector<Task> tasks = taskService.filterTasksByCompletion(false);
            printTaskList(tasks);
        }
        else if (arguments == "completed") {
            const std::vector<Task> tasks = taskService.filterTasksByCompletion(true);
            printTaskList(tasks);
        }
        else if (arguments.empty()) {
            const std::vector<Task> tasks = taskService.listTasks();
            printTaskList(tasks);
        }
        else {
            std::cout << "Invalid list option. Try 'list', 'list active', or 'list completed'." << std::endl;
        }
    }

    //search command
    else if (command == "search") {
        if (arguments.empty()) {
            std::cout << "Search must include a keyword." << std::endl;
            return CommandResult::Continue;
        }

        const std::vector<Task> results = taskService.searchTasks(arguments);
        printTaskList(results);
    }

    //sort command
    else if (command == "sort") {
        if (arguments == "priority") {
            const std::vector<Task> sortedTasks = taskService.sortTasksByPriority();
            printTaskList(sortedTasks);
        }
        else if (arguments == "due") {
            const std::vector<Task> sortedTasks = taskService.sortTasksByDueDate();
            printTaskList(sortedTasks);
        }
        else {
            std::cout << "Invalid sort option. Try 'sort priority' or 'sort due'." << std::endl;
        }
    }

    //next command
    else if (command == "next") {
        Task task;

        if (taskService.getHighestPriorityTask(task)) {
            std::cout << "Next recommended task:" << std::endl;

            std::cout << task.id << "> [ ] "
                  << task.title
                  << " | Priority " << task.priority
                  << " | Due Date " << task.dueDate
                  << std::endl;

        std::cout << "   Description: " << task.description << std::endl;
        }
        else {
            std::cout << "No active tasks found." << std::endl;
        }
    }
    //complete command
    else if (command == "complete") {
        int taskId = 0;

        if (!parsePositiveInt(arguments, taskId)) {
            std::cout << "Please enter a valid positive task ID." << std::endl;
            return CommandResult::Continue;
        }

        if (taskService.completeTask(taskId)) {
            std::cout << "Task " << taskId << " marked as complete." << std::endl;
        }
        else {
            std::cout << "Task " << taskId << " not found." << std::endl;
        }
    }

    //delete command
    else if (command == "delete") {
        int taskId = 0;

        if (!parsePositiveInt(arguments, taskId)) {
            std::cout << "Please enter a valid positive task ID." << std::endl;
            return CommandResult::Continue;
        }

        if (taskService.deleteTask(taskId)) {
            std::cout << "Task " << taskId << " deleted." << std::endl;
        }
        else {
            std::cout << "Task " << taskId << " not found." << std::endl;
        }
    }

    //help command
    else if (command == "help") {
        printHelp();
    }

    //exit command
    else if (command == "exit") {
        return CommandResult::Exit;
    }

    else {
        std::cout << "Invalid command. Type 'help' to see available commands." << std::endl;
    }

    return CommandResult::Continue;
}