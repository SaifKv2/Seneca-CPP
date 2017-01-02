// OOP244 Workshop 7: compositions
// File	Engine.h
// Version 1.0
// Date 2015-07-30
// Author	Ben Mantle-Williams
// Description
// Engine class declaration
/////////////////////////////////////////////////////

#ifndef _244_ENGINE_H_
#define _244_ENGINE_H_
#include <iostream>

namespace oop244 {
    
    class Engine {
        char _type[31];
        double _size;
        
    public:
        Engine(double size = 0.0, const char* type = "");
        double get() const;
        std::ostream& display(std::ostream& os) const;
    };
}

#endif