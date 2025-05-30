#include "timer.h"


namespace
{
    uint32_t now = 0;
    uint32_t offset = 0;

    uint32_t timeRemaining = 0;
    uint32_t lastUpdate = 0;

    bool isPaused = false;

    char buffer[8];
}

namespace TIME_DEFS
{
    constexpr uint32_t MILLIS = 1;
    constexpr uint32_t SECOND = 1000;
    constexpr uint32_t MINUTE = 60 * SECOND;
    constexpr uint32_t HOUR = 60 * MINUTE;
}

namespace TIMER
{
    void update()
    {
        now = millis() - offset;

        if (now > 2592000000) // 30 days in milliseconds
        {
            // Handles overflow (hopefully)
            offset = millis();
        }
    }

    void updateTimeRemaining()
    {
        if (!isPaused)
        {
            uint32_t elapsed = now - lastUpdate;
            timeRemaining = (elapsed >= timeRemaining) ? 0 : timeRemaining - elapsed;
            lastUpdate = now;
        }
    }

    void setTimeRemaining(uint32_t time)
    {
        timeRemaining = time;
    }

    uint32_t getTimeRemaining()
    {
        return timeRemaining;
    }

    char* getTimeRemainingFormatted()
    {
        uint32_t timeLeft = getTimeRemaining();
        uint16_t totalSeconds = timeLeft / 1000;
        uint16_t hour = (totalSeconds / 60 / 60) % 60;
        uint16_t min = (totalSeconds / 60) % 60;
        uint16_t sec = totalSeconds % 60;

        sprintf(buffer, "%01u:%02u:%02u", hour, min, sec);
        return buffer;
    }

    char* getTimeRemainingFormatted(uint32_t time)
    {
        uint32_t timeLeft = time;
        uint16_t totalSeconds = timeLeft / 1000;
        uint16_t hour = (totalSeconds / 60 / 60) % 60;
        uint16_t min = (totalSeconds / 60) % 60;
        uint16_t sec = totalSeconds % 60;

        sprintf(buffer, "%01u:%02u:%02u", hour, min, sec);
        return buffer;
    }

    void pause()
    {
        isPaused = true;
    }

    void unpause()
    {
        isPaused = false;
        lastUpdate = now;
    }

    void togglePause()
    {
        if (isPaused)
        {
            unpause();
        }
        else
        {
            pause();
        }
    }

    bool paused()
    {
        return isPaused;
    }
}