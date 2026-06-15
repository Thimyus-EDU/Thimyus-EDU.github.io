#include "../../include/core/task_service.h"

#include <ctime>

bool TaskService::addTask(const std::string& title, const std::string& description, const int priority, const std::string& dueDate) const {
    if (title.empty() || title.length() > 50) {
        return false;
    }

    if (description.empty() || description.length() > 200) {
        return false;
    }

    if (priority < 1 || priority > 3) {
        return false;
    }

    if (dueDate.empty()) {
        return false;
    }

    Task newTask;
    newTask.title = title;
    newTask.description = description;
    newTask.priority = priority;
    newTask.dueDate = dueDate;
    newTask.completed = false;
    newTask.timestamp = std::time(nullptr);

    return repo.addTask(newTask);
}

std::vector<Task> TaskService::listTasks() const {
    return repo.loadTasks();
}

bool TaskService::completeTask(const int id) const {
    if (id <= 0) {
        return false;
    }

    return repo.completeTask(id);
}

bool TaskService::deleteTask(const int id) const {
    if (id <= 0) {
        return false;
    }

    return repo.deleteTask(id);
}

std::vector<Task> TaskService::searchTasks(const std::string& keyword) const {
    if (keyword.empty()) {
        return {};
    }

    return repo.searchTasks(keyword);
}

std::vector<Task> TaskService::filterTasksByCompletion(const bool completed) const {
    return repo.filterTasksByCompletion(completed);
}

std::vector<Task> TaskService::sortTasksByPriority() const {
    return repo.sortTasksByPriority();
}

std::vector<Task> TaskService::sortTasksByDueDate() const {
    return repo.sortTasksByDueDate();
}

bool TaskService::getHighestPriorityTask(Task& result) const {
    return repo.getHighestPriorityTask(result);
}
