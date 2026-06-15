# Enhancement Three: Databases Narrative

**Enhancement Category:** Databases

## Artifact Description

The artifact I selected for this enhancement is a Task Management application originally based on a Java project from CS 320. The original version of the project used a `Task` class and a `TaskService` class to manage task objects in memory. It demonstrated basic object-oriented programming concepts, validation, and service-layer logic, but it did not include persistent storage or a database.

For my capstone project, I rewrote and expanded the application in C++ to create a more complete command-line task management system. The enhanced version allows users to add, list, complete, delete, search, filter, sort, and view prioritized tasks.

For this database enhancement, I improved the artifact by replacing the earlier JSON-based storage system with a SQLite database.

## Justification for Inclusion in the ePortfolio

I selected this artifact for my ePortfolio because it demonstrates my ability to take a simple academic project and turn it into a more complete software application. The original artifact was useful as a starting point because it already had a clear purpose: managing tasks. However, it was limited because tasks were stored in memory and were not preserved in a professional database structure.

A task management application is a strong candidate for database enhancement because each task naturally maps to a database record with fields such as ID, title, description, priority, due date, completion status, and creation timestamp. By adding database persistence, I was able to transform the project from a basic programming assignment into a more realistic application that stores and retrieves data reliably.

## Database Enhancement Summary

The major improvement made in this enhancement was replacing JSON file persistence with SQLite database storage. In the earlier C++ version, the repository saved and loaded tasks from a JSON file. While this was useful for basic persistence, it required the program to work with the full collection of tasks as a file-based data structure.

The enhanced version now stores tasks in a SQLite database using a `tasks` table. This table includes fields for the task ID, title, description, priority, due date, completion status, and creation timestamp. This design better reflects how real applications organize persistent data and allows the application to use SQL queries for storage and retrieval.

## Separation of Concerns

Another important improvement was strengthening the separation of concerns in the application architecture. The project is organized so that the parser handles user commands, the task service handles business logic and validation, and the repository handles database operations.

This design keeps SQL-specific code out of the command parser and task service, making the project easier to maintain and expand. The repository is responsible for:

* Initializing the database
* Creating the `tasks` table if it does not already exist
* Inserting new tasks
* Retrieving tasks
* Updating completion status
* Deleting tasks
* Searching tasks
* Filtering by completion status
* Sorting by priority
* Sorting by due date
* Retrieving the next highest-priority task

This demonstrates the repository pattern and shows a cleaner division between user interaction, application logic, and data persistence.

## SQL CRUD Operations

The enhancement also demonstrates database programming skills through the use of SQL CRUD operations. The application can:

* Create task records through `INSERT` statements
* Read task records through `SELECT` queries
* Update task completion status through `UPDATE` statements
* Delete task records through `DELETE` statements

In addition to basic CRUD operations, the database layer also supports query-based searching, filtering, and sorting. For example, search functionality uses SQL pattern matching to find tasks by title or description, while sorting functionality uses SQL ordering to organize tasks by priority or due date.

Moving these operations into the database makes the application more aligned with database-driven software design.

## Security Considerations

Security was also considered during this enhancement. Instead of building SQL commands by directly combining user input with query strings, the enhanced repository uses prepared statements for operations that accept user input. Prepared statements help protect the database layer from unsafe input and reduce the risk of SQL injection.

This was especially important for commands such as adding tasks, completing tasks, deleting tasks, and searching by keyword. Including prepared statements allowed me to connect the database enhancement to secure coding practices as well as database design.

## Course Outcome Alignment

This enhancement aligns mostly with Course Outcome Three and Course Outcome Four.

Course Outcome Three focuses on designing and evaluating computing solutions using algorithmic principles and computer science practices while managing trade-offs. This outcome is demonstrated through the decision to use SQLite instead of JSON file storage. JSON was simpler, but SQLite provides a more structured and scalable approach to persistent data. The project also uses query-based sorting, searching, and filtering, which shows consideration of how data retrieval can be handled more effectively.

Course Outcome Four focuses on using well-founded techniques, skills, and tools in computing practices to implement solutions that deliver value. This outcome is demonstrated through the integration of SQLite with C++, the use of SQL queries, the repository pattern, and the creation of a more practical task management application.

This enhancement also supports Course Outcome Five because it applies a security mindset to data handling. Although this is a local command-line application, the use of prepared statements shows that security was considered during database interaction. I learned that secure design should be included even in smaller applications because the habits used in small projects carry over into larger professional systems.

By avoiding unsafe SQL construction and keeping database logic contained within the repository, the project became more reliable and better organized.

## Reflection on the Enhancement Process

The process of enhancing this artifact helped me better understand the difference between file-based persistence and database-driven persistence. With JSON storage, the program treated the task list as one large object that had to be loaded and saved. With SQLite, each task is stored as a row in a table, and the program can use SQL statements to work with individual records.

This helped me understand why databases are valuable for applications that need reliable data management, structured queries, and long-term maintainability.

One challenge I faced was adjusting the design of the repository. In the JSON version, the repository only needed to load and save a vector of tasks. In the SQLite version, the repository needed to support several specific operations, such as adding one task, completing one task, deleting one task, and querying tasks in different ways.

This required me to think more carefully about how data should flow through the application. I also had to make sure that the task service remained focused on validation and business logic rather than becoming responsible for SQL statements. This helped reinforce the importance of separation of concerns.

Another challenge was making sure the database enhancement did not break the existing command-line interface. Because the parser and task service were already separated from the repository, I was able to replace the storage system without rewriting the entire application. This showed me the practical value of modular design. Since each part of the program had a clear responsibility, I could improve one layer of the application while preserving the behavior of the other layers.

Overall, this enhancement improved the artifact by making it more persistent, organized, secure, and realistic. The application now demonstrates database integration, SQL query development, CRUD operations, prepared statements, and repository-based architecture.

More importantly, it shows my growth from creating simple class-based programs to designing a more complete software system with separate layers and a real database. This makes the artifact a strong addition to my ePortfolio because it reflects skills that are directly connected to my goal of becoming a software engineer.

[Return to Home](index.md)
