#ifndef _KEYHANDLE_HEAD_H
#define _KEYHANDLE_HEAD_H

#include <iostream>
#include <termio.h>
#include <unistd.h>
#include "Cursor.hpp"
#include <map>
// struct termios tm_old;
#define PLACE_CHESS_KEY ' '
class KeyHandle
{
public:
    KeyHandle()
    {
        /* 比之前俄罗斯项目设置为原始模式更规范 */
        struct termios attr;
        tcgetattr(0, &attr);              // 获取属性
        attr.c_lflag &= ~(ICANON | ECHO); // 关闭回车确认和回显  ICANON:回车   ECHO: 回显模式
        tcsetattr(0, TCSANOW, &attr);     // 设置属性  TCSANOW:设置立即生效

        control.insert(pair<char, function<void(void)>>('i', bind(&Cursor::move, &cursor, Cursor::UP)));
        control.insert(pair<char, function<void(void)>>('I', bind(&Cursor::move, &cursor, Cursor::UP)));

        control.insert(pair<char, function<void(void)>>('k', bind(&Cursor::move, &cursor, Cursor::DOWN)));
        control.insert(pair<char, function<void(void)>>('K', bind(&Cursor::move, &cursor, Cursor::DOWN)));

        control.insert(pair<char, function<void(void)>>('j', bind(&Cursor::move, &cursor, Cursor::LEFT)));
        control.insert(pair<char, function<void(void)>>('J', bind(&Cursor::move, &cursor, Cursor::LEFT)));

        control.insert(pair<char, function<void(void)>>('l', bind(&Cursor::move, &cursor, Cursor::RIGHT)));
        control.insert(pair<char, function<void(void)>>('L', bind(&Cursor::move, &cursor, Cursor::RIGHT)));
    }
    ~KeyHandle()
    {
        struct termios attr;
        tcgetattr(0, &attr);             // 获取属性
        attr.c_lflag |= (ICANON | ECHO); // 回车确认和回显
        tcsetattr(0, TCSANOW, &attr);    // 设置属性
    }
    // 方向移动 ,放棋子  棋手 放一个棋子之后函数结束
    void waitPlayerPlaceChess(Player *player)
    {
        char ch;
        while (1)
        {
            ch = getchar();
            // 下棋逻辑
            if (PLACE_CHESS_KEY == ch)
            {
                bool ok = player->placeChess(cursor.getX(), cursor.getY());
                if (ok) // 只有在成功放下棋子后才退出循环
                {
                    break;
                }
            }
            else // 进入方向逻辑
            {
                map<char, function<void(void)>>::iterator itr = control.find(ch);
                if (itr != control.end())
                {
                    auto handle = itr->second;
                    handle();
                }
            }
        }
    }

private:
    Cursor cursor;
    map<char, function<void(void)>> control; // 存放函数
};

#endif