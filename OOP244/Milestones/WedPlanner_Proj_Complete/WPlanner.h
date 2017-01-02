#ifndef __244_WPlanner_H__
#define __244_WPlanner_H__
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cstring>
#include "OnShelf.h"
#include "CustomMade.h"

namespace oop244 {

  class WPlanner {

    char _filename[256];
    Good* _good[MAX_NO_RECS];
    std::fstream datafile;
    int _noOfGoods;

    WPlanner(const WPlanner& source) = delete;
    WPlanner& operator = (const WPlanner source) = delete;

    int menu();
    void loadRecs();
    void saveRecs();
    void listGoods() const;
    int SearchGoods(const char* upc) const;
    void updateQty(const char* upc);
    void addGood(bool isCustomMade);
    
  public:
    WPlanner(const char* filename);
    ~WPlanner();
    int run();
  };
}

#endif