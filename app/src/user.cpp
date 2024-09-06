#include "user.h"
//! JSON Functions 
static vector<User> getUsersFromJSON() {
	ifstream file("database/users.json");
	if (!file.is_open()) {
		cout << "The JSON file does not exist. Initializing an empty user list." << endl;
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

	return j.get<vector<User>>();
}

static vector<User> Users = getUsersFromJSON();

static void saveUsersToJSON(const vector<User>& users) {
	ofstream file("database/users.json");
	json j = users;
	file << j.dump(4);
}
void printUser() {
	for (int i = 0; i < Users.size(); i++)
	{
		cout << Users[i].name;

	}
}
//! Validation Functions
bool is_Admin(string email, string password) {
	return (Users[0].email == email && Users[0].password == password);
};
bool is_Cust(string email, string password) {
	for (int i = 1; i < Users.size(); i++) {
		if (Users[i].email == email && Users[i].password == password) {
			return true;
		}
	}
	return false;
};

string get_name_by_email(string email) {
	for (int i = 0; i < Users.size(); i++) {
		if (Users[i].email == email) {
			return Users[i].name;
			break;
		}
	}
	return "Not Found";
};

/*
#include <unordered_map>

// Use an unordered_map to store books by their ID
std::unordered_map<int, Book> bookMap;

// Function to initialize the map from the vector of books
void initializeBookMap(const std::vector<Book>& Books) {
	for (const auto& book : Books) {
		bookMap[book.ID] = book;
	}
}

// Function to find a book by ID using the map
string findBookTitleByID(int ID) {
	auto it = bookMap.find(ID);
	if (it != bookMap.end()) {
		return it->second.title;
	}
	return "";
}
*/

//! User Functions
//void createUser(string name, string email, string password, string role) {
//	if (usersCount < 100) {
//		users[usersCount][0] = name;
//		users[usersCount][1] = email;
//		users[usersCount][2] = password;
//		users[usersCount][3] = role;
//		usersCount++;
//		successMsg("Customer created successfully with id: " + to_string(usersCount - 1));
//	}
//	else {
//		errorMsg("Sorry! You have reached your '100' user limit.");
//	}
//}

static string valid_name() {
	string name;
	while (true) {
		cout << endl << "\033[1;35mWelcome to our Library!\033[0m\nLet's start with your name: ";
		cin.ignore(); getline(cin, name);

		regex nameRegex(R"([a-zA-Z\s]+)");

		if (!name.empty() && regex_match(name, nameRegex)) {
			int spacePos = name.find(' ');
			string firstName = (spacePos != string::npos) ? name.substr(0, spacePos) : name;

			system("cls");

			if (firstName.size() > 10) {
				cout << "Hi!" + name << endl << endl;
			}
			else {
				cout << "\033[1;32m";
				printLargeText("HI! " + firstName);
				cout << "\033[0m" << endl;

			}
			return name;
		}
		errorMsg("Name cannot be empty and must contain only alphabetic characters.\nPlease enter a valid name.");
	}
}

static string valid_egyptian_phone() {
	string phone;
	while (true) {
		cout << "Let's log in for you,\nEnter your Egyptian Phone Number: ";
		getline(cin, phone);

		// Regular expression for Egyptian mobile numbers
		regex egyptPhoneRegex(R"(^01[0125][0-9]{8}$)");

		if (regex_match(phone, egyptPhoneRegex)) {
			return phone;
		}

		errorMsg("Invalid phone number. Please enter a valid Egyptian phone number (e.g., 01012345678).");
	}
}

static string valid_email() {
	string email;
	while (true) {
		cout << "Email: ";
		getline(cin, email);

		regex emailRegex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");

		if (!email.empty() && regex_match(email, emailRegex)) {
			if (!(get_name_by_email(email) == "Not Found")) {
				errorMsg("Sorry! this email is already exists.");
			}
			else {
				return email;
			}
		}
		else {
			errorMsg("Invalid email format. Please enter a valid email.");
		}
	}
}

static string valid_password() {
	string password;
	while (true) {
		cout << "Password: ";
		getline(cin, password);

		if (!password.empty() && password.length() >= 8) {
			return password;
		}

		errorMsg("Password must be at least 8 characters long. Please enter a valid password.");
	}
}

void createNewCustomer() {
	string name = valid_name();
	string phone = valid_egyptian_phone();
	string email = valid_email();
	string password = valid_password();
	string role = "Customer";
	int ID = Users[Users.size() - 1].ID + 1;

	User newUser = { ID , name, phone, email, password, role };

	Users.push_back(newUser);
	saveUsersToJSON(Users);
	Users = getUsersFromJSON();
}