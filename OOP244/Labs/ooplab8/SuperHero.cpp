// OOP244 Workshop 8: Derived Classes
// File	Hero.h
// Version 1.0
// Date 2015-07-30
// Author	Ben Mantle-Williams
// Description
// ...........
/////////////////////////////////////////////////////

#include "SuperHero.h"
namespace oop244 {
    
    SuperHero::SuperHero() {
        safeState();
    }
    
    void SuperHero::safeState() {
        _addPowers = (int*)0;
        _size = 0;
    }
    
    SuperHero::SuperHero(const int* addPowers, int size, const char* superName, double superStrength) : Hero(superName, superStrength) {
        
        int i;
        _size = size;
        
        if (size >= 0) {
            _addPowers = new int[size];
            
            for (i = 0; i < size; i++) {
                if (addPowers[i] <= 0) {
                    _addPowers[i] = 0;
                }
                else {
                    _addPowers[i] = addPowers[i];
                }
            }
        }
        else {
            safeState();
        }
    }
    
    std::ostream& SuperHero::display(std::ostream& os) const {
        
        int i;
        Hero::display(os);
        
        if (_size == 0 && Hero::empty()) {
        }
        
        else if (_size == 0) {
            os << "No powers" << std::endl;
        }
        
        else {
            os << "Superhero's powers:" << std::endl;
            for (i = 0; i < _size; i++) {
                if (_addPowers[i] == 0)
                    os << _addPowers[i] << "-failed power" << std::endl;
                else if (_addPowers[i] <= 10)
                    os << _addPowers[i] << "-firebolt" << std::endl;
                else if (_addPowers[i] <= 20)
                    os << _addPowers[i] << "-invisibility" << std::endl;
                else if (_addPowers[i] <= 30)
                    os << _addPowers[i] << "-double strength" << std::endl;
                else if (_addPowers[i] <= 40)
                    os << _addPowers[i] << "-shield" << std::endl;
                else
                    os << _addPowers[i] << "-speed" << std::endl;
            }
        }
        return os;
    }
    
    
    SuperHero::~SuperHero() {
        
        delete[] _addPowers;
    }
}
