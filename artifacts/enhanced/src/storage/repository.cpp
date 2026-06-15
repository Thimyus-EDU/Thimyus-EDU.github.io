// Used to load and save tasks with SQLite
#include "../../include/storage/repository.h"

#include <iostream>

Repository::Repository() {
    initializeDatabase();
}

void Repository::initializeDatabase() const {
    const std::string sql =
        "CREATE TABLE IF NOT EXISTS tasks ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "title TEXT NOT NULL, "
        "description TEXT NOT NULL, "
        "priority INTEGER NOT NULL CHECK(priority BETWEEN 1 AND 3), "
        "due_date TEXT NOT NULL, "
        "completed INTEGER NOT NULL DEFAULT 0, "
        "created_at INTEGER NOT NULL"
        ");";

    if (!executeStatement(sql)) {
        std::cerr << "Unable to initialize database." << std::endl;
    }
}

bool Repository::executeStatement(const std::string& sql) const {
    sqlite3* db = nullptr;
    char* errorMessage = nullptr;

    if (sqlite3_open(DATABASE_FILE.c_str(), &db) != SQLITE_OK) {
        std::cerr << "Unable to open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return false;
    }

    const int result = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errorMessage);

    if (result != SQLITE_OK) {
        std::cerr << "SQL error: " << errorMessage << std::endl;
        sqlite3_free(errorMessage);
        sqlite3_close(db);
        return false;
    }

    sqlite3_close(db);
    return true;
}

std::vector<Task> Repository::executeTaskQuery(const std::string& sql) const {
    std::vector<Task> tasks;
    sqlite3* db = nullptr;
    sqlite3_stmt* statement = nullptr;

    if (sqlite3_open(DATABASE_FILE.c_str(), &db) != SQLITE_OK) {
        std::cerr << "Unable to open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return tasks;
    }

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &statement, nullptr) != SQLITE_OK) {
        std::cerr << "Unable to prepare query: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return tasks;
    }

    while (sqlite3_step(statement) == SQLITE_ROW) {
        Task task;

        task.id = sqlite3_column_int(statement, 0);
        task.title = reinterpret_cast<const char*>(sqlite3_column_text(statement, 1));
        task.description = reinterpret_cast<const char*>(sqlite3_column_text(statement, 2));
        task.priority = sqlite3_column_int(statement, 3);
        task.dueDate = reinterpret_cast<const char*>(sqlite3_column_text(statement, 4));
        task.completed = sqlite3_column_int(statement, 5) == 1;
        task.timestamp = static_cast<std::time_t>(sqlite3_column_int64(statement, 6));

        tasks.push_back(task);
    }

    sqlite3_finalize(statement);
    sqlite3_close(db);

    return tasks;
}

