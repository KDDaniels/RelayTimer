#ifndef DISPLAY_H
#define DISPLAY_H

namespace SCREEN
{
    void init();
    void print(const char* message);
    void print(const char* message, int row, int col);
    void print(int message);
    void print(int message, int row, int col);
    void setCursor(int row, int col);
    void clear();
}

#endif