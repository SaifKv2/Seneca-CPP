#include "OnShelf.h"
using namespace std;

namespace oop244 {

	OnShelf::OnShelf() : Good("", "", 0, 1, true) {}

	fstream& OnShelf::store(fstream& file) const {
		file << "S" << "," << upc() << "," << name() << "," << 
    price() << "," << taxed() << "," << quantity() << "," << 
    qtyNeeded() << endl;

		return file;
	}
	
	fstream& OnShelf::load(fstream& file) {

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

		return file;
	}

  ostream& OnShelf::display(ostream& ostr, bool linear) const {

    if (_err.isClear() != true) {
      ostr << _err;
      return ostr;
    }

    else {
      if (linear) {
        ostr << left << setw(MAX_UPC_LEN) << upc() << '|' << 
        setw(20) << name() << '|' << fixed << right << setw(7) << 
        setprecision(2) << cost() << '|';

        if (taxed()) {
          ostr << " t ";
        }
        else {
          ostr << "   ";
        }
         
        ostr << '|' << fixed << right << setw(4) << quantity() << 
        '|' << setw(4) << qtyNeeded() << '|';
      }
      else {
        if (taxed()) {
          ostr << "Upc: " << upc() << endl << "Name: " << name() << 
          '\n' << "Price: " << price() << endl << "Price after tax: " << 
          cost() << endl << "Quantity On Hand: " << quantity() << endl << 
          "Quantity Needed: " << qtyNeeded() << endl;
        }
        else {
          ostr << "Upc: " << upc() << endl << "Name: " << name() << endl << 
          "Price: " << price() << endl << "Price after tax: " << "N/A" << 
          endl << "Quantity On Hand: " << quantity() << endl << 
          "Quantity Needed: " << qtyNeeded() << endl;
        }
      }      
    }

    return ostr;
  }

  istream& OnShelf::conInput(istream& istr) {

    char c;
    char str[200];
    int i;
    double d;
    _err.clear();

    cout << "OnShelf Good Entry:" << endl;
    cout << "Upc: ";
    // istr.getline(str, 200, '\n');
    istr >> str; // replacement
    upc(str);
    cout << "Name: ";
    istr.ignore(2000, '\n'); // addition
    istr.getline(str, 2000, '\n');
    name(str);
    cout << "Price: ";
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
    
    return istr;
  }
}
