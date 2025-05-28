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

/* ==== Relay Vars ==== */
bool relayEnabled = false;

/* ==== Button Vars ==== */
bool funcPressed = false;
bool enablePressed = false;


bool ledEnabled = false;

void setup()
{
  pinMode(1, OUTPUT);
  SCREEN::init();
  SCREEN::print("test");
}

void loop()
{
  currentMillis = millis();
  SCREEN::setCursor(0, 1);
  SCREEN::print(int(currentMillis/1000));
}