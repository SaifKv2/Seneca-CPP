// OOP244 Workshop 7: compositions
// File	Ship.h
// Version 1.0
// Date 2015-07-30
// Author	Ben Mantle-Williams
// Description
// Ship class declaration
/////////////////////////////////////////////////////

#ifndef _244_SHIP_H_
#define _244_SHIP_H_
#include "Engine.h"

namespace oop244 {
    
    class Ship {
        
        int _len;
        char _shipType[7];
        Engine _obj[10];
        
    public:
        Ship();
        Ship(const char* shipType, const Engine obj[], int len);
        bool empty() const;
        double calculatePower() const;
        bool operator<(double);
        std::ostream& display(std::ostream& os) const;
    };
    
    std::ostream& operator<<(std::ostream&, const Ship&);
}

#endif