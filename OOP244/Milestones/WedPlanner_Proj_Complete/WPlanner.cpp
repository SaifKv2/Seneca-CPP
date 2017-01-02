#include <cstring>
#include <iomanip>
#define _CRT_SECURE_NO_WARNINGS
#include "WPlanner.h"
using namespace std;

namespace oop244 {

  WPlanner::WPlanner(const char* filename) {
    if (filename != NULL) {
      strcpy(_filename, filename);
    }
    else {
      _filename[0] = '\0';
    }

    for (int i = 0; i < MAX_NO_RECS; i++) {
      _good[i] = NULL;
    }
    
    _noOfGoods = 0;
    loadRecs();
  }

  WPlanner::~WPlanner() {}

  void WPlanner::loadRecs() {

    int readIndex = 0;
    datafile.open(_filename, ios::in);

    if (datafile.fail()) {
      datafile.clear();
      datafile.close();
      datafile.open(_filename, ios::out);
      datafile.close();
    }
    else {
      bool loop = true;

      while (loop) {
        char c = '\0';
        datafile.get(c);
        datafile.ignore(1);

        if (c == 'C') {
          CustomMade* csMd = (char)0;
          csMd = new CustomMade;
          _good[readIndex++] = csMd;
          csMd->load(datafile);
        }
        else if (c == 'S') {
          OnShelf* shGood = (char)0;
          shGood = new OnShelf;
          _good[readIndex++] = shGood;
          shGood->load(datafile);
        }
        else if (c == '\0') {
          loop = false;
        }
        else {
          cout << "File is empty" << endl;
          loop = false;
        }
      }
    }

    _noOfGoods = readIndex;
    datafile.close();
  }

  void WPlanner::saveRecs() {

    datafile.open(_filename, ios::out);

    if (datafile.is_open()) {
      for (int i = 0; i < _noOfGoods; i++) {
        _good[i]->store(datafile);
      }
    }

    datafile.close();
  }

  void WPlanner::listGoods() const {

    cout << " Row | UPC    | Good Name          | Cost  |Tax| QTY|Need| Delivery" << endl;
    cout << "-----|--------|--------------------|-------|---|----|----|----------" << endl;

    double total = 0.0;

    for (int i = 0; i < _noOfGoods; i++) {
      cout << right << setfill(' ') << setw(4) << (i + 1) << " | " << *_good[i] << endl;
      total += *_good[i];
    }

    cout << "---------------------------------------------------------------------------" << endl;
    cout << "Total cost of the Wedding: $";
    cout << fixed << left << setprecision(2) << total << endl << endl;
  }

  int WPlanner::SearchGoods(const char* upc) const {

    int i;

    for (i = 0; i < _noOfGoods; i++) {

      if (strcmp(_good[i]->upc(), upc) == 0) {
        _good[i]->display(cout, false);
        cout << endl;
        return i;
      }
    }

    return -1;
  }

  void WPlanner::updateQty(const char* upc) {

    int tempGood;
    int _id = SearchGoods(upc);

    if (_id == -1) {
      cout << "Not found!" << endl << endl;
    }
    else {
      cout << "Please enter the number of purchased goods: ";
      cin >> tempGood;
      if (cin.fail()) {
        cout << "Invalid Quantity value!" << endl;
      }
      else {
        if (tempGood <= (_good[_id]->qtyNeeded() - _good[_id]->quantity())) {
          *_good[_id] += tempGood; 
        }
        else {
          *_good[_id] += (_good[_id]->qtyNeeded() - _good[_id]->quantity());
          cout << "Too many purchased, only " << _good[_id]->qtyNeeded() << 
          " needed, please return the extra " << tempGood - _good[_id]->qtyNeeded()
          << "." << endl;
        }

        cout << "Updated!\n" << endl;
        saveRecs();
      }
    }
  }

  void WPlanner::addGood(bool isCustomMade) {

    if (isCustomMade == true) {

      CustomMade *cmGood = new CustomMade();
      cin >> *cmGood;

      if (!cin.fail()) {
        _good[_noOfGoods++] = cmGood;
        saveRecs();
        cout << "Good added\n" << endl;
      }
      else {
        cout << *cmGood; // << endl;
        cin.clear();
        cin.ignore();
      }
    }
    else {
      OnShelf *osGood = new OnShelf();
      cin >> *osGood;

      if (!cin.fail()) {
        _good[_noOfGoods++] = osGood;
        saveRecs();
        cout << "Good added\n" << endl;
      }
      else {
        cout << *osGood; // << endl;
        cin.clear();
        cin.ignore();
      }
    }
  }

  int WPlanner::menu() {

    int input;
    
    cout << "Wedding Planner Management Program" << endl;
    cout << "1 - List goods" << endl;
    cout << "2 - Add On Shelf Good" << endl;
    cout << "3 - Add Custom-Made Good" << endl;
    cout << "4 - Update Good quantity" << endl;
    cout << "0 - Exit program" << endl;
    cout << "> ";
    cin >> input;
    cout << endl;
    // cin.ignore();

    if (cin.fail()){
      cin.clear();
      cin.ignore(2000, '\n');
      input = -1;
    }

    switch (input) {

    case 1:
      break;

    case 2:
      break;

    case 3:
      break;

    case 4:
      break;

    case 0:
      break;

    default:
      input = -1;
      break;
    }
   
    return input;
  }

  int WPlanner::run() {

    int option;
    char tempUpc[7];

    do{
      option = menu();

      if (option == 1){
        listGoods();
      }
      else if (option == 2) {
        addGood(false);
      }
      else if (option == 3) {
        addGood(true);
      }
      else if (option == 4) {
        cout << "Please enter the UPC: ";
        cin >> tempUpc;
        updateQty(tempUpc);
      }
      else if (option == 0) {
        cout << "Goodbye!!" << endl;
      }
      else {
        cout << "===Invalid Selection, try again.===" << endl;
      }
    } while (option != 0);

    return option;
  }
}
