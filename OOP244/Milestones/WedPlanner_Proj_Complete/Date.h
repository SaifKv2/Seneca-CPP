#ifndef __244_DATE_H__
#define __244_DATE_H__
// header file includes
#include <iostream>

namespace oop244 {
    
  // Error code values go here
    
  #define NO_ERROR 0 // no error - the date is valid
  #define CIN_FAILED 1 // istream failed on accepting information
  #define YEAR_ERROR 2 // year value is invalid
  #define MON_ERROR 3 // month value is invalid
  #define DAY_ERROR 4 // day value is invalid

    
  class Date {
      
  private:
      int _year;
      int _mon;
      int _day;
      int _readErrorCode;

      // private member functions and setters
      
      int value()const;
      void errCode(int errorCode);

  public:
      // constructors
    
      Date();
      Date(int year, int mon, int day);

      // operator overloads
      
      bool operator==(const Date& D)const;
      bool operator!=(const Date& D)const;
      bool operator<(const Date& D)const;
      bool operator>(const Date& D)const;
      bool operator<=(const Date& D)const;
      bool operator>=(const Date& D)const;

      
      // IO member functions

      std::istream& read(std::istream& istr);
      std::ostream& write(std::ostream& ostr) const;

      // public member functions and getters
      
      int mdays() const;
      int errCode() const;
      bool bad() const;
  };

  // operator << and >> overloads prototypes for ostream and istream go here
  std::ostream& operator<<(std::ostream& ostr, const Date& D);
  std::istream& operator>>(std::istream& istr, Date& D);
}

#endif