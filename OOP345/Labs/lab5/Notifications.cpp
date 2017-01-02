#include "Notifications.h"

using namespace w5;

Notifications::Notifications(const Notifications& rhs) {

    messages = nullptr;
    *this = rhs;
}

Notifications& Notifications::operator=(const Notifications& rhs) {

    if (this != &rhs) {
        if(messages) {

            delete [] messages;
            messages = nullptr;
        }

        count = rhs.count;

        if (rhs.messages) {

            messages = new Message[count];

            for (int i = 0; i < count; i++) {
                messages[i] = rhs.messages[i];
            }
        }
    }

    return *this;
}

Notifications::Notifications(Notifications&& rhs) {

    messages = rhs.messages;
    count = rhs.count;
    rhs.messages = nullptr;
    rhs.count = 0;
}

Notifications&& Notifications::operator=(Notifications&& rhs) {

    if (this != &rhs) {
        if (messages) {
            delete [] messages;
        }

        messages = rhs.messages;
        count = rhs.count;
        rhs.messages = nullptr;
        rhs.count = 0;
    }

    return std::move(*this);
}

Notifications::~Notifications() {

    if (messages) {

        delete [] messages;
        messages = nullptr;
    }
}

void Notifications::operator+=(const Message& msg) {

    if (!messages) {

        messages = new Message[MAX_MESSAGE];
        count = 0;
    }

    if (count < MAX_MESSAGE) {
        messages[count++] = msg;
    }

    else {
        cout << "Too many messages. Only " << MAX_MESSAGE << " messages are allowed." << endl;
    }
}

void Notifications::display(std::ostream& os) const {

    for (int i = 0; i < count; i++) {
        messages[i].display(os);
    }
}