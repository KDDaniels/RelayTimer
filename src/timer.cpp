#include "timer.h"
#include <Arduino.h>

namespace
{
    unsigned long currentMillis = 0;
    unsigned long timerTarget = 0;
    unsigned long interval = 1000;

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
        currentMillis = millis();
    }

    unsigned long getCurrentTime()
    {
        return currentMillis;
    }

    unsigned long getCurrentTime(int type)
    {
        unsigned long t;

        switch(type)
        {
            case(0):
                t = TIME_DEFS::MILLIS; // not necessary but looks better
                break;
            case(1):
                t = TIME_DEFS::SECOND;
                break;
            case(2):
                t = TIME_DEFS::MINUTE;
                break;
            case(3):
                t = TIME_DEFS::HOUR;
                break;
                
            default:
                break;
        }
        
        return (currentMillis / t);
    }

    unsigned long getTargetTime(unsigned long interval)
    {
        return (currentMillis + interval);
    }

    bool hasIntervalPassed()
    {
        return (currentMillis >= timerTarget);
    }

    bool hasIntervalPassed(unsigned long targetTime)
    {
        return (currentMillis >= targetTime);
    }

    void setInterval(unsigned long val)
    {
        interval = val;
    }

    void setTimerTarget(unsigned long interval)
    {
        timerTarget = currentMillis + interval;
    }

    unsigned long getTimeRemaining()
    {
        return (timerTarget - currentMillis);
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
}