#ifndef __244_CUSTOMMADE_H__
#define __244_CUSTOMMADE_H__
#define _CRT_SECURE_NO_WARNINGS // Do I always need this in general?
                                // Best practice?
#include <iostream>
#include "Date.h"
#include "Good.h"
#include "ReadWrite.h"
#include "ErrorMessage.h"
 
namespace oop244 {

  class CustomMade : public Good {

  private:

    ErrorMessage _err;
    Date _delivery;

  public:

    CustomMade();
    const Date& delivery() const;
    void delivery(const Date& value);

    std::fstream& store(std::fstream& file) const;
    std::fstream& load(std::fstream& file);
    std::ostream& display(std::ostream& ostr, bool linear) const;
    std::istream& conInput(std::istream& istr);
  };
}

#endif