#include "Vehicle.h"

namespace oop244 {
    
    double Vehicle::getSpeed() const {
        return speed;
    }
    
    void Vehicle::setSpeed(double vhcSpd) {
        
        if (vhcSpd > 0)
            vhcSpd = speed;
        else
            speed = 0.0;
    }
    
    void move(Vehicle& vhc) {
        
        vhc.accelerate();
        vhc.brake();
    }
    
    void show(const Vehicle& os) {
        
        os.display(std::cout);
    }
}
