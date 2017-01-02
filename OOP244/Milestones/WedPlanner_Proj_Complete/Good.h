#ifndef __244_GOOD_H__
#define __244_GOOD_H__
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "ReadWrite.h"
#include "general.h"

namespace oop244 {
    
    //inherited from ReadWrite:
    class Good: public ReadWrite {
      
    private:
        // attributes
        char _upc[MAX_UPC_LEN + 1];
        char* _name;
        double _price;
        bool _taxed;
        int _quantity;
        int _qtyNeeded;

    public:
        // constructors
        Good();
        Good(const Good& source);
        Good(const char* upc, const char* name, double price, int qtyNeeded, bool taxed = true);
        Good& operator=(const Good& source);
      
        // virtual destructor
        virtual ~Good();
      
        // setters
        void upc(char* upc);
        void name(char* name);
        void price(double price);
        void taxed(bool taxed);
        void quantity(int quantity);
        void qtyNeeded(int qtyNeeded);
      
        // getters
        const char* upc() const;
        const char* name() const;
        double price() const;
        bool taxed() const;
        int quantity() const;
        int qtyNeeded() const;
        double cost() const;
      
        // operators
        bool operator==(const char* rhs) const;
        int operator+=(int quantity);
    };
    
    // Helper operator overloads
    double operator+=(double& lhs, const Good& rhs);
    std::ostream& operator<<(std::ostream& ostr, Good& rhs);
    std::istream& operator>>(std::istream& istr, Good& rhs);
}

#endif