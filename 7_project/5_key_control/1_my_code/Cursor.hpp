#ifndef _CURSOR_HEAD_H
#define _CURSOR_HEAD_H

#include <iostream>
#include <functional>
using namespace std;
#define MIN_X 1
#define MAX_X 57
#define MIN_Y 1
#define MAX_Y 29
#define Y_STEP 2
#define X_STEP 4

// 屏幕坐标轴和棋盘关系  棋盘 横 :4*(x-1)+1     棋盘 纵 :2*(y-1)+1
class Cursor
{
public:
    enum Direction
    {
        UP,
        DOWN,
        LEFT,
        RIGHT,
    };

    Cursor() : x(29),
               y(15) // 设置正中间坐标
    {
        show();
    }
    void show() // 输出光标位置
    {
        fprintf(stderr, "\033[%d;%dH", y, x);
    }
    void moveUp()
    {
        if (y <= MIN_Y)
        {
            return;
        }
        y -= Y_STEP;
    }

    void moveDown()
    {
        if (y >= MAX_Y)
        {
            return;
        }
        y += Y_STEP;
    }
    void moveLeft()
    {
        if (x <= MIN_X)
        {
            return;
        }
        x -= X_STEP;
    }
    void moveRight()
    {
        if (x >= MAX_X)
        {
            return;
        }
        x += X_STEP;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    int setX(int x)
    {
        this->x = x;
    }
    int getY(int y)
    {
        this->y = y;
    }
    void move(Direction dir)
    {
        auto handle = fun_arr[dir];
        handle();
        show();
    }

private:
    int x;
    int y;
    function<void()> fun_arr[4]{
        bind(&Cursor::moveUp, this),
        bind(&Cursor::moveDown, this),
        bind(&Cursor::moveLeft, this),
        bind(&Cursor::moveRight, this)

    };
};
#endif