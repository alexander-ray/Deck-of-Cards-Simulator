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

// String.tolower
string Helper::toLowerCase(string s) {
	for (int i = 0; i < s.length(); i++) {
		s[i] = tolower(s.at(i)); // Changing each char to lowercase
	}
	return s;
}

// Function to change "one" to "1", etc if applicable
string Helper::alphaToDigit(string s) {
	if (s == "two")
		return "2";
	else if (s == "three")
		return "3";
	else if (s == "four")
		return "4";
	else if (s == "five")
		return "5";
	else if (s == "six")
		return "6";
	else if (s == "seven")
		return "7";
	else if (s == "eight")
		return "8";
	else if (s == "nine")
		return "9";
	else 
		return s;
}

// Change "diamonds" to "diamond"
string Helper::suitPluralToSingular(string s) {
	if (s == "diamonds")
		return "diamond";
	else if (s == "hearts")
		return "heart";
	else if (s == "clubs")
		return "club";
	else if (s == "spades")
		return "spade";
	else
		return s;
}


