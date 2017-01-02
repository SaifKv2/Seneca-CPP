#include "Enrollment.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

Enrollment::Enrollment() {
	check = false;
}

Enrollment::Enrollment(const char* n, const char* c, int y, int t, int s) {

  if (y >= 2015 && t > 0 && t < 3 && s > 0) {	
	course = new char[strlen(n) + 1];
	strcpy(course, n);
		
	code = new char[strlen(c) + 1];
	strcpy(code, c);
		
	year = y;
	term = t;
	slot = s;

	check = true;
  }
  else {
    check = false;
  }
}

Enrollment::~Enrollment() {

	delete[]course;
	delete[]code;
}

void Enrollment::enroll(char* n, char* c, int y, int t, int s) {

  if (year >= 2015 && term > 0 && term < 3 && slot > 0 && n != NULL && c != NULL) {   
	course = new char[strlen(n) + 1];
	strcpy(course, n);
	code = new char[strlen(c) + 1];
	strcpy(code, c);
		
	year = y;
	term = t;
	slot = s;

	check = true;
  }
  else {
	check = false;
  }
}

bool Enrollment::isEnrolled() const {
	if (check) {
		return true;
	}
	else {
		return false;
	}
}

void Enrollment::withdraw() { 
	delete[]course;
	delete[]code;
	year = 0;
	term = 0;
	slot = 0;
	check = false;

	cout << "The student is successfully withdrawn!" << endl;
}

bool Enrollment::hasConflict(const Enrollment &other) const {

	if (year == other.year && term == other.term && slot == other.slot) {
		return true;
	}
	else {
		return false;
	}
}

void Enrollment::display() const {

	if (isEnrolled() == false) {
		cout << "Student not enrolled!" << endl;
	}
	else {
		cout << course << '\n' << code << '\t' << "Year: " << year
		<< '\n' << "Term: " << term << ' ' << "Slot: " << slot << endl;
	}
}