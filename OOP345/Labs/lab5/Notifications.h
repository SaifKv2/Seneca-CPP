#pragma once

#include <iostream>
#include "Message.h"
#define MAX_MESSAGE 10

namespace w5 {

    class Notifications {
    private:
        int count;
        Message* messages;

    public:
        Notifications() {};
        Notifications(const Notifications& rhs);
        Notifications& operator=(const Notifications& rhs);
        Notifications(Notifications&& rhs);
        Notifications&& operator=(Notifications&& rhs);
        ~Notifications();
        void operator+=(const Message& msg);
        void display(std::ostream& os) const;
    };
}
