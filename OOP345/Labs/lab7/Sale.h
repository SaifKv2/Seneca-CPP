#pragma once

#include "Product.h"
#include <vector>

namespace w7 {

  class Sale {
    std::vector<iProduct*>products;

  public:
    Sale(const char* filename);
    ~Sale();
    void display(std::ostream& os) const;
  };
}