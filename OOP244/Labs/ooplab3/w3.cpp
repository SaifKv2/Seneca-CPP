// OOP244 Workshop 3: Dynamic Memory
// File w3.cpp
// Date 2015/06/03
// Author Benjamin Mantle-Williams
// 064329147
// This file is used to demonstrate dynamic memory in
// C++ and to process an array of objects of compound
// type where the user specifies the number of
// elements in the array at run-time.
/////////////////////////////////////////////////////

#include <iostream>
#include "Weather.h"
using namespace std;

int main() {
    
    int n;
    Weather* user = NULL;
    
    cout << "Weather Data\n";
    cout << "=====================" << endl;
    cout << "Days of Weather: ";
    cin >> n;
    
    user = new Weather[n];
    
    for(int i = 0; i < n; i++) {
        
        char date_description[31];
        double high, low;
        
        cin.ignore();
        cout << "Enter date: ";
        cin.getline(date_description, 30);
        cout << "Enter high: ";
        cin >> high;
        cout << "Enter low: ";
        cin >> low;
        
        user[i].set(date_description, high, low);
        cout <<endl;
    }
    
    cout << "Weather report:\n";
    cout << "==================" << endl;
    
    for (int i = 0; i < n; i++) {
        
        user[i].display();
        cout << endl;
    }
    
    delete[] user;
    user = NULL;
    //getchar();
    //getchar();
    
    return 0;
}