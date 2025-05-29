#ifndef TIMER_H
#define TIMER_H

namespace TIMER
{
    void update();
    void updateTimeRemaining();
    void setTimeRemaining(unsigned long time);
    unsigned long getTimeRemaining();
    char* getTimeRemainingFormatted();
}

#endif