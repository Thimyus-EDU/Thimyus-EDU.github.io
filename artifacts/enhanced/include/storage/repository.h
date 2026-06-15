//Handles persistent storage
#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "../core/task.h"
#include <string>
#include <vector>
#include <iostream>

#include <sqlite3.h>

class Repository {
private:
    const std::string DATABASE_FILE = "../data/tasks.db";

    [[nodiscard]] bool executeStatement(const std::string& sql) const;
    [[nodiscard]] std::vector<Task> executeTaskQuery(const std::string& sql) const;

public:
    Repository();

    void initializeDatabase() const;

    [[nodiscard]] bool addTask(const Task& task) const;
    [[nodiscard]] bool completeTask(int id) const;
    [[nodiscard]] bool deleteTask(int id) const;

    [[nodiscard]] std::vector<Task> loadTasks() const;
    [[nodiscard]] std::vector<Task> filterTasksByCompletion(bool completed) const;
    [[nodiscard]] std::vector<Task> sortTasksByPriority() const;
    [[nodiscard]] std::vector<Task> searchTasks(const std::string& keyword) const;
    [[nodiscard]] std::vector<Task> sortTasksByDueDate() const;
    bool getHighestPriorityTask(Task& result) const;
};



#endif