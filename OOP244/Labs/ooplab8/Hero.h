// OOP244 Workshop 8: Derived Classes
// File	Hero.h
// Version 1.0
// Date 2015-07-30
// Author	Ben Mantle-Williams
// Description
// ...........
/////////////////////////////////////////////////////

#ifndef _244_HERO_H_
#define _244_HERO_H_
#include <iostream>

namespace oop244 {
    
    class Hero {
        double _strength;
        char _name[21];
        void safeState();
        
    public:
        Hero();
        Hero(const char* name, double strength);
        double strength() const;
        bool empty() const;
        virtual std::ostream& display(std::ostream& os) const;
        bool operator<(const Hero& rightOperand) const;
        virtual ~Hero();
    };
    
    std::ostream& operator<<(std::ostream& os, const Hero& s);
}

#endif