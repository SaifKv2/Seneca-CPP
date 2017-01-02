// OOP244 Workshop 8: Derived Classes
// File	Hero.h
// Version 1.0
// Date 2015-07-30
// Author	Ben Mantle-Williams
// Description
// ...........
/////////////////////////////////////////////////////

#include "Hero.h"
namespace oop244 {
    
    Hero::Hero() {
        
        safeState();
    }
    
    void Hero::safeState() {
        _strength = 0;
        _name[0] = '\0';
    }
    
    Hero::Hero(const char* name, double strength) {
        
        int i;
        
        if (strength >= 0) {
            _strength = strength;
            for (i = 0; i < 20 && name[i] != '\0'; i++)
                _name[i] = name[i];
            _name[i] = '\0';
        }
        else {
            safeState();
        }
    }
    
    bool Hero::empty() const {
        
        return _strength == 0 && _name[0] == '\0';
    }
    
    double Hero::strength() const {
        
        if (_strength != 0) {
            return _strength;
        }
        else {
            return 0;
        }
    }
    
    std::ostream& Hero::display(std::ostream& os) const {
        if (empty()) {
            return os;
        }
        else {
            os << _name << "- " << _strength << std::endl;
            return os;
        }
    }
    
    bool Hero::operator<(const Hero& rightOperand) const {
        
        return this->strength() < rightOperand.strength();
    }
    
    Hero::~Hero() {
    }
    
    std::ostream& operator<<(std::ostream& os, const Hero& s) {
        return s.display(os);
    }
}
