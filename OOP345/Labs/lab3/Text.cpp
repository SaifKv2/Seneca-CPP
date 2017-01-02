#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>

#include "Text.h"

using namespace std;

namespace w3 {

    Text::~Text() {
        if (lineTable) {
            delete[] lineTable;
        }
    }

    Text::Text(const char* filename) : lineCount(0), lineTable(nullptr) {

        fstream fs(filename);

        if (fs.is_open()) {

            string s;

            while (getline(fs, s)) {
            lineCount++;
            }

            cout << "file " << filename << " contains " << lineCount << " lines" << endl;

            lineTable = new string[lineCount];

            fs.clear();
            fs.seekp(0, ios::beg);

            for (size_t i = 0; i < lineCount; i++) {
                getline(fs, lineTable[i]);
            }

            fs.close();
        }

        else {
            cerr << "Cannot open file -->" << filename << "<--" << endl;
        }
    }

    Text& Text::operator=(const Text& rhs) {

        if (this != &rhs) {

            if (lineTable) {
                delete[] lineTable;
            }

            lineCount = rhs.lineCount;
            lineTable = new string[lineCount];

            for (size_t i = 0; i < lineCount; i++) {
                lineTable[i] = rhs.lineTable[i];
            }
        }

        return *this;
    }

    Text::Text(const Text& rhs) {

        lineTable = nullptr;
        *this = rhs;
    }

    Text& Text::operator=(Text&& rhs) {

        if (this != &rhs) {

            if (lineTable) {
                delete[] lineTable;
            }

            lineCount = rhs.lineCount;
            lineTable = rhs.lineTable;

            rhs.lineCount = 0;
            rhs.lineTable = nullptr;
        }

        return *this;
    }

    Text::Text(Text&& rhs) {

        lineTable = nullptr;
        *this = rhs;
    }
} // namespace w3
