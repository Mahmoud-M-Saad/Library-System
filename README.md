# Library Management System

## Project Overview

This project is a simple **Library Management System** implemented in C++. It allows interaction between users and an admin, providing the following features:

- **Admin Features**:
  - Create, Read, Update, and Delete (CRUD) operations on books.
  - View all books and determine if it is available or not.
  - Manage library inventory.

- **User Features**:
  - Borrow books from the library.
  - Return borrowed books.
  - Search for all books by id.

### Project Scope

- The project is designed to be simple and straightforward, focusing on basic C++ programming techniques.
- It is not developed using Object-Oriented Programming (OOP) concepts. Instead, it uses fundamental constructs like functions, loops, arrays, and basic data structures.
- Also, each model is linked to its JSON file to make all their CRUD operations on it.

## Prerequisites

To compile and run this project, you'll need:

- A C++ compiler (e.g., GCC, Clang, MSVC).
- A text editor or an Integrated Development Environment (IDE) such as Visual Studio, Code::Blocks, or VSCode.

## Project Structure
``` text
.
├── app
│    ├── database
│    │       ├── books.json
│    │       └── users.json
│    ├── header
│    │       ├── book.h
│    │       ├── generalFunctions.h
│    │       ├── json.hpp
│    │       └── user.h
│    ├── src
│    │       ├── book.cpp
│    │       ├── generalFunctions.cpp
│    │       └── user.cpp
│    └── main.cpp
├── CMakeLists.txt
├── CMakePresets.json
└── .gitignore

```

Main program go in [app/](app),
Sources go in [src/](src),
Header files go in [header/](header), 
Database files go in [database/](database).

## How to Compile and Run the Project

Step 1: Clone the Repository:

Clone the repository to your local machine:

```bash
git clone https://github.com/Mahmoud-M-Saad/Library-System.git
cd Library-System
```

Step 2: Compile the Project:

Use a C++ compiler like Microsoft Visual Studio to compile the project
  - go to app -> main.cpp
  - run the project


## Finally

Hope you enjoy our Library 😊
