#include "Truck.h"

namespace oop244{
    
    Truck::Truck() {
        
        _trkSpd = 0.0;
        _trkCpct = false;
    }
    
    Truck::Truck(double trkSpd){
        _trkSpd = trkSpd;
    }
    
    Truck::Truck(double trkSpd, bool trkCpct) {
        
        _trkSpd = trkSpd;
        _trkCpct = trkCpct;
    }
    
    void Truck::accelerate() {
        _trkSpd += 50;
    }
    
    void Truck::brake() {
        
        if (_trkSpd >= 20)
            _trkSpd -= 20;
        else if (_trkSpd > 0 && _trkSpd < 20)
            _trkSpd -= _trkSpd;
    }
    
    std::ostream& Truck::display(std::ostream& os) const {
        
        if (_trkCpct) {
            os << "This truck is going " << _trkSpd
            << " after accelerating and braking, and it can be used to tow.";
        }
        else {
            os << "This truck is going " << _trkSpd
            << " after accelerating and braking, and it cannot be used to tow.";
        }
        
        return os;
    }
}
