#ifndef RELAY_H
#define RELAY_H

namespace RELAY
{
    void init(int relayPin);
    void toggle();
    bool getState();
    void enable();
    void disable();
}

#endif