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

    void print(const char* message, int row, int col)
    {
        setCursor(row, col);
        lcd.print(message);
    }

    void print(int message)
    {
        lcd.print(message);
    }

    void print(int message, int row, int col)
    {
        setCursor(row, col);
        lcd.print(message);
    }

    void setCursor(int row, int col)
    {
        lcd.setCursor(row, col);
    }

    void clear()
    {
        lcd.clear();
    }

}