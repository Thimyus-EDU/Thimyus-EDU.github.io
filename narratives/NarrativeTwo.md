# Enhancement Two: Algorithms and Data Structures Narrative

**Enhancement Category:** Algorithms and Data Structures

## Artifact Description

The artifact I selected for this enhancement is a Task Management application originally created as a Java project in CS 320. The original version of the application included a `Task` class and a `TaskService` class. The `Task` class stored basic task information, including a task ID, name, and description. The `TaskService` class managed the tasks using an in-memory `HashMap`, which allowed tasks to be added, updated, deleted, and retrieved by their unique ID.

For this enhancement, I rewrote and expanded the application in C++. The enhanced version includes a more complete task model, a command-line interface, a task service layer, and a repository layer for JSON-based persistence. More importantly for this milestone, the enhanced version adds algorithms and data structure functionality that was not present in the original Java version. These improvements include searching tasks by keyword, filtering tasks by completion status, sorting tasks by priority, sorting tasks by due date, and retrieving the highest-priority active task.

## Justification for Inclusion in the ePortfolio

I selected this artifact for my ePortfolio because it shows meaningful growth from a simple course assignment into a more complete and useful software application. The original Java version demonstrated basic object-oriented programming, validation, and use of a collection-based data structure. However, it was limited because it only stored tasks in memory and did not include more advanced ways to organize, search, or prioritize task data.

This artifact is a strong choice for the algorithms and data structures category because task management naturally depends on efficient organization and retrieval of information. In the enhanced version, I expanded the task model to include additional fields such as title, description, priority, due date, completion status, and timestamp. These fields make it possible to apply more meaningful algorithms to the task collection.

## Algorithmic Improvements

### Keyword Search

One specific improvement was adding keyword search functionality. The search feature allows the user to search through task titles and descriptions. This demonstrates a linear search algorithm because the program must examine each task in the collection and compare the search term against the task’s stored text fields.

Although this approach has a time complexity of `O(n)`, it is appropriate for the size and scope of this command-line task management application.

### Filtering by Completion Status

Another improvement was adding filtering functionality. The enhanced application can now list active tasks separately from completed tasks. This is useful because users often need to focus only on unfinished work.

The filtering process also uses a linear traversal of the task collection, adding matching tasks to a result vector. This demonstrates my ability to select and apply a simple but effective algorithm based on the needs of the application.

### Sorting by Priority and Due Date

I also added sorting functionality. The enhanced application can sort tasks by priority and by due date. Sorting by priority allows high-priority tasks to appear before lower-priority tasks, while sorting by due date allows the user to view tasks in chronological order.

These features demonstrate the use of comparison-based sorting with a time complexity of approximately `O(n log n)`. This enhancement shows that I can use standard algorithmic tools to improve the usability and organization of application data.

### Highest-Priority Task Retrieval

In addition, I added a highest-priority task feature using a priority queue. This feature recommends the next active task based on task priority.

The use of a priority queue is important because it shows the use of a specialized data structure rather than only relying on vectors or maps. This demonstrates my understanding of how different data structures can be selected based on the type of problem being solved.

## Overall Improvement

Overall, the artifact was improved from a basic in-memory task service into a more complete C++ task management system with searchable, sortable, filterable, and priority-based task organization. These changes make the application more useful while also demonstrating stronger knowledge of algorithms and data structures.

## Course Outcome Alignment

This enhancement aligns most directly with Course Outcome Three: designing and evaluating computing solutions that solve a given problem using algorithmic principles and computer science practices and standards appropriate to the solution while managing the trade-offs involved in design choices.

The enhancement demonstrates this outcome because I had to evaluate the limitations of the original artifact and choose appropriate algorithms and data structures to improve it. The original project used a `HashMap` for basic ID-based task storage, which was useful for fast lookup but did not support advanced organization.

In the enhanced C++ version, I used a combination of structures and algorithms, including:

* Vectors
* Searching
* Filtering
* Sorting
* A priority queue

Each choice involved a trade-off. For example, linear search is simple and appropriate for a small task manager, but it would not be the most efficient option for a much larger data set. Sorting the vector creates an organized view of the task data without permanently changing the stored tasks, which improves usability while keeping the design safe and understandable.

This enhancement also supports Course Outcome Four because the project demonstrates the use of well-founded computing techniques and tools to create a more valuable software solution. Rewriting the artifact in C++ required me to apply object-oriented design, modular file organization, input validation, persistent storage, and command-line interaction. While the main focus of this milestone is algorithms and data structures, the project also shows growth in software engineering and implementation practices.

I believe I met the outcome coverage that I planned in Module One. My original plan for the algorithms and data structures category included searching, sorting, filtering, and priority-based organization. The completed enhancement includes each of those features. I do not need to make major changes to my outcome-coverage plan, but I would describe the final version more specifically by mentioning the priority queue and the time complexity of the implemented algorithms.

## Reflection on the Enhancement Process

The process of enhancing this artifact helped me better understand how algorithms and data structures affect the usefulness of an application. Before the enhancement, the project could store and manage tasks, but the user had very limited control over how tasks were viewed or organized. By adding searching, filtering, sorting, and priority-based retrieval, I learned how algorithmic features can directly improve the user experience.

One important lesson I learned was that the task model must support the algorithms the application needs. The original Java version only included a task ID, name, and description. In the enhanced C++ version, I needed additional fields such as priority, due date, completion status, and timestamp. Without these fields, features like sorting by due date, filtering completed tasks, or finding the highest-priority active task would not be possible. This helped me see how data design and algorithm design are closely connected.

Another lesson I learned was the importance of separating responsibilities within the program. The parser handles user commands, the task service handles application logic, and the repository handles saving and loading task data. This separation made it easier to add new algorithmic features because the logic could be placed in the task service without making the parser or repository overly complicated.

One challenge I faced was making sure the new task fields worked correctly with the existing JSON persistence system. After adding fields such as description, priority, and due date, I had to update both the save and load logic so the data would persist between program runs. I also had to make sure older task records that did not include the new fields did not cause the program to fail.

Another challenge was debugging command parsing issues. For example, the `sort` command needed to correctly separate the main command from its argument, such as recognizing `sort` as the command and `due` as the argument. Fixing this helped me better understand how command-line parsers process user input and why clean parsing logic is important.

A final challenge was ensuring that completed tasks displayed correctly in the list output. This required checking both the service logic that updates a task’s completion status and the display logic that prints `[x]` for completed tasks. This was a useful reminder that a feature is not complete unless the underlying data and the user-facing output both behave correctly.

Overall, this enhancement helped me grow as a developer because it required me to think beyond basic functionality. I had to consider how data should be stored, how users would want to interact with that data, which algorithms were appropriate for each feature, and how to explain the efficiency and trade-offs of those choices.

The completed enhancement demonstrates my ability to apply algorithms and data structures in a practical software project while improving the quality and usefulness of the original artifact.

[Return to Home](index.md)
