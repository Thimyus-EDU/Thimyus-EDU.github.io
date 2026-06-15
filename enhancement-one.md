# Enhancement One: Software Design and Engineering

## Overview

The first enhancement focuses on software design and engineering. The original artifact was a Java task management project that demonstrated basic object-oriented programming and service-layer logic. For this enhancement, I rewrote and expanded the artifact into a modular C++ command-line task management application.

## Enhancement Summary

The enhanced version separates the application into focused components:

* `Task` defines the task data model.
* `Parser` interprets user commands.
* `TaskService` handles business logic.
* `Repository` manages persistence.
* `main.cpp` controls the application loop.

This structure improves maintainability because each part of the application has a clear responsibility. The parser does not manage storage, the repository does not control user commands, and the main program does not contain all application logic.

## Skills Demonstrated

This enhancement demonstrates:

* Modular software architecture
* C++ application development
* Command-line interface design
* Separation of concerns
* Input validation and error handling
* Persistent storage integration
* Improved control flow
* Maintainable file organization

## Course Outcome Alignment

This enhancement supports the course outcomes related to designing and evaluating computing solutions, using well-founded computing techniques and tools, communicating technical decisions, and applying a security mindset through validation and defensive programming.

## Supporting Files

* [Software Design and Engineering Narrative](narratives/NarrativeOne.md)
* [Enhanced Source Code](artifacts/enhanced/)
* [Original Source Code](artifacts/original/)

