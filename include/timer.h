#ifndef TIMER_H
#define TIMER_H

#include <Arduino.h>
#include <stdint.h>

namespace TIMER
{
    void init();
    void update();
    void updateTimeRemaining();
    void setTimeRemaining(uint32_t time);
    uint32_t getTimeRemaining();
    char* getTimeRemainingFormatted();
    char* getTimeRemainingFormatted(uint32_t time);
    void pause();
    void unpause();
    void togglePause();
    bool paused();
}

#endif