#include "FlyingPoints.h"

FlyingPoints::FlyingPoints() {
	in = 0;
	out = 0;
}

FlyingPoints::FlyingPoints(int _in, int _out) {
	in = _in;
	out = _out;
}

int FlyingPoints::getIn() const {
	return in;
}
int FlyingPoints::getOut() const {
	return out;
}

void FlyingPoints::updateBalance() {
    
	if (in > out) {
		in -= out;
		out = 0;
	}
	else {
		out -= in;
		in = 0;
	}
}

void FlyingPoints::display() const {
	cout << in << " points available fly." << endl;
	cout << out << " points spent." << endl;
}

FlyingPoints& FlyingPoints::operator+=(const FlyingPoints& f) {
    
	in += f.in;
	out += f.out;

	updateBalance();

	return *this;
}

FlyingPoints operator+(const FlyingPoints& f1, const FlyingPoints& f2) {
    
	FlyingPoints replace(f1.getIn(), f1.getOut());
	replace += f2;

	return replace;
}

bool operator==(const FlyingPoints& f1, const FlyingPoints& f2) {
    
	FlyingPoints replace1, replace2;

	replace1 += f1;
	replace2 += f2;

	return replace1.getIn() == replace2.getIn() && replace1.getOut() == replace2.getOut();
}