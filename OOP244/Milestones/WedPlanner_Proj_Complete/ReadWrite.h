#ifndef __244__READWRITE_H__
#define __244__READWRITE_H__
#define _CRT_SECURE_NO_WARNIGNS

#include <iostream>
#include <fstream>
#include "general.h"
// hearder file includes go here

namespace oop244 {
    
  class ReadWrite {
      
  public:
      virtual std::fstream& store(std::fstream&) const=0;
      virtual std::fstream& load(std::fstream&)=0;
      virtual std::ostream& display(std::ostream& os, bool linear) const=0;
      virtual std::istream& conInput (std::istream& is)=0;
  };
}

#endif