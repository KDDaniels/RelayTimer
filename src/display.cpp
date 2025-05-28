#include "display.h"
#include <Arduino.h>
#include <TinyWireM.h>
#include <LiquidCrystal_attiny.h>

namespace
{
    LiquidCrystal_I2C lcd(0x27, 16, 2);
}

namespace SCREEN
{
    void init()
    {
        lcd.init();
        lcd.backlight();
        lcd.clear();
        lcd.setCursor(0, 0);
    }

    void print(const char* message)
    {
        lcd.print(message);
    }

    void print(uint8_t message)
    {
        lcd.print(message);
    }

    void setCursor(uint8_t row, uint8_t col)
    {
        lcd.setCursor(row, col);
    }

    void clear()
    {
        lcd.clear();
    }

}