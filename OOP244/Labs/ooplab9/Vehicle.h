#ifndef _244_VEHICLE_
#define _244_VEHICLE_
#define _CRT_SECURE_NO_WARNINGS // Adding this for once just in case because you use VS...
#include <iostream>
#include <cstring>

namespace oop244 {
    
    class Vehicle {
        
    private:
        double speed;
    protected:
        double getSpeed() const;
        void setSpeed(double speed);
    public:
        virtual void accelerate() = 0;
        virtual void brake() = 0;
        virtual std::ostream& display(std::ostream& os) const = 0;
    };
    
    void move(Vehicle& vhc);
    void show(const Vehicle& os);
}

#endif