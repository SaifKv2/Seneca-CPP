// OOP345 Workshop 2: unsigned int, Enumerations, String Class and File I/O
// Date 2016-02-01
// Author — Ben Mantle
///////////////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#ifndef _STATIONS_H
#define _STATIONS_H

#include <string>
#include "Station.h"

namespace w2 {

    class Stations {

        Station* _stations;
        int _numStation;

    public:
        Stations(const char* filename);
        virtual ~Stations();

        void update() const;
        void restock() const;
        void report() const;
    };
}

#endif // _STATIONS_H