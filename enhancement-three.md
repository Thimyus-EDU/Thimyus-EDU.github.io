# Enhancement Three: Databases

## Overview

The third enhancement focuses on databases. The earlier version of the task management application used JSON-based file persistence. While JSON storage allowed tasks to remain available between program runs, it was still limited because the program treated the task collection as a file-based data structure. For this enhancement, I replaced JSON persistence with SQLite database storage.

## Enhancement Summary

The enhanced version stores tasks in a SQLite database using a `tasks` table. The table includes fields such as task ID, title, description, priority, due date, completion status, and creation timestamp. This design better reflects how real applications organize persistent data and allows the program to use SQL queries for storage and retrieval.

The repository layer is responsible for database operations, including:

* Initializing the database
* Creating the tasks table if it does not already exist
* Adding new tasks
* Retrieving task records
* Updating task completion status
* Deleting tasks
* Searching tasks by keyword
* Filtering tasks by completion status
* Sorting tasks by priority
* Sorting tasks by due date
* Retrieving the next highest-priority task

## Database Skills Demonstrated

This enhancement demonstrates:

* SQLite integration with C++
* SQL table design
* CRUD operations
* Repository-based database access
* Query-based searching
* Query-based filtering
* Query-based sorting
* Persistent data management
* Prepared statements
* Separation of database logic from application logic

## Security Considerations

Security was an important part of this enhancement. Instead of directly combining user input with SQL strings, the repository uses prepared statements for operations that accept user input. Prepared statements help reduce the risk of unsafe SQL construction and support more secure database interaction.

This was especially important for commands that use user-supplied values, such as adding tasks, completing tasks, deleting tasks, and searching by keyword. Even though the application is a local command-line program, this enhancement demonstrates the importance of building secure habits into all database-driven software.

## Course Outcome Alignment

This enhancement supports the course outcome related to using well-founded and innovative techniques, skills, and tools in computing practices. SQLite integration, SQL queries, CRUD operations, and repository-based architecture demonstrate practical database development skills that are directly connected to real software applications.

It also supports the outcome related to designing and evaluating computing solutions because the enhancement required a design trade-off between JSON file storage and SQLite database persistence. JSON was simpler, but SQLite provided a more structured, scalable, and realistic approach to data management.

Finally, this enhancement supports the security outcome because it uses prepared statements and keeps database logic contained within the repository layer. This design reduces risk, improves maintainability, and helps ensure that user input is handled more carefully.

## Supporting Files

* [Databases Narrative](narratives/NarrativeThree.md)
* [Enhanced Source Code](artifacts/enhanced/)
* [Original Source Code](artifacts/original/)

[Return to Home](index.md)

