// OOP244 Workshop 8: Derived Classes
// File	Hero.h
// Version 1.0
// Date 2015-07-30
// Author	Ben Mantle-Williams
// Description
// ...........
/////////////////////////////////////////////////////

#ifndef _244_SUPERHERO_H_
#define _244_SUPERHERO_H_
#include "Hero.h"

namespace oop244 {
    
    class SuperHero : public Hero {
        int _size;
        int* _addPowers;
        void safeState();
        
    public:
        SuperHero();
        SuperHero(const int* addPowers, int size, const char* superName, double superStrength);
        std::ostream& display(std::ostream& os) const;
        ~SuperHero();
    };
}

#endif
