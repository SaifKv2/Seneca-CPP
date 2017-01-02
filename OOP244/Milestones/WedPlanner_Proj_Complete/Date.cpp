#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Date.h"
#include "general.h"

namespace oop244 {
    
  // returns a uniqe value out of date
  // this value is used to compare two dates
    
  int Date::value()const {
      return _year * 372 + _mon * 31 + _day;
  }

  // validate(), this is an optional private function to write
  // for validation logic and setting the _readErrorCode.
  // see the read() function description for more detail

  void Date::errCode(int errorCode) {
      _readErrorCode = errorCode;
  }

  // mday():
  // returns the day of the month.
  // _mon value must be set for this to work
  // if _mon is invalid, this function returns -1
  // leap years are considered in this logic

  int Date::mdays()const {
        
      int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
      int mon = _mon >= 1 && _mon <= 12 ? _mon : 13;
      mon--;
        
      return days[mon] + int((mon == 1)*((_year % 4 == 0) && (_year % 100 != 0)) || (_year % 400 == 0));
  }

    
  // constructors

  Date::Date() {
        
      _year = 0;
      _mon = 0;
      _day = 0;
      _readErrorCode = NO_ERROR;
  }
    
  Date::Date(int year, int mon, int day) {
        
      _year = year;
      _mon = mon;
      _day = day;
      _readErrorCode = NO_ERROR;
  }

    
  // member functions

  int Date::errCode() const {
      return _readErrorCode;
  }

  bool Date::bad() const {
      return _readErrorCode != 0;
  }

    
  // operators

  bool Date::operator==(const Date& D) const {
        
      if (this->value() == D.value())
          return true;
      else
          return false;
  }

  bool Date::operator!=(const Date& D) const {
        
      if (this->value() != D.value())
          return true;
      else
          return false;
  }
    
  bool Date::operator<(const Date& D) const {
       
      if (this->value() < D.value())
          return true;
      else
          return false;
  }

  bool Date::operator>(const Date& D) const {
        
      if (this->value() > D.value())
          return true;
      else
          return false;
  }
    
  bool Date::operator<=(const Date& D) const {
       
      if (this->value() >= D.value())
          return true;
      else
          return false;
  }
    
  bool Date::operator>=(const Date& D) const {
        
      if (this->value() >= D.value())
          return true;
      else
          return false;
  }
    
    
  // IO functions

  std::istream& Date::read(std::istream& istr) {
        
      _readErrorCode = 0;
      istr >> _year;
      istr.ignore();
      istr >> _mon;
      istr.ignore();
      istr >> _day;
        
      if (istr.fail()) {
          _readErrorCode = CIN_FAILED;
      }
      else if (MIN_YEAR > _year || _year > MAX_YEAR) {
          errCode(YEAR_ERROR);
      }
      else if (1 > _mon || _mon > 12) {
          _readErrorCode = MON_ERROR;
      }
      else if (mdays() < _day || _day < 1) {
          _readErrorCode = DAY_ERROR;
      }
        
      return istr;
  }
    
  std::ostream& Date::write(std::ostream& ostr) const {
        
      if (_mon < 10)
          ostr << _year << "/0" << _mon;
      else
          ostr<< _year << "/" << _mon;
        
      if (_day < 10)
          ostr << "/0" << _day;
      else
          ostr << "/" << _day;
        
      return ostr;
  }

    
  // non-member operator overloads

  std::ostream& operator<<(std::ostream& ostr, const Date& D) {
      return D.write(ostr);
  }

  std::istream& operator>>(std::istream& istr, Date& D) {
      return D.read(istr);
  }
}
