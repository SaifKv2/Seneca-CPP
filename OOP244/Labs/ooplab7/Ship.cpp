// OOP244 Workshop 7: compositions
// File	Ship.cpp
// Version 1.0
// Date 2015-07-30
// Author	Ben Mantle-Williams
// Description
// Ship class implementation
/////////////////////////////////////////////////////

#include <cstring>
#include <iomanip>
#include "Ship.h"
#include "Engine.h"

namespace oop244 {
    
    Ship::Ship() {
        _shipType[0] = '\0';
        _len = 0;
    }
    
    Ship::Ship(const char* shipType, const Engine obj[], int len) {
        
        strcpy(_shipType, shipType);
        _len = len;
        for (int i = 0; i < len; i++)
            _obj[i] = obj[i];
    }
    
    bool Ship::empty() const {
        return _shipType[0] == '\0' && _len == 0;
    }
    
    double Ship::calculatePower() const {
        
        double power = 0.0;
        
        for (int i = 0; i < _len; i++) {
            power += _obj[i].get() * 5;
        }
        return power;
    }
    
    std::ostream& Ship::display(std::ostream& os) const {
        
        os << _shipType << "-" << std::fixed << std::setw(6) << std::setprecision(2) << calculatePower() << std::endl;
        
        for (int i = 0; i < _len; i++) {
            _obj[i].display(os);
        }
        return os;
    }
    
    bool Ship::operator<(double MIN) {
        return calculatePower() < MIN;
    }
    
    std::ostream& operator<<(std::ostream& os, const Ship& a) {
        return a.display(os);
    }
}