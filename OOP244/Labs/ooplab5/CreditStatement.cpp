#include "CreditStatement.h"

CreditStatement::CreditStatement()
{
    desc = NULL;
    price = 0;
}

CreditStatement::CreditStatement(const char* _desc, double _price)
{
    desc = new char[strlen(_desc) + 1];
    strcpy(desc, _desc);
    price = _price;
}

CreditStatement::CreditStatement(const CreditStatement& source)
{
    price = source.price;
    
    if (desc != NULL)
    {
        desc = new char[strlen(source.desc) + 1];
        strcpy(desc, source.desc);
    }
    else {
        desc = NULL;
    }
}

CreditStatement& CreditStatement::operator = (const CreditStatement& source)
{
    if (this != &source)
    {
        delete[]desc;
        desc = new char[strlen(source.desc) + 1];
        strcpy(desc, source.desc);
        price = source.price;
    }
    
    return *this;
}

CreditStatement::~CreditStatement()
{
    delete[]desc;
}

bool CreditStatement::isGreaterThan(const CreditStatement& source) const
{
    if (price > source.price) {
        return true;
    }
    
    else {
        return false;
    }
}

void CreditStatement::display() const
{
    cout << fixed << setw(26) << desc << right << setw(8) << setprecision(2) << price << endl;
}