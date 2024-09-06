# Basic Library Management System

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
├── .gitignore
├── CMakeLists.txt
├── CMakePresets.json
└── README.md

```

Main program go in [app/](app),
Sources go in [src/](app/src),
Header files go in [header/](app/header), 
Database files go in [database/](app/database).

## How to Compile and Run the Project

## Way 1: Using Microsoft Visual Studio IDE 

  1. Open Microsoft Visual Studio IDE.
  2. Choose `Clone a repository`.
  3. Copy this url
  ```bash
  https://github.com/Mahmoud-M-Saad/Library-System.git
  ```
  4. Open Library-System --> app --> main.cpp
  5. Run the compiler or click f5. 

## Way 2: Using Bash 

  1. Clone the repository to your local machine:

  ```bash
  git clone https://github.com/Mahmoud-M-Saad/Library-System.git
  cd Library-System
  ```

  2. Run the compiler.

## Finally

Hope you enjoy our Library 😊
