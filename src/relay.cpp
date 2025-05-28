#include "relay.h"
#include <Arduino.h>

namespace
{
    bool isEnabled = false;
    int pin;
}

namespace RELAY
{
    void init(int relayPin)
    {
        pin = relayPin;
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }

    void toggle()
    {
        isEnabled = !isEnabled;
        digitalWrite(pin, isEnabled);
    }

    bool getState()
    {
        return isEnabled;
    }

}