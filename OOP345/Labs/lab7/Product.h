#pragma once

#include "iProduct.h"

namespace w7 {

  class Product : public iProduct {

    int no;
    double cost;
    
  public:
    explicit Product() = default;
    Product(int n, double c): no(n), cost(c) {}
    
    double getCharge() const;
    void display( std::ostream& ) const;
  };
}