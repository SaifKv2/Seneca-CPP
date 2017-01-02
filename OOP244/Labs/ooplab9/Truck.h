#ifndef _244_TRUCK_
#define _244_TRUCK_
#define _CRT_SECURE_NO_WARNINGS // Adding this for once just in case because you use VS...
#include "Vehicle.h"

namespace oop244 {
    
    class Truck : public Vehicle {
        
        double _trkSpd;
        bool _trkCpct;
    public:
        Truck();
        Truck(double trkSpd);
        Truck(double trkSpd, bool trkCpct);
        void accelerate();
        void brake();
        std::ostream& display(std::ostream& os) const;
    };
}

#endif