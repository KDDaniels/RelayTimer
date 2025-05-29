#include "buttons.h"

namespace
{
    uint8_t fPin;
    uint8_t tPin;
    bool held = false;
}

namespace BUTTONS
{
    void init(uint8_t funcPin, uint8_t togglePin)
    {
        fPin = funcPin;
        tPin = togglePin;

        // Enable fPin as INPUT and PULLUP
        DDRB &= ~(1 << fPin);
        PORTB |= (1 << fPin);
        
        // Enable tPin as INPUT and PULLUP
        DDRB &= ~(1 << tPin);
        PORTB |= (1 << tPin);
    }

    bool isfPinPressed()
    {
        return !(PINB & (1 << fPin));
    }

    bool istPinPressed()
    {
        return !(PINB & (1 << tPin));
    }

    bool isHeld()
    {
        return held;
    }

    void holding()
    {
        held = true;
    }

    void notHolding()
    {
        held = false;
    }
}