#ifndef TIMER_H
#define TIMER_H

namespace TIMER
{
    void update();
    unsigned long getCurrentTime();
    unsigned long getCurrentTime(int type);
    unsigned long getTargetTime(unsigned long interval);
    bool hasIntervalPassed();
    bool hasIntervalPassed(unsigned long targetTime);
    void setInterval(unsigned long val);
    void setTimerTarget(unsigned long interval);
    unsigned long getTimeRemaining();
    char* getTimeRemainingFormatted();
}

#endif