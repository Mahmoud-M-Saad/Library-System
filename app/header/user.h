#pragma once
#include <iostream>
#include <conio.h>
#include <fstream>
#include <cstdlib> 
#include <cstring>
#include <regex>
#include <cstdlib>
#include <string>
#include "json.hpp"
#include "generalFunctions.h"
using namespace std;
using json = nlohmann::json;

struct User {
	int ID;
	string name;
	string phone;
	string email;
	string password;
	string role;

	NLOHMANN_DEFINE_TYPE_INTRUSIVE(User, ID, name, phone, email, password, role)
};

static vector<User> getUsersFromJSON();
static void saveUsersToJSON(const vector<User>& users);

//! Local Basic Users Database Table
//!  static string users[100][4] = {
//!  	// {name=0,email=1,pass=2,role=3}
//!  	{},
//!  	{"M Saad","admin@mail.com","123456","admin"},
//!  	{"M Joker","customer@mail.com","654321","customer"}
//!  };
//!  static int usersCount = 3;
//! void createUser(string name, string email, string password, string role);

//! Validation Functions
bool is_Admin(string email, string password);
bool is_Cust(string email, string password);
string get_name_by_email(string email);

//! User Functions
void createNewCustomer();
void printUser();