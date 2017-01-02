#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class FlyingPoints {
    
	int in, out;
	void updateBalance();
    
public:
	FlyingPoints();
	FlyingPoints(int, int);
	int getIn() const;
	int getOut() const;
	void display() const;
	FlyingPoints& operator+=(const FlyingPoints& f);
	friend bool operator == (const FlyingPoints&, const FlyingPoints&);
};

FlyingPoints operator+(const FlyingPoints&, const FlyingPoints&);