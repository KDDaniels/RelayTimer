#ifndef DISPLAY_H
#define DISPLAY_H

namespace SCREEN
{
    void init();
    void print(const char* message);
    void print(int message);
    void setCursor(int row, int col);
    void clear();
}

#endif