// OOP345 Workshop 2: unsigned int, Enumerations, String Class and File I/O
// Date 2016-02-01
// Author — Ben Mantle
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Station.h"

namespace w2 {

    Station::Station() : _name("") {
        _passes[STUDENT_PASS] = 0;
        _passes[ADULT_PASS] = 0;
    }

    void Station::set(const std::string& name, unsigned studentPass, unsigned adultPass) {
        _name = name;
        _passes[STUDENT_PASS] = studentPass;
        _passes[ADULT_PASS] = adultPass;
    }

    unsigned Station::inStock(PassType type) const {
        return _passes[type];
    }

    const std::string& Station::getName() const {
        return _name;
    }

    void Station::update(PassType type, int num) {
        _passes[type] += num;
    }
}
