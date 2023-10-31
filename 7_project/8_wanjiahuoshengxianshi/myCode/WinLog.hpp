#ifndef _WINLOGO_HEAD_H_
#define _WINLOGO_HEAD_H_
#include <iostream>
#define CHESSBOARD_WIDTH 57
#define CHESSBOARD_HEIGHT 29
#define HORIZONTAL_OFFSET 2

using namespace std;
class WinLogo
{
public:
    WinLogo(int x = 0, int y = 0, int width = 25, int height = 15)
    {
        if (!x)
        {
            this->x = CHESSBOARD_WIDTH + HORIZONTAL_OFFSET;
        }
        else
        {
            this->x = x;
        }
        if (!y)
        {
            this->y = (CHESSBOARD_HEIGHT - height) / 2;
        }
        else
        {
            this->y = y;
        }
        this->width = width;
        this->height = height;
    }
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

    void drawText(int x, int y, const char *text, int fontcolor, int background)
    {
        fprintf(stderr, "\033[%d;%dH\033[%d;%dm%s\033[0m", y, x, background, fontcolor, text);
    }
    void showWinPlayer(string name, string color)
    {
        // drawRectangle(x, y, width, height, 42);
        drawRectangle(x + 2, y + 1, width, height, 47);

        string text1 = "胜方棋色:";
        text1 += color;
        drawText(x + 3, y + height / 2 - 2, text1.c_str(), 34, 47);

        string text2 = "胜方姓名:";
        text2 += name;
        drawText(x + 3, y + height / 2 - 2 + 1, text2.c_str(), 34, 47);

        string text3 = "游戏开发者:叶凡";

        drawText(x + 3, y + height / 2 - 2 + 2, text3.c_str(), 34, 47);
    }

private:
    int x;
    int y;
    int width;
    int height;
};
#endif