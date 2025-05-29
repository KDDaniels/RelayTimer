#ifndef BUTTONS_H
#define BUTTONS_H

namespace BUTTONS
{
    void init(int funcPin, int togglePin);
    bool isfPinPressed();
    bool istPinPressed();
}

#endif