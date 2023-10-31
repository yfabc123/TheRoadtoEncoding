#ifndef _WINLOGO_HEAD_H_
#define _WINLOGO_HEAD_H_
#include <iostream>
using namespace std;
class WinLogo
{
public:
    void drawRectangle(int x, int y, int width, int height, int backgroundColor)
    {
        fprintf(stderr, "\033[%d;%dH", y, x);
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                fprintf(stderr, "\033[%d;%dH\033[%dm \033[0m", y + i, x + j, backgroundColor);
            }
        }
    }

    void showWinPlayer(const string name, string color)
    {
        drawRectangle(60, 7, 25, 15, 42);
        drawRectangle(62, 8, 25, 15, 47);
    }

private:
};
#endif