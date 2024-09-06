#include "book.h"

//! JSON Functions 

vector<Book> getBooksFromJSON() {
	ifstream file("database/books.json");
	if (!file.is_open()) {
		cout << "The JSON file does not exist. Initializing an empty book list." << endl;
		return {};
	}

	json j;
	try {
		file >> j;
	}
	catch (json::parse_error& e) {
		cout << "Error parsing JSON: " << e.what() << endl;
		return {};
	}

	return j.get<vector<Book>>();
}

static vector<Book> Books = getBooksFromJSON();

void saveBooksToJSON(const vector<Book>& books) {
	ofstream file("database/books.json");
	json j = books;
	file << j.dump(4);  // Pretty print with 4 spaces
}

void Book::displayInfo() const {
	cout << endl
		<< "Book ID: " << ID << endl
		<< "Title: " << title << endl
		<< "Author: " << author << endl
		<< "Description: " << description << endl
		<< "Section: " << section << endl
		<< "Number of Copies: " << copies << endl;
	(copies > 0) ?
		cout << "It's available for borrowing." << endl :
		cout << "Oops! It's currently out of stock, Please order some for us." << endl;
}

void Book::marketingShow() const {
	cout << "\nIntroducing an unmissable read: \"\033[94m" << title << "\033[0m\"!" << endl
		<< "Dive into the fascinating world of \"\033[94m" << description << "\033[0m\" " << endl
		<< "With this expertly crafted book by renowned author \"\033[33m" << author << "\033[0m\"." << endl
		<< "You can find it exclusively in section \'\033[91m" << section
		<< "\033[0m\', with ID: \'\033[91m" << ID << "\033[0m\'." << endl
		<< "Act fast! Only (\033[91m" << copies << "\033[0m) copies remain. "
		<< "This masterpiece won't stay on the shelves for long!" << endl << endl;
}


void printBooks() {
	for (int i = 0; i < Books.size(); i++)
	{
		cout << Books[i].title;

	}
}
//! Validation functions
static bool isFound(int ID) {
	for (int i = 1; i < Books.size(); i++) {
		if (ID == Books[i].ID) {
			return true;
			break;
		}
	}
	return false;
}

const void initBooks() {
	if (Books.size() <= 1) {
		//! Book newBook0 = { 0, "Title", "Description", 'A', 0, "Author", 0 };
		//! Books.push_back(newBook0);
		Book newBook1 = { 1, "David Copperfield","Journey from an unhappy childhood to a successful novelist",'X',1,"Charles Dickens",1 };
		Books.push_back(newBook1);
		Book newBook2 = { 2, "Moby-Dick","Captain want to hunt down a giant whale",'M', 2, "Herman Melville", 2 };
		Books.push_back(newBook2);
		Book newBook3 = { 3, "Oliver Twist","Orphan boy forced into unjust and cruel situations",'D',0,"Charles Dickens",0 };
		Books.push_back(newBook3);
		saveBooksToJSON(Books);
		Books = getBooksFromJSON();
	}
}

static int valid_id() {
	int ID;
	while (true) {
		cout << endl << "Enter book ID: ";
		cin >> ID;
		if (cin.fail() || !isFound(ID)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			errorMsg("Invalid book ID. Please provide a valid ID. Or Ask MSaad.");

		}
		else {
			return ID;
		}
	}
}

static string valid_title() {
	string title;
	while (true) {
		cout << "Title: ";
		cin.ignore(); getline(cin, title);
		if (!title.empty()) {
			return title;
		}
		errorMsg("Title cannot be empty. Please enter a valid title.");
	}
}

static string valid_description() {
	string description;
	while (true) {
		cout << "Description: ";
		cin.ignore(); getline(cin, description);
		if (!description.empty()) {
			return description;
		}
		errorMsg("Description cannot be empty. Please enter a valid description.");
	}
}

static string valid_author() {
	string author;
	while (true) {
		cout << "Author: ";
		cin.ignore(); getline(cin, author);
		if (!author.empty()) {
			return author;
		}
		errorMsg("Author cannot be empty. Please enter a valid author.");
	}
}

static int valid_copies() {
	int copies;
	while (true) {
		cout << "Number of copies: ";
		cin >> copies;
		if (cin.fail() || copies < 0 || copies > 10) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			errorMsg("Please enter a valid number of copies (0 - 10), Due to Shelf space :D.");
		}
		else {
			return copies;
		}
	}
}

static char valid_section() {
	char section;
	while (true) {
		cout << "In which Section (Capital letter): ";
		cin >> section;
		if (!(section < 'A' || section > 'Z')) {
			return section;
		}
		errorMsg("Section must be an Capital alphanumeric character. Please enter a valid section.");
	}
}

int getBookIndexByID(int ID) {
	for (int i = 1; i < Books.size(); i++) {
		if (ID == Books[i].ID) {
			return i;
			break;
		}
	}
}

//! Admin Functions
void createBookFromAdmin() {
	cout << "Let's Start" << endl;
	string title = valid_title();
	string description = valid_description();
	string author = valid_author();
	int ID = Books[Books.size() - 1].ID + 1;
	int copies = valid_copies();
	int owned = copies;
	char section = valid_section();

	Book newBook = { ID , title, description, section, copies, author, owned };

	Books.push_back(newBook);
	saveBooksToJSON(Books);
	Books = getBooksFromJSON();
	successMsg("Book created successfully with id: " + to_string(ID) + ".");
}

void removeBook() {
	int bookID = valid_id();
	int index = getBookIndexByID(bookID);
	if (Books.size() <= 1) {
		errorMsg("Sorry! we have no books.");
	}
	else {
		Books.erase(Books.begin() + index);
		saveBooksToJSON(Books);
		Books = getBooksFromJSON();
		successMsg("Book with id (" + to_string(bookID) + ") deleted successfully.");
	}
}

void updateDescription() {
	int bookID = valid_id();
	int index = getBookIndexByID(bookID);
	string description = valid_description();
	Books[index].description = description;
	saveBooksToJSON(Books);
	successMsg("Book description successfully updated.");
}

void updateCopies() {
	int bookID = valid_id();
	int copies = valid_copies();
	int index = getBookIndexByID(bookID);
	Books[index].copies += copies;
	if (Books[index].copies > Books[index].owned) {
		Books[index].owned = Books[index].copies;
	}
	saveBooksToJSON(Books);
	successMsg("Great, Thanks for getting more.");
}

void updateBook() {
	int choice;
SelectChoice:
	cout << "What do you want to update: " << endl << endl
		<< "1. Description " << endl
		<< "2. Adding books " << endl << endl
		<< "Select an option: ";
	cin >> choice;
	cout << endl;
	switch (choice) {
	case 1:
		updateDescription();
		break;
	case 2:
		updateCopies();
		break;
	default:
		errorMsg("Invalid option! Please choose one of these options.");
		goto SelectChoice;
		break;
	}
	Books = getBooksFromJSON();
}

void showAllBooks() {
	if (Books.size() <= 1) {
		errorMsg("Sorry! we have no books.");
	}
	else {
		for (int i = 1; i < Books.size(); i++) {
			if (i == 1) {
				cout << "\033[1;35m======================================\033[0m" << endl;
			}
			Books[i].displayInfo();
			cout << "\033[1;35m======================================\033[0m" << endl;
		}
	}
}

//! User Functions
void getBookIndexByID() {
	int bookID = valid_id();
	int index = getBookIndexByID(bookID);
	Books[index].displayInfo();
}

void borrowBook() {
	int bookID = valid_id();
	int index = getBookIndexByID(bookID);
	if (Books[index].copies > 0) {
		successMsg("Enjoy your reading ;)");
		Books[index].copies--;
	}
	else {
		errorMsg("Sorry! Out of stock.");
	}
};

void returnBook() {
	int bookID = valid_id();
	int index = getBookIndexByID(bookID);
	if (Books[index].copies < Books[index].owned) {
		Books[index].copies++;
		successMsg("Hope you enjoy the book!");
	}
	else {
		errorMsg("Sorry! This book not from us.");
	}
};

void showAvailableBooks() {
	bool isFound = false;

	for (int i = 1; i < Books.size(); i++) {
		if (Books[i].copies > 0) {
			if (i == 1) {
				cout << "\033[1;35m======================================\033[0m" << endl;
			}
			isFound = true;
			Books[i].marketingShow();
			cout << "\033[1;35m======================================\033[0m" << endl;
		}
	}

	if (!isFound) {
		errorMsg("We currently have no books in stock. Please check back later.");
	}
}
