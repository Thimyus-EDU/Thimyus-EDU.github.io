//Task definition
#ifndef TASK_H
#define TASK_H

#include <ctime>
#include <string>

struct Task{
    int id = 0;
    std::string title;
    std::string description;
    int priority = 3;
    std::string dueDate;
    bool completed = false;
    std::time_t timestamp = 0;
};

#endif