#pragma once
#include <iostream>
#include <conio.h>
#include <cstdlib> 
#include <string> 
#include <cstring>
#include <vector>
#include <fstream>
#include "json.hpp"
#include "generalFunctions.h"
using namespace std;
using json = nlohmann::json;

struct Book {
    int ID;
    string title;
    string description;
    char section;
    int copies;
    string author;
    int owned;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Book, ID, title, description, section, copies, author, owned)

    void displayInfo() const;
    void marketingShow() const;
};

vector<Book> getBooksFromJSON();
void saveBooksToJSON(const vector<Book>& books);

void printBooks();
//! Validation functions
const void initBooks();
static int valid_id();
static string valid_title();
static string valid_description();
static string valid_author();
static int valid_copies();
static char valid_section();

//! Admin Functions
void createBookFromAdmin();
void removeBook();
void updateBook();
void showAllBooks();

//! User Functions
void getBookIndexByID();
void borrowBook();
void returnBook();
void showAvailableBooks();





