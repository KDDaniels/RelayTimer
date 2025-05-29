#include "timer.h"
#include <Arduino.h>

/*

NEEDED:
vars:
now (currentMillis)
timeRemaining (time left for countdown)
timeRemainingBtn (time left to consider button held)
lastUpdate (last time updated, now-lastUpdate = time to subtract from timeRemaining)


functions:
update -> update current time
updateTimer -> update time remaining




*/

namespace
{
    unsigned long now = 0;

    unsigned long timeRemaining = 0;
    unsigned long timeRemainingBtn = 1000;
    unsigned long lastUpdate = 0;

    char buffer[8];
}

namespace TIME_DEFS
{
    constexpr unsigned long MILLIS = 1;
    constexpr unsigned long SECOND = 1000;
    constexpr unsigned long MINUTE = 60 * SECOND;
    constexpr unsigned long HOUR = 60 * MINUTE;
}

namespace TIMER
{
    void update()
    {
        now = millis();
    }

    void updateTimeRemaining()
    {
        timeRemaining = ((now-lastUpdate) >= timeRemaining) ? 0 : timeRemaining - (now-lastUpdate);
        lastUpdate = now;
    }

    void setTimeRemaining(unsigned long time)
    {
        timeRemaining = time;
    }

    unsigned long getTimeRemaining()
    {
        return timeRemaining;
    }

    char* getTimeRemainingFormatted()
    {
        unsigned long timeLeft = getTimeRemaining();
        unsigned int totalSeconds = timeLeft / 1000;
        unsigned int hour = (totalSeconds / 60 / 60) % 60;
        unsigned int min = (totalSeconds / 60) % 60;
        unsigned int sec = totalSeconds % 60;

        sprintf(buffer, "%01u:%02u:%02u", hour, min, sec);
        return buffer;
    }

    char* getTimeRemainingFormatted(unsigned long time)
    {
        unsigned long timeLeft = time;
        unsigned int totalSeconds = timeLeft / 1000;
        unsigned int hour = (totalSeconds / 60 / 60) % 60;
        unsigned int min = (totalSeconds / 60) % 60;
        unsigned int sec = totalSeconds % 60;

        sprintf(buffer, "%01u:%02u:%02u", hour, min, sec);
        return buffer;
    } 
}