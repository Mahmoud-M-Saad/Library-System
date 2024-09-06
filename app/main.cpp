//========* Libaray System *======== 
//========* Mahmoud Saad Mon-Thu 6:00pm *======== 

#include <iostream>
#include <conio.h>
#include <cstdlib> 
#include <string> 
#include <cstring>
#include "book.h"
#include "generalFunctions.h"
#include "user.h"
using namespace std;

int main() {
	int option = 0;
	bool isAdmin = false;
	char isNew;
	initBooks();
	while (true) {
	LoginPage:
		system("cls");
		cout << "\033[1;34m";
		printLargeText("MSaad Library");
		cout << "\033[0m" << endl;

		isAdmin = login_or_signUp();

		while (true) {
			printOptions(isAdmin);

		Options:
			cout << "Select an option: ";
			cin >> option;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				errorMsg("Invalid option. Please provide only numbers from these options.");
				goto Options;
			}
			cout << endl;

			switch (option) {
			case 1:
				isAdmin ? createBookFromAdmin() : getBookIndexByID();
				//_getch();
				cout << endl << endl; system("PAUSE");
				break;

			case 2:
				isAdmin ? removeBook() : borrowBook();
				//_getch();
				cout << endl << endl; system("PAUSE");
				break;

			case 3:
				isAdmin ? updateBook() : returnBook();
				//_getch();
				cout << endl << endl; system("PAUSE");
				break;

			case 4:
				isAdmin ? showAllBooks() : showAvailableBooks();
				//_getch();
				cout << endl << endl; system("PAUSE");
				break;

			case 5:
				goto LoginPage;
				break;

			case 6:
				cout << "\033[1;34mThank you for visiting the MSaad Library. "
					<< "We hope to see you again soon.\033[0m" << endl;
				//_getch();
				cout << endl << endl; system("PAUSE"); exit(0);
				break;

			default:
				errorMsg("Invalid option! Please choose one of these options.");
				//_getch();
				cout << endl << endl; system("PAUSE");
				break;
			};
		};
	};
};
