# Enhancement Two: Data Structures and Algorithms

## Overview

The second enhancement focuses on algorithms and data structures. The original task management artifact included basic task storage and task service operations, but it did not provide advanced ways to organize, search, filter, or prioritize tasks. For this enhancement, I expanded the application so users could interact with task data in more useful ways.

## Enhancement Summary

This enhancement added several features that improved how task data is organized and retrieved:

* Search tasks by keyword
* Filter active and completed tasks
* Sort tasks by priority
* Sort tasks by due date
* Retrieve the highest-priority active task

These features make the application more practical because users are no longer limited to viewing tasks only in the order they were created. Instead, users can search for specific work, focus on unfinished tasks, organize tasks by importance, view upcoming due dates, and identify the next task that should receive attention.

## Algorithms and Data Structures Used

The search feature uses a linear search approach to compare the user’s search term against task titles and descriptions. This approach has a time complexity of O(n), which is appropriate for the size and scope of this type of command-line task management application.

The filtering feature also uses linear traversal. It examines the task collection and returns tasks that match a specific completion status. This allows the user to view active tasks separately from completed tasks.

The sorting features use comparison-based sorting. Sorting by priority places higher-priority tasks before lower-priority tasks, while sorting by due date organizes tasks chronologically. These features demonstrate the use of standard sorting logic to improve the usefulness of application data.

The highest-priority task feature demonstrates priority-based retrieval. This feature helps identify the next active task based on importance, showing how a specialized data structure or priority-focused logic can improve decision making in an application.

## Skills Demonstrated

This enhancement demonstrates:

* Algorithmic problem solving
* Linear search
* Filtering through collection traversal
* Comparison-based sorting
* Priority-based task retrieval
* Data model expansion
* Evaluation of time complexity
* Selection of appropriate data structures
* Practical use of algorithms to improve user experience

## Course Outcome Alignment

This enhancement most directly supports the course outcome related to designing and evaluating computing solutions using algorithmic principles and computer science practices. It demonstrates the ability to select algorithms and data structures based on the needs of the application while considering trade-offs.

For example, linear search is not the most efficient approach for very large datasets, but it is simple, readable, and appropriate for a small command-line task manager. Sorting provides organized task views without permanently changing the meaning of the stored task data. Priority-based retrieval improves usability by helping users determine which task should receive attention first.

This enhancement also supports the outcome related to using well-founded computing techniques and tools because it applies standard programming practices to create a more valuable and functional software solution.

## Supporting Files

* [Algorithms and Data Structures Narrative](narratives/NarrativeTwo.docx)
* [Enhanced Source Code](artifacts/enhanced/)
* [Original Source Code](artifacts/original/)

[Return to Home](index.md)

