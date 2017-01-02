#include "Message.h"
#include <iostream>
using namespace std;
using namespace w5;

Message::Message(std::ifstream& in, char c) {

    isEmpty = false;

    if (in) {

        string line;
        getline(in, line, c);
        std::size_t found = line.find('@');

        if (found == std::string::npos) {

            found = line.find(" ");

            if (found != std::string::npos) {

                user = line.substr(0, found + 1);
                tweetContent = line.substr(found + 1);
            }

            else {
                user = line;
            }
        }

        else {

            user = line.substr(0, line.find(" @") + 1);

            line.erase(0, line.find(" @") + 2 );

            reply = line.substr(0, line.find(" ") + 1);
            tweetContent = line.substr(line.find(" ") + 1);
        }

        if (tweetContent == "") {
            isEmpty = true;
        }
    }
}

bool Message::empty() const {
    return isEmpty;
}

void Message::display(std::ostream& os) const {

    os << "Message\n";
    os << " User  : " << user << endl;

    if (reply != "") {
        os << " Reply : " << reply << endl;
    }

    if (tweetContent != "") {
        os << " Tweet : " << tweetContent << endl;
    }

    os << endl;
}