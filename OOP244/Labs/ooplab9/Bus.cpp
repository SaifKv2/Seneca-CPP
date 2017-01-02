#include "Bus.h"

namespace oop244 {
    
    Bus::Bus() {
        
        _busSpd = 0.0;
        _busCpct = 0;
    }
    
    Bus::Bus(double busSpd, int busCpct) {
        
        _busSpd = busSpd;
        _busCpct = busCpct;
    }
    
    void Bus::accelerate() {
        _busSpd += 20;
    }
    
    void Bus::brake() {
        
        if (_busSpd >= 10)
            _busSpd -= 10;
        else if (_busSpd > 0 && _busSpd < 10)
            _busSpd -= _busSpd;
    }
    
    std::ostream& Bus::display(std::ostream& os) const {
        
        os << "This bus has total capacity of " << _busCpct
        << " passengers and has a speed of " << _busSpd
        << " after acceleration and braking.";
        
        return os;
    }
}
