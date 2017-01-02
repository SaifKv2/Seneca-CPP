// Workshop 6 - Lambda Expression
// w6.cpp

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Grades.h"

int main(int argc, char* argv[]) {
    
	if (argc != 2) {
		std::cerr << argv[0] <<
			": incorrect number of arguments\n";
		std::cerr << "Usage: " << argv[0] << " file_name\n";
		return 1;
	}

	Grades grades(argv[1]);
	
	auto letter = [=](double grade) {

		auto _letter = "F";

		if (grade >= 90) {
			_letter = "A+";
		}
		else if (grade >= 80) {
			_letter = "A";
		}
		else if (grade >= 75) {
			_letter = "B+";
		}
		else if(grade >= 70) {
			_letter = "B";
		}
		else if(grade >= 65) {
			_letter = "C+";
		}
		else if(grade >= 60) {
			_letter = "C";
		}
		else if(grade >= 55) {
			_letter = "D+";
		}
		else if(grade >= 50) {
			_letter = "D";
		}
		else {
			_letter = "F";
		}
		
		return _letter;
	};

	grades.displayGrades(std::cout, letter);

	std::cout << "Press any key to continue ... ";
	std::cin.get();
}