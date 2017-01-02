// OOP345 Workshop 1: From One Translation Unit to Another
// File w1.cpp
// Version 1.0
// Date 2016-01-21
// Author Ben Mantle
/////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "CString.h"
#include "process.h"

using namespace std;
// using namespace w1;

	int main(int argc, char* argv[]) {

		cout << "Command Line : "; // << argv[0]
		for (int arg = 0; arg < argc; arg++) {
			cout << " " << argv[arg];
		}

		cout << "\n";

		if (argc == 1) { 
			cout << "Insufficient number of arguments (min 1)\n";
			return 1;
		}

		cout << "Maximum number of characters stored : " << MAX << "\n";
		for (int arg = 1; arg < argc; arg++) {
			process(argv[arg]);
		}

		return 0;
	}
