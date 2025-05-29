/*
RelayTimer is a simple interactive timer to control a relay.
Copyright (C) 2025 Kendall Daniels

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "buttons.h"
#include "display.h"
#include "relay.h"
#include "timer.h"

#define RELAY_PIN PB1
#define FUNC_PIN PB3
#define TOGGLE_PIN PB4

const uint32_t TIMER_INCREMENT = 5000;

bool isRunning = false;

void setup()
{
  SCREEN::init();
  RELAY::init(RELAY_PIN);
  BUTTONS::init(FUNC_PIN, TOGGLE_PIN);

  SCREEN::print("Select time            ", 0, 0);
  SCREEN::print(TIMER::getTimeRemainingFormatted(), 0, 1);
}

void loop()
{
  TIMER::update();
  if (isRunning == true)
  {
    if (!TIMER::paused())
    {
      // Updates the time if not paused
      TIMER::updateTimeRemaining();
      SCREEN::print("Time remaining:     ", 0, 0);
      SCREEN::print(TIMER::getTimeRemainingFormatted(), 0, 1);
    }
    else
    {
      if (BUTTONS::istPinPressed() && BUTTONS::isfPinPressed() && !BUTTONS::isHeld())
      {
        // Resets the timer back to initial state
        TIMER::setTimeRemaining(0);
        SCREEN::print("Select time            ", 0, 0);
        SCREEN::print(TIMER::getTimeRemainingFormatted(), 0, 1);
        isRunning = false;
        TIMER::unpause();
        BUTTONS::holding();
      }
    }

    if (BUTTONS::istPinPressed() && !BUTTONS::isHeld())
    {
      // Pauses the timer
      TIMER::togglePause();
      RELAY::toggle();
      SCREEN::print("Paused            ", 0, 0);
      BUTTONS::holding();
    }
    else if (!BUTTONS::istPinPressed() && BUTTONS::isHeld())
    {
      // Resets toggle button state if not held
      BUTTONS::notHolding();      
    }

    if (TIMER::getTimeRemaining() == 0)
    {
      // Timer hits 0 time remaining, resets to initial state
      RELAY::disable();
      SCREEN::print("Select time            ", 0, 0);
      SCREEN::print(TIMER::getTimeRemainingFormatted(), 0, 1);
      isRunning = false;
    }
  }
  else
  {
    if (!BUTTONS::isHeld())
    {
      if (BUTTONS::isfPinPressed() && !BUTTONS::istPinPressed())
      {
        // If FUNC pin is pressed, add time to timer and display
        TIMER::setTimeRemaining(TIMER::getTimeRemaining() + TIMER_INCREMENT);
        SCREEN::print(TIMER::getTimeRemainingFormatted(), 0, 1);
      }
      else if (BUTTONS::istPinPressed() && BUTTONS::isfPinPressed())
      {
        // If FUNC and TOGGLE are pressed, reset timer to initial state
        TIMER::setTimeRemaining(0);
        SCREEN::print("Select time            ", 0, 0);
        SCREEN::print(TIMER::getTimeRemainingFormatted(), 0, 1);
        BUTTONS::holding();
      }
      else if (BUTTONS::istPinPressed() && TIMER::getTimeRemaining() != 0)
      {
        // If TOGGLE pressed, start timer
        isRunning = true;
        TIMER::unpause();
        RELAY::enable();
        BUTTONS::holding();
      }
    }
    else if (!BUTTONS::istPinPressed() && !BUTTONS::isfPinPressed())
    {
      // Resets button state if neither are pressed
      BUTTONS::notHolding();
    }
  }
}