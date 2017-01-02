// OOP345 Workshop 1: From One Translation Unit to Another
// File CString.cpp
// Version 1.0
// Date 2016-01-23
// Author Ben Mantle
/////////////////////////////////////////////////

#include "CString.h"

namespace w1 {
	CString::CString(char* str) {
		if (str == NULL) {
			_str[0] = '\0';
			return;
		}

		strncpy(_str, str, MAX);
		_str[MAX] = '\0';
	}

	void CString::display(std::ostream& os) {
		os << _str;
	}

	std::ostream& operator<<(std::ostream& os, CString cs) {
		static int calls = 0;
		os << calls++ << ": ";
		cs.display(os);

		return os;
	}
}
