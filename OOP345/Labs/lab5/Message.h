#pragma once

#include <fstream>
#include <string>

using namespace std;

namespace w5 {

    class Message {
    private:
        bool isEmpty;
        string user;
        string reply;
        string tweetContent;

    public:
        Message() {};
        Message(std::ifstream& in, char c);
        bool empty() const;
        void display(std::ostream& os) const;
    };
}
