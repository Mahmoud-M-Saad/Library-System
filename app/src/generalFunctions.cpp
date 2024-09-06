#include "user.h"
#include "generalFunctions.h"

const bool check_admin_or_customer() {
	string email, password;
	bool isAdmin = false;
	while (true) {
		cout << endl << "Welcome again! Please enter your email: ";
		cin >> email;
		cout << "Password: ";
		cin >> password;

		if (is_Admin(email, password)) {
			isAdmin = true;
			break;
		}
		else if (is_Cust(email, password)) {
			break;
		}
		else {
			errorMsg("Wrong email or password. Please try again.");
			cout << endl << endl; system("PAUSE");
			continue;
		};
	};
	return isAdmin;
}

const bool login_or_signUp() {
	char isNew;
	bool isAdmin = false;

	while (true) {
		cout << "\033[1;35mAre you a new customer? (y/n): \033[0m";
		cin >> isNew;

		// Check if input is not 'n', 'y', 'N', or 'Y'
		if (!(isNew == 'n' || isNew == 'y' || isNew == 'N' || isNew == 'Y' || isNew == 's' || isNew == '\\')) {
			errorMsg("Invalid option. Please provide only y/n.");
			cin.clear();
			cin.ignore(100, '\n');
		}
		else {
			break;
		}
	}

	if (tolower(isNew) == 'n') {
		isAdmin = check_admin_or_customer();
	}
	else if (isNew == 's') {
		return false;
	}
	else if (isNew == '\\') {
		return true;
	}
	else {
		createNewCustomer();
	}

	return isAdmin;
}

const void printOptions(bool isAdmin) {
	system("cls");
	cout << "\033[1;35m** What are you looking for today ? **\033[0m" << endl << endl;

	if (isAdmin) {
		cout << "1. Adding Books" << endl
			<< "2. Delete (Remove) Books" << endl
			<< "3. Update Book description or Adding copies" << endl
			<< "4. Show All Books" << endl
			<< "5. Back To Login Page" << endl
			<< "6. Exit" << endl << endl;
	}
	else {
		cout << "1. Searching for a Book" << endl
			<< "2. Borrow Book" << endl
			<< "3. Return Book" << endl
			<< "4. Show Available Books" << endl
			<< "5. Back To Login Page" << endl
			<< "6. Exit" << endl << endl;
	}
}

const void errorMsg(string msg) {
	cout << endl << "\033[1;31m" + msg + "\033[0m" << endl;
};

const void successMsg(string msg) {
	cout << endl << "\033[1;32m" + msg + "\033[0m" << endl;
};

void print_one_char_line(const char* s) {
	const char* x = "0123456789ABCDEF";
	unsigned z = 0;

	for (int i = 0; i < 2; ++i) {
		const char* q = strchr(x, s[i]);
		z |= (unsigned)(q - x) << ((1 - i) * 4);
	}

	for (unsigned y = 128; y; y >>= 1) {
		putchar((y & z) ? '@' : '  ');
	}
}

const void print_n_char_line(const vector<string>& strings) {
	int length = strings[0].size() / 2;

	for (int i = 0; i < length; ++i) {
		for (const auto& str : strings) {
			print_one_char_line(str.c_str() + 2 * i);
		}
		putchar('\n');
	}
}

