#include <iomanip>
#include "Product.h"
#include "TaxableProduct.h"

using namespace std;

namespace w7 {

  iProduct* readProduct(std::ifstream& fs) {

    iProduct *p;
    int n;
    double c;
    char buff;
    
    fs >> n >> c;
    buff = fs.get();

    if (buff == ' ') {
      fs >> buff;

      if (buff == 'H') {
        TaxableProduct* temp = new TaxableProduct(n, c, HST);
        p = temp;
      }

      else if(buff == 'P') {

        TaxableProduct* temp = new TaxableProduct(n, c, PST);
        p = temp;
      }
    }

    else {
      Product* temp = new Product( n, c );
      p = temp;
    }

    return p;
  }

  std::ostream& operator<<(std::ostream& os, const iProduct* p) {

    p->display(os);
    return os;
  }
  
  double Product::getCharge() const {
    return cost; }
  
  void Product::display(std::ostream& os) const {
    os << setw(10) << no << right << setw(10) << std::fixed << std::setprecision(2)
    << Product::getCharge();
  }
}