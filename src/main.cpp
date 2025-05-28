#include <Arduino.h>

#include "buttons.h"
#include "display.h"
#include "relay.h"
#include "timer.h"

#define RELAY_PIN 1
#define FUNC_BTN 3
#define TOGGLE_BTN 4

/* ==== Time Vars ==== */
unsigned long currentMillis = 0;

void setup()
{
  SCREEN::init();
  RELAY::init(RELAY_PIN);
}

void loop()
{
  currentMillis = millis();
  SCREEN::setCursor(0, 1);
  SCREEN::print(int(currentMillis/1000));

  RELAY::toggle();

  SCREEN::setCursor(0, 0);
  SCREEN::print((RELAY::getState()) ? "enabled  " : "disabled  ");

  delay(1000);
}