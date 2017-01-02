#include <iostream>
#include <iomanip>
#include "Sale.h"
#include "stdio.h"

using namespace std;

namespace w7 {

  Sale::Sale(const char* filename) {
    
    try {
      ifstream fs(filename, ios::out);

      if(fs.fail()) {
        throw "fail to open the file";
      }
      else {
        while (fs) {
          products.push_back(readProduct(fs));
        }
      }

    }catch( const char* msg ) {
      cout << msg << endl;
    }
  }
  
  Sale::~Sale() {

    std::vector<iProduct*>().swap(products);
  }
  
  void Sale::display(std::ostream& os) const {
    double total = 0;
    
    os << "Product No      Cost Taxable" << endl;
    os << "----------------------------" << endl;

    for(auto i = 0; i < products.size(); i++) {

      os << products[i];
      os << endl;
      total += products[i]->getCharge();
    }

    os << "----------------------------" << endl;
    os << "     Total" << setw(10) << total << endl;
  }
}