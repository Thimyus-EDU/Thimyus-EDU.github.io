#ifndef TASK_SERVICE_H
#define TASK_SERVICE_H

#include "task.h"
#include "../storage/repository.h"

#include <string>
#include <vector>

class TaskService {
private:
    Repository repo;

public:
    [[nodiscard]] bool addTask(const std::string& title, const std::string& description, int priority, const std::string& dueDate) const;
    [[nodiscard]] bool deleteTask(int id) const;
    [[nodiscard]] std::vector<Task> listTasks() const;
    [[nodiscard]] bool completeTask(int id) const;

    [[nodiscard]] std::vector<Task> searchTasks(const std::string& keyword) const;
    [[nodiscard]] std::vector<Task> filterTasksByCompletion(bool completed) const;
    [[nodiscard]] std::vector<Task> sortTasksByPriority() const;
    [[nodiscard]] std::vector<Task> sortTasksByDueDate() const;
    bool getHighestPriorityTask(Task& result) const;
};

#endif