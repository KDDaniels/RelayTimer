#include "relay.h"

namespace
{
    uint8_t pin;
}

namespace RELAY
{
    void init(uint8_t relayPin)
    {
        pin = relayPin;
        DDRB |= (1 << pin);
        PORTB &= ~(1 << pin);
    }

    void enable()
    {
        PORTB |= (1 << pin);
    }
    
    void disable()
    {
        PORTB &= ~(1 << pin);
    }
}