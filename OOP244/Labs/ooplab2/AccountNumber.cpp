#include <iostream>
#include <cstring>
#include "AccountNumber.h"

using namespace std;
using namespace oop244;

void AccountNumber::setName(const char name[]) {
    strcpy (_name, name);
}

void AccountNumber::setAccountNumber(int bankCode, int branchCode, int accountNumber) {
    
    _bankCode = bankCode;
    _branchCode = branchCode;
    _accountNumber = accountNumber;
    
    if (bankCode >= MIN_BANKCODE && bankCode <= MAX_BANKCODE && branchCode >= MIN_BRANCHCODE &&
        branchCode <= MAX_BRANCHCODE && _accountNumber >= MIN_ACCNO && _accountNumber <= MAX_ACCNO){
        _validAccNumber = true;
        
    }
    
    else {
        _validAccNumber = false;
    }
}

void AccountNumber::display() const {
    
    if (_validAccNumber) {
        cout << "Name: " << _name << ", Account number: " << _bankCode << "-" << _branchCode << "-" << _accountNumber << endl;
    }
    
    else {
        cout << _name << " does not have a valid account number." << endl;
    }
}

bool AccountNumber::isValid() const {
    
    return _validAccNumber;
}