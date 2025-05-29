#ifndef BUTTONS_H
#define BUTTONS_H

#include <avr/io.h>
#include <stdint.h>

namespace BUTTONS
{
    void init(uint8_t funcPin, uint8_t togglePin);
    bool isfPinPressed();
    bool istPinPressed();
}

#endif