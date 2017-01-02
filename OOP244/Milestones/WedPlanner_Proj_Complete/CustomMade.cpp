#include <iomanip>
#include <iostream>
#include "CustomMade.h"
using namespace std;

namespace oop244 {

  CustomMade::CustomMade() : Good("", "", 0, 1, true) {}

  const Date& CustomMade::delivery() const {
    return _delivery;
  }

  void CustomMade::delivery(const Date& value) {
    _delivery = value;
  }

  fstream& CustomMade::store(fstream& file) const {

    file << "C" << "," << upc() << "," << name() << "," << 
    price() << "," << taxed() << "," << quantity() << "," << 
    qtyNeeded() << "," << delivery() << endl;

    return file;
  }

  fstream& CustomMade::load(fstream& file) {

    char c[200];
    int i;
    double d;
    bool b;

    file.getline(c, MAX_UPC_LEN, ',');
    upc(c);
    file.getline(c, 20, ',');
    name(c);
    file >> d;
    file.ignore();
    price(d);
    file >> b;
    file.ignore();
    taxed(b);
    file >> i;
    file.ignore();
    quantity(i);
    file >> i;
    file.ignore();
    qtyNeeded(i);
    file >> _delivery;

    return file;
  }

  ostream& CustomMade::display(ostream& ostr, bool linear) const {

    if (_err.isClear() != true) {
      ostr << _err;
      return ostr;
    }
    else {
      if (linear) {
        ostr << left << setw(MAX_UPC_LEN) << upc() << '|' << setw(20) << 
        name() << '|' << fixed << right << setw(7) << setprecision(2) << cost() << '|';

        if (taxed()) {
          ostr << " t ";
        }
        else {
          ostr << "   ";
        }

        ostr << '|' << fixed << right << setw(4) << quantity() << '|' << setw(4) 
        << qtyNeeded() << '|' << delivery();
      }
      else {
        if (taxed()) {
          ostr << "upc: " << upc() << endl << "name: " << name() << '\n' << 
          "price: " << price() << endl << "Price after tax: " << cost() << endl << 
          "Quantity On hand: " << quantity() << endl << "Quantity Needed: " << 
          qtyNeeded() << endl << "delivery date: " << delivery() << endl;
        }
        else {
          ostr << "upc: " << upc() << endl << "name: " << name() << endl << 
          "price: " << price() << endl << "Price after tax: " << "N/A" << endl << 
          "Quantity On hand: " << quantity() << endl << "Quantity Needed: " << 
          qtyNeeded() << endl << "delivery date: " << delivery() << endl;
        }
      }
    }

    return ostr;
  }

  istream& CustomMade::conInput(istream& istr) {
    char c;
    char str[200];
    int i;
    double d;
    _err.clear();

    cout << "CustomMade Good Entry: " << endl;
    cout << "upc: ";
    // istr.getline(str, 200, '\n');
    istr >> str; // using this instead...
    upc(str);
    cout << "name: ";
    // istr.getline(str, 200, '\n');
    istr.ignore(2000, '\n'); // using this instead
    istr.getline(str, 2000, '\n');
    name(str);
    cout << "price: ";
    istr >> d;

    if (istr.fail()) {
      _err.message("Invalid Price Entry");
      return istr;
    }
    else {
      price(d);
    }

    cout << "Taxed: ";
    istr >> c;

    if (c != 'Y' && c != 'y' && c != 'N' && c != 'n') {
      _err.message("Invalid Taxed Entry, (y)es or (n)o\n\n");
      istr.setstate(ios::failbit);

      return istr;
    }
    else {
      if (c == 'Y' || c == 'y') {
        taxed(true);
      }
      else if (c == 'N' || c == 'n') {
        taxed(false);
      }
    }

    cout << "Quantity On hand: ";
    istr >> i;

    if (istr.fail()) {
      _err.message("Invalid Quantity Entry");
      return istr;
    }
    else {
      quantity(i);
    }

    cout << "Quantity Needed: ";
    istr >> i;

    if (istr.fail()) {
      _err.message("Invalid Quantity Needed Entry");
      return istr;
    }
    else {
      qtyNeeded(i);
    }

    cout << "delivery date (YYYY/MM/DD) : ";
	  _delivery.read(istr);

    if (_delivery.bad()) {
      if (_delivery.errCode() == CIN_FAILED) {

        _err.message("Invalid Date Entry");
        istr.setstate(ios::failbit);
      }
      else if (_delivery.errCode() == YEAR_ERROR) {

        _err.message("Invalid Year in Date Entry\n\n");
        istr.setstate(ios::failbit);
      }
      else if (_delivery.errCode() == MON_ERROR) {

        _err.message("Invalid Month in Date Entry");
        istr.setstate(ios::failbit);
      }
      else if (_delivery.errCode() == DAY_ERROR) {

        _err.message("Invalid Day in Date Entry");
        istr.setstate(ios::failbit);
      }

      return istr;
    }

    istr.clear();
    return istr;
  }
}
