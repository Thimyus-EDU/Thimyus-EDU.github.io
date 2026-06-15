# CS 499 Milestone Two Narrative: Software Design and Engineering Enhancement

**Enhancement Category:** Software Design and Engineering

## Artifact Description

The artifact I selected for this milestone is a task management application that began as a Java project from earlier coursework. The original version included a `Task` class, a `TaskService` class, and JUnit tests that validated basic task creation, deletion, updating, and retrieval. In its original form, the application demonstrated object-oriented programming and basic service-layer design, but it was limited because it stored tasks only in memory and did not provide a complete user-facing application flow.

For this software design and engineering enhancement, I began transforming the artifact into a modular C++ command-line task manager. The enhanced version uses separate files for the task model, parser, task service, repository, and program entry point. This allows the project to move beyond a small academic service class and become a more complete application with clearer separation of responsibilities.

## Reason for Selection and ePortfolio Justification

I selected this artifact for my ePortfolio because it shows a clear path of growth from a simple original program into a more professional software solution. The original Java artifact had a good foundation because it already separated the task object from the service logic, but it did not fully demonstrate the design decisions that are needed in a larger application.

By rewriting and enhancing the project in C++, I was able to show stronger software development skills through modular architecture, command parsing, persistent storage, validation, and improved control flow. The most important design improvement was separating the program into focused components:

* The `Task` struct defines the data for one task.
* `TaskService` handles business logic such as adding, completing, deleting, and listing tasks.
* `Repository` handles saving and loading tasks from `tasks.json`.
* `Parser` interprets user commands.
* `main.cpp` controls the application loop.

This structure makes the code easier to understand, test, and expand because each file has a specific purpose.

## Specific Enhancements Made

One major enhancement was transforming the original Java task service into a more complete C++ command-line application. The original Java version included a `Task` class and a `TaskService` class that supported basic operations such as adding, deleting, updating, and retrieving tasks. However, the Java version did not include a full user interface, persistent storage, or a command-processing system.

In the enhanced C++ version, I expanded the artifact by creating a command-based interface with commands such as:

```text
add <task title>
list
complete <task id>
delete <task id>
help
exit
```

This improvement makes the application more usable because the user can interact with the program directly instead of only relying on service methods behind the scenes. It also demonstrates stronger software design because `main.cpp` is responsible for running the application loop, the `Parser` is responsible for interpreting user input, `TaskService` handles the task logic, and `Repository` manages saving and loading task data.

Another important enhancement was improving the overall control flow of the application. In the original Java artifact, task operations were called through service methods, but there was no larger application structure for handling user commands. In the enhanced version, I added parser logic that separates the user’s command from the command arguments. For example, when the user enters:

```text
add Finish milestone two
```

the parser identifies `add` as the command and `Finish milestone two` as the task title. This design makes the application easier to expand because new commands can be added to the parser without rewriting the entire program. I also structured the parser with an `if / else-if / else` command chain so only one command branch runs for each input. This makes the command logic clearer, easier to debug, and more reliable.

I also improved the way functions accept arguments and communicate results. The original Java artifact used object-oriented methods such as `addTask`, `deleteTask`, and `updateTask`, but the enhanced C++ version required me to think more carefully about how data should move between functions. For example, `addTask` accepts the task title as `const std::string&` because the service only needs to read the title and should not make an unnecessary copy of a string. For task IDs, passing an `int` by value is appropriate because integers are small and inexpensive to copy.

This distinction helped me better understand when to use pass-by-value, pass-by-reference, and const references in C++. I also moved service operations such as `deleteTask` and `completeTask` toward returning a success or failure value so the parser can give the user accurate feedback when a task does not exist.

The `Repository` component was another key improvement over the original Java artifact. The original version stored tasks in memory using a collection, which meant the task data was lost when the program ended. In the enhanced C++ version, the application uses `tasks.json` as persistent storage. Instead of losing tasks after each run, the application loads existing tasks, modifies the task collection, and saves the updated data back to the JSON file.

This improvement strengthens the artifact because it moves the project from a simple in-memory service toward a more realistic task management application. It also helped me understand the importance of file paths and working directories in C++, especially when running the program from a build directory in CLion.

## Course Outcomes

This enhancement supports several of the CS program outcomes. It most directly supports the outcome related to using well-founded techniques, skills, and tools in computing practice because I used C++, CMake/CLion, modular project organization, file I/O, and JSON persistence to turn the original artifact into a more complete application.

It also supports the outcome related to designing and evaluating computing solutions because I had to make design trade-offs about project structure, command parsing, task storage, and error handling.

Although this milestone focuses on software design and engineering, it also prepares the artifact for later outcomes connected to algorithms and data structures because the project currently stores tasks in a vector and can be expanded with searching, filtering, and sorting.

It also begins to support a security mindset because the enhanced design includes better input validation and defensive handling of invalid commands or file access problems.

At this stage, I believe I met the outcome coverage I planned for the software design and engineering category, and my plan is to continue improving the same artifact in later milestones by strengthening the algorithms, data structures, and persistence portions of the project.

## Reflection on the Enhancement Process

The biggest lesson I learned from this enhancement is that software design is not only about adding more features. A program can have useful functionality but still be difficult to maintain if responsibilities are mixed together or the control flow is unclear.

Refactoring the task manager helped me understand why it is important to separate user input, business logic, and storage. The `Parser` should not directly manage file storage, the `Repository` should not decide how commands work, and `main.cpp` should not contain all of the application logic.

I also learned more about debugging C++ behavior. For example, when the help command printed successfully but the program crashed with a SIGILL error, the issue was connected to a non-void function path that did not return a value. That showed me why compiler warnings such as `control reaches end of non-void function` should be treated seriously.

Another challenge was resolving the `tasks.json` file path. I originally used:

```text
data/tasks.json
```

but because the executable was running from the build directory, the correct relative path was:

```text
../data/tasks.json
```

Working through that issue helped me understand that relative paths are based on the current working directory, not the location of the source file.

Overall, this enhancement helped me see the difference between code that works in a limited way and code that is designed to grow. The original artifact was useful because it provided a clean starting point, but the enhanced C++ version demonstrates stronger software engineering practices through modular design, clearer control flow, persistent storage, and more intentional function design.

I still have areas to improve, such as adding more complete automated tests, improving repository error handling for corrupted JSON, and expanding task operations with update, search, sort, and filter features. However, this milestone represents meaningful progress toward a professional ePortfolio artifact because it shows both my ability to analyze weaknesses in earlier work and my ability to redesign that work into a more maintainable and practical application.

[Return to Home](index.md)
