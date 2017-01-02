// OOP244 Workshop 7: compositions
// File	Engine.cpp
// Version 1.0
// Date 2015-07-30
// Author	Ben Mantle-Williams
// Description
// Engine class implementation
/////////////////////////////////////////////////////

#include <iomanip>
#include "Engine.h"

namespace oop244 {
    
    Engine::Engine(double size, const char* type) {
        int i;
        
        if (size > 0.0 && type != (char*)0 && type != 0) {
            _size = size;
            for (i = 0; i < 31 && type[i] != 0; i++) {
                _type[i] = type[i];
            }
            _type[i] = 0;
        }
    }
    
    double Engine::get() const {
        return _size;
    }
    
    std::ostream& Engine::display(std::ostream& os) const {
        
        os << std::fixed << std::setprecision(2) << _size << " litre - " << _type << std::endl;
        return os;
    }
}