bool Repository::addTask(const Task& task) const {
    sqlite3* db = nullptr;
    sqlite3_stmt* statement = nullptr;

    const std::string sql =
        "INSERT INTO tasks (title, description, priority, due_date, completed, created_at) "
        "VALUES (?, ?, ?, ?, ?, ?);";

    if (sqlite3_open(DATABASE_FILE.c_str(), &db) != SQLITE_OK) {
        std::cerr << "Unable to open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return false;
    }

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &statement, nullptr) != SQLITE_OK) {
        std::cerr << "Unable to prepare insert statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return false;
    }

    sqlite3_bind_text(statement, 1, task.title.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(statement, 2, task.description.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(statement, 3, task.priority);
    sqlite3_bind_text(statement, 4, task.dueDate.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(statement, 5, task.completed ? 1 : 0);
    sqlite3_bind_int64(statement, 6, static_cast<sqlite3_int64>(task.timestamp));

    const bool success = sqlite3_step(statement) == SQLITE_DONE;

    if (!success) {
        std::cerr << "Unable to insert task: " << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(statement);
    sqlite3_close(db);

    return success;
}

std::vector<Task> Repository::loadTasks() const {
    const std::string sql =
        "SELECT id, title, description, priority, due_date, completed, created_at "
        "FROM tasks "
        "ORDER BY id ASC;";

    return executeTaskQuery(sql);
}

bool Repository::completeTask(int id) const {
    sqlite3* db = nullptr;
    sqlite3_stmt* statement = nullptr;

    const std::string sql =
        "UPDATE tasks "
        "SET completed = 1 "
        "WHERE id = ?;";

    if (sqlite3_open(DATABASE_FILE.c_str(), &db) != SQLITE_OK) {
        std::cerr << "Unable to open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return false;
    }

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &statement, nullptr) != SQLITE_OK) {
        std::cerr << "Unable to prepare update statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return false;
    }

    sqlite3_bind_int(statement, 1, id);

    const bool success = sqlite3_step(statement) == SQLITE_DONE;
    const int changedRows = sqlite3_changes(db);

    if (!success) {
        std::cerr << "Unable to complete task: " << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(statement);
    sqlite3_close(db);

    return success && changedRows > 0;
}

bool Repository::deleteTask(int id) const {
    sqlite3* db = nullptr;
    sqlite3_stmt* statement = nullptr;

    const std::string sql =
        "DELETE FROM tasks "
        "WHERE id = ?;";

    if (sqlite3_open(DATABASE_FILE.c_str(), &db) != SQLITE_OK) {
        std::cerr << "Unable to open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return false;
    }

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &statement, nullptr) != SQLITE_OK) {
        std::cerr << "Unable to prepare delete statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return false;
    }

    sqlite3_bind_int(statement, 1, id);

    const bool success = sqlite3_step(statement) == SQLITE_DONE;
    const int changedRows = sqlite3_changes(db);

    if (!success) {
        std::cerr << "Unable to delete task: " << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(statement);
    sqlite3_close(db);

    return success && changedRows > 0;
}

std::vector<Task> Repository::searchTasks(const std::string& keyword) const {
    std::vector<Task> tasks;
    sqlite3* db = nullptr;
    sqlite3_stmt* statement = nullptr;

    const std::string sql =
        "SELECT id, title, description, priority, due_date, completed, created_at "
        "FROM tasks "
        "WHERE title LIKE ? OR description LIKE ? "
        "ORDER BY id ASC;";

    if (sqlite3_open(DATABASE_FILE.c_str(), &db) != SQLITE_OK) {
        std::cerr << "Unable to open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return tasks;
    }

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &statement, nullptr) != SQLITE_OK) {
        std::cerr << "Unable to prepare search statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return tasks;
    }

    const std::string pattern = "%" + keyword + "%";

    sqlite3_bind_text(statement, 1, pattern.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(statement, 2, pattern.c_str(), -1, SQLITE_TRANSIENT);

    while (sqlite3_step(statement) == SQLITE_ROW) {
        Task task;

        task.id = sqlite3_column_int(statement, 0);
        task.title = reinterpret_cast<const char*>(sqlite3_column_text(statement, 1));
        task.description = reinterpret_cast<const char*>(sqlite3_column_text(statement, 2));
        task.priority = sqlite3_column_int(statement, 3);
        task.dueDate = reinterpret_cast<const char*>(sqlite3_column_text(statement, 4));
        task.completed = sqlite3_column_int(statement, 5) == 1;
        task.timestamp = static_cast<std::time_t>(sqlite3_column_int64(statement, 6));

        tasks.push_back(task);
    }

    sqlite3_finalize(statement);
    sqlite3_close(db);

    return tasks;
}

std::vector<Task> Repository::filterTasksByCompletion(bool completed) const {
    const std::string sql =
        "SELECT id, title, description, priority, due_date, completed, created_at "
        "FROM tasks "
        "WHERE completed = " + std::to_string(completed ? 1 : 0) + " "
        "ORDER BY id ASC;";

    return executeTaskQuery(sql);
}

std::vector<Task> Repository::sortTasksByPriority() const {
    const std::string sql =
        "SELECT id, title, description, priority, due_date, completed, created_at "
        "FROM tasks "
        "ORDER BY priority ASC, id ASC;";

    return executeTaskQuery(sql);
}

std::vector<Task> Repository::sortTasksByDueDate() const {
    const std::string sql =
        "SELECT id, title, description, priority, due_date, completed, created_at "
        "FROM tasks "
        "ORDER BY substr(due_date, 7, 4), substr(due_date, 1, 2), substr(due_date, 4, 2), id ASC;";

    return executeTaskQuery(sql);
}

bool Repository::getHighestPriorityTask(Task& result) const {
    const std::string sql =
        "SELECT id, title, description, priority, due_date, completed, created_at "
        "FROM tasks "
        "WHERE completed = 0 "
        "ORDER BY priority ASC, substr(due_date, 7, 4), substr(due_date, 1, 2), substr(due_date, 4, 2), id ASC "
        "LIMIT 1;";

    const std::vector<Task> tasks = executeTaskQuery(sql);

    if (tasks.empty()) {
        return false;
    }

    result = tasks.front();
    return true;
}