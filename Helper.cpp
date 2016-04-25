#include "Helper.h"
#include <iostream>
#include <stdio.h>

using namespace std;

Helper::Helper(){};

Helper::~Helper(){};

// Checking if a string is composed entirely of digits
bool Helper::isInt (string s) {
    for (int i = 0; i < s.length(); i++) {
        if (!isdigit(s.at(i))) // Checking if char is a digit
            return false;
    }
    return true;
}

string Helper::toLowerCase(string s) {
	for (int i = 0; i < s.length(); i++) {
		s[i] = tolower(s.at(i));
	}
	return s;
}