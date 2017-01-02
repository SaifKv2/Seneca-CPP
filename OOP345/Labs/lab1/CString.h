// OOP345 Workshop 1: From One Translation Unit to Another
// File CString.h
// Version 1.0
// Date 2016-01-23
// Author Ben Mantle
/////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#pragma once // avoiding problems with #includes

#include <iostream>
#include <cstring>

const int MAX = 3;

namespace w1 {
	class CString {
		char _str[MAX + 1];
	public:
		CString(char* str);
		void display(std::ostream& os);
	};

	std::ostream& operator<<(std::ostream& os, CString cs);
}
