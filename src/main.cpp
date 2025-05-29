#include <Arduino.h>

#include "buttons.h"
#include "display.h"
#include "relay.h"
#include "timer.h"

#define RELAY_PIN 1
#define FUNC_BTN 3
#define TOGGLE_BTN 4

bool isRunning = false;

void setup()
{
  SCREEN::init();
  RELAY::init(RELAY_PIN);
  TIMER::setInterval(5000);
}

void loop()
{
  TIMER::update();
  
  // if enabled == true
  if (isRunning == true)
  {
    if (TIMER::hasIntervalPassed())
    {
      // enabled == false
      RELAY::toggle();
      TIMER::setTimerTarget(10000); // pass desired delay as arg
    }
  
    SCREEN::print("Time remaining: ", 0, 0);
    SCREEN::print(TIMER::getTimeRemainingFormatted(), 0, 1);
  }

  // else
  // print out adjustable time w/ text
}