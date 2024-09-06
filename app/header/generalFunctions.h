#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include "user.h"
using namespace std;

const bool login_or_signUp();

const void printOptions(bool isAdmin);

const void errorMsg(string msg);

const void successMsg(string msg);

void printLargeText(string text);