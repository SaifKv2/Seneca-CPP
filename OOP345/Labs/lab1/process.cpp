// OOP345 Workshop 1: From One Translation Unit to Another
// File Process.cpp
// Version 1.0
// Date 2016-01-23
// Author Ben Mantle
/////////////////////////////////////////////////

#include "process.h"

	void process(char* parm) {
		w1::CString cs(parm);
		std::cout << cs << "\n";
	}
