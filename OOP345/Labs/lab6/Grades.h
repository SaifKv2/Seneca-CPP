#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

class Grades {
	int studentNo;
	std::vector<double> grade;
	std::vector<int> studentId;
public:
	Grades() { // default vals
		studentNo = 0;
		int studentId = int();
		double grade = double();
	}

	Grades(const char* filename) { // ctor 
		studentNo = 0;
		std::ifstream is(filename);

		if (is) {
			std::fstream is; // input
			is.open(filename);
			
			if (!is) {
				throw std::string("Cannot open the file: ");
			}

			// read
			std::string s;
			while (!is.eof()) {

				getline(is, s, ' ');
				studentId.push_back(atoi(s.c_str()));

				getline(is, s, '\n');
				grade.push_back(atof(s.c_str()));

				studentNo++;
			}
		}

		else {
			std::cerr << "Failed to open " << filename << "." << std::endl;
		}
		is.close();
		
	}
	
	template <typename T>
	void displayGrades(std::ostream& os, T t) const {
		
		for (int i = 0; i < studentId.size(); i++) {
			std::cout << studentId[i] << " " << std::fixed << std::setprecision(2) << grade[i] << " " << t(grade[i]) << std::endl;
		}
	}
};