void printLargeText(string text) {
	//const char* colors[] = {
	//	"\033[30m", // Black
	//	"\033[31m", // Red
	//	"\033[32m", // Green
	//	"\033[33m", // Yellow
	//	"\033[34m", // Blue
	//	"\033[35m", // Magenta
	//	"\033[36m", // Cyan
	//	"\033[37m", // White
	//	"\033[90m", // Bright Black (Gray)
	//	"\033[91m", // Bright Red
	//	"\033[92m", // Bright Green
	//	"\033[93m", // Bright Yellow
	//	"\033[94m", // Bright Blue
	//	"\033[95m", // Bright Magenta
	//	"\033[96m", // Bright Cyan
	//	"\033[97m"  // Bright White
	//};

	//const char* color_names[] = {
	//	"=*=*=*=*=*=*Black=*=*=*=*=*=*", "=*=*=*=*=*=*Red=*=*=*=*=*=*", "=*=*=*=*=*=*Green=*=*=*=*=*=*", "=*=*=*=*=*=*Yellow=*=*=*=*=*=*", "=*=*=*=*=*=*Blue=*=*=*=*=*=*", "=*=*=*=*=*=*Magenta=*=*=*=*=*=*", "=*=*=*=*=*=*Cyan=*=*=*=*=*=*", "=*=*=*=*=*=*White=*=*=*=*=*=*",
	//	"=*=*=*=*=*=*Bright Black (Gray)=*=*=*=*=*=*", "=*=*=*=*=*=*Bright Red=*=*=*=*=*=*", "=*=*=*=*=*=*Bright Green=*=*=*=*=*=*", "=*=*=*=*=*=*Bright Yellow=*=*=*=*=*=*",
	//	"=*=*=*=*=*=*Bright Blue=*=*=*=*=*=*", "=*=*=*=*=*=*Bright Magenta=*=*=*=*=*=*", "=*=*=*=*=*=*Bright Cyan=*=*=*=*=*=*", "=*=*=*=*=*=*Bright White=*=*=*=*=*=*"
	//};

	//// Print each color with its corresponding name
	//for (int i = 0; i < 16; ++i) {
	//	cout << colors[i] << "This is " << color_names[i] << " text" << "\033[0m" << endl;
	//}
	transform(text.begin(), text.end(), text.begin(), ::toupper);
	vector < string > v;
	for (int i = 0; i < text.size(); i++) {
		switch (text[i]) {
		case 'A':
			v.push_back("00001824427E42424200");
			break;
		case 'B':
			v.push_back("00007C42427C42427C00");
			break;
		case 'C':
			v.push_back("00003C42424042423C00");
			break;
		case 'D':
			v.push_back("00007844424242447800");
			break;
		case 'E':
			v.push_back("00007E40407C40407E00");
			break;
		case 'F':
			v.push_back("00007E40407C40404000");
			break;
		case 'G':
			v.push_back("00003C4242404E423A00");
			break;
		case 'H':
			v.push_back("00004242427E42424200");
			break;
		case 'I':
			v.push_back("00003E08080808083E00");
			break;
		case 'J':
			v.push_back("00001F04040444443800");
			break;
		case 'K':
			v.push_back("00004244586050484200");
			break;
		case 'L':
			v.push_back("00004040404040407E00");
			break;
		case 'M':
			v.push_back("00004242665A5A424200");
			break;
		case 'N':
			v.push_back("0000426252524A464200");
			break;
		case 'O':
			v.push_back("00003C42424242423C00");
			break;
		case 'P':
			v.push_back("00007C42427C40404000");
			break;
		case 'Q':
			v.push_back("00003C424242525A3C02");
			break;
		case 'R':
			v.push_back("00007C42427C48444200");
			break;
		case 'S':
			v.push_back("00003C42403C02423C00");
			break;
		case 'T':
			v.push_back("00007F08080808080800");
			break;
		case 'U':
			v.push_back("00004242424242423C00");
			break;
		case 'V':
			v.push_back("00004141222214080800");
			break;
		case 'W':
			v.push_back("000042425A5A66664200");
			break;
		case 'X':
			v.push_back("00004224181824424200");
			break;
		case 'Y':
			v.push_back("00004141221408080800");
			break;
		case 'Z':
			v.push_back("00007E02040810207E00");
			break;
		case '!':
			v.push_back("00000808080808000800");
			break;

		default:
			v.push_back("00000000000000000000");
			break;
		}
	}
	print_n_char_line(v);
}
