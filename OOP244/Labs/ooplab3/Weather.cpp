#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Weather.h"
using namespace std;

void Weather::set(const char* date_D, double hi, double lo) {

    strcpy(date_description, date_D);
    high = hi;
    low = lo;
}

void Weather::display() const {

    cout << fixed << left << setfill('_') << setw(10) << date_description << fixed << left << setfill('_') << setw(6) << setprecision(1) << high << low << endl;
}