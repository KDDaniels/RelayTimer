#ifndef DISPLAY_H
#define DISPLAY_H

namespace SCREEN
{
    void init();
    void print(const char* message);
    void print(uint8_t message);
    void setCursor(uint8_t row, uint8_t col);
    void clear();
}

#endif