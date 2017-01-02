#include <iostream>
    
    class Weather {
        
        char date_description[31];
        double high, low;
        
    public:
        void set(const char*, double, double);
        void display() const;
    };