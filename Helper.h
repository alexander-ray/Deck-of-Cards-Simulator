#ifndef HELPER_H
#define HELPER_H
#include <iostream>

using namespace std; 

class Helper {
	public:
		Helper();
		~Helper();
		bool isInt(string s);
		string toLowerCase(string s);
		string alphaToDigit(string s);
};

#endif