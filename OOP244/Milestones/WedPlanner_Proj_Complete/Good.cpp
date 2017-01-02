// includes go here
#include "Good.h"

namespace oop244 {
    
    // Good class implementation
    
    Good::Good() {
      
        _upc[0] = '\0';
        _name = (char*)0;
        _price = 0;
        _taxed = true;
        _quantity = 0;
        _qtyNeeded = 0;
    }
  
    Good::Good(const char* upc, const char* name, double price, int qtyNeeded, bool taxed) {
      
        taxed = true;
        strncpy(_upc, upc, MAX_UPC_LEN);
        _upc[MAX_UPC_LEN] = '\0';
        _name = new char[strlen(name) + 1];
        strcpy(_name, name);
        _price = price;
        _taxed = taxed;
        _quantity = 0;
        _qtyNeeded = qtyNeeded;
    }

    Good::Good(const Good& source) {
      
        strncpy(_upc, source._upc, MAX_UPC_LEN);
        _upc[MAX_UPC_LEN] = '\0';

	    if (source._name != (char*)0) {
            _name = new char[strlen(source._name) + 1];
            strcpy(_name, source._name);
        }
        else {
	        _name = (char*)0;

            _price = source._price;
            _taxed = source._taxed;
            _quantity = source._quantity;
            _qtyNeeded = source._qtyNeeded;
        }
    }

    Good& Good::operator=(const Good& source) {
      
        if (this != &source) {
            delete[] _name;
            // strncpy(_upc, source._upc, MAX_UPC_LEN);
            // _upc[MAX_UPC_LEN] = '\0';
        }
        
        if (source._name != (char*)0) {
                _name = new char[strlen(source._name) + 1];
                strcpy(_name, source._name);
	    }
        else {
            _name = (char*)0;
            _price = source._price;
            _taxed = source._taxed;
            _quantity = source._quantity;
            _qtyNeeded = source._qtyNeeded;
        }
      
        return *this;
    }

    Good::~Good() {
        if (_name != (char*)0) {
            delete[] _name;
        }
    }
    
    void Good::upc(char* upc) {
      
        strncpy(_upc, upc, MAX_UPC_LEN);
        _upc[MAX_UPC_LEN] = '\0';
    }
    
    void Good::name(char* name) {
      
        _name = new char[strlen(name) + 1];
        strcpy(_name, name);
    }
    
    void Good::price(double price) {
        _price = price;
    }
    
    void Good::taxed(bool taxed) {
        _taxed = taxed;
    }
  
    void Good::quantity(int quantity) {
        _quantity = quantity;
    }
  
    void Good::qtyNeeded(int qtyNeeded) {
        _qtyNeeded = qtyNeeded;
    }

    const char* Good::upc() const {
        return _upc;
    }
    
    const char* Good::name() const {
        return _name;
    }
    
    double Good::price() const {
        return _price;
    }
    
    bool Good::taxed() const {
        return _taxed;
    }
    
    int Good::quantity() const {
        return _quantity;
    }
    
    int Good::qtyNeeded() const {
        return _qtyNeeded;
    }
    
    double Good::cost() const {
      
        if (_taxed == false)
            return _price;
        else
            return _price + (_price * TAX);
    }

    bool Good::operator==(const char* rhs) const {
        return strcmp(_upc, rhs) == 0;
    }
  
    int Good::operator+=(int quantity) {
        return _quantity += quantity;
    }

    // Helper operators
    
    double operator+=(double& lhs, const Good& rhs) {
        return  lhs+=rhs.quantity() * rhs.cost();
    }

    std::ostream& operator<<(std::ostream& ostr, Good& rhs) {
        return rhs.display(ostr, true);
    }

    std::istream& operator>>(std::istream& istr, Good& rhs) {
        return rhs.conInput(istr);
    }
}
