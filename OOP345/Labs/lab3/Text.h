#ifndef _TEXT_H
#define _TEXT_H
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

namespace w3 {

    class Text {
        string* lineTable;
        size_t lineCount;

    public:
        Text() : lineCount(0), lineTable(nullptr) {}
        ~Text();
        Text(const char* filename);

        Text& operator=(const Text& rhs);

        Text(const Text& rhs);

        Text& operator=(Text&& rhs);

        Text(Text&& rhs);

        size_t size() const { return lineCount; }
    };

} // namespace w3

#endif // _TEXT_H