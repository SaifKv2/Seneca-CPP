#define _CRT_SECURE_NO_WARNINGS
#define MAX_LINE_LENGTH 256
#define MAX_PURCHASES 5

#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;


class CreditStatement {
    
private:
    char* desc;
    double price;
    
public:
    CreditStatement();
    CreditStatement(const char* _desc, double _price);
    CreditStatement(const CreditStatement&);
    CreditStatement& operator = (const CreditStatement&);
    
    ~CreditStatement();
    void display() const;
    bool isGreaterThan(const CreditStatement&) const;
};
