#ifndef _244_BUS_
#define _244_BUS_
#define _CRT_SECURE_NO_WARNINGS // Adding this for once just in case because you use VS...
#include "Vehicle.h"

namespace oop244 {
    
  class Bus : public Vehicle {
      
    double _busSpd;
    int _busCpct;
      
  public:
    Bus();
    Bus(double busSpd, int busCpct);
    void accelerate();
    void brake();
    std::ostream& display(std::ostream& os) const;
  };
}

#endif
