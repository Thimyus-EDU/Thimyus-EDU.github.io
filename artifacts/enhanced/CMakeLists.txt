cmake_minimum_required(VERSION 3.16)

project(task_engine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(task_engine
    main.cpp
    src/cli/parser.cpp
    src/core/task_service.cpp
    src/storage/repository.cpp
)

find_package(SQLite3 REQUIRED)

target_link_libraries(task_engine PRIVATE SQLite::SQLite3)

target_include_directories(task_engine PRIVATE
    include
)