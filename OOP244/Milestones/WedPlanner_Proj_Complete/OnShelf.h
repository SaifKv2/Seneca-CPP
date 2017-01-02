#ifndef __244_OnShelf_H__
#define __244_OnShelf_H__
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "Good.h"
#include "ErrorMessage.h"

namespace oop244 {
  
  class OnShelf : public Good {

  private:
    ErrorMessage _err;

  public:
    OnShelf();
	  std::fstream& store(std::fstream& file) const;
	  std::fstream& load(std::fstream& file);
	  std::ostream& display(std::ostream& ostr, bool linear) const;
	  std::istream& conInput(std::istream& istr);
  };
}

#endif