#ifndef RELAY_H
#define RELAY_H

#include <avr/io.h>
#include <stdint.h>

namespace RELAY
{
    void init(uint8_t relayPin);
    void enable();
    void disable();
}

#endif