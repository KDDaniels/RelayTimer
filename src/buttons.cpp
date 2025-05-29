#include "buttons.h"
#include <Arduino.h>

namespace
{
    int fPin;
    int tPin;
    bool fPinPressed = false;
    bool tPinPressed = false;
}

namespace BUTTONS
{
    void init(int funcPin, int togglePin)
    {
        fPin = funcPin;
        tPin = togglePin;

        pinMode(fPin, INPUT_PULLUP);
        pinMode(tPin, INPUT_PULLUP);
    }

    bool isfPinPressed()
    {
        return (digitalRead(fPin) == LOW);
    }

    bool istPinPressed()
    {
        return (digitalRead(tPin) == LOW);
    }
}