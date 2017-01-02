#include "TaxableProduct.h"

namespace w7 {

  double TaxableProduct::getCharge() const {

    return Product::getCharge() * (1 + tax);
  }
  
  void TaxableProduct::display(std::ostream& os) const {

    Product::display(os);
    os << ( tax == HST ? " HST" : " PST");
  }
}