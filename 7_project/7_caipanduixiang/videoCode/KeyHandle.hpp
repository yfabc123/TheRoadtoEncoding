#ifndef _KEYHANDLE_HEAD_H
#define _KEYHANDLE_HEAD_H

#include <iostream>
#include <termio.h>
#include <unistd.h>
#include "Cursor.hpp"
#include <map>
struct termios tm_old;
#define PLACE_CHESS_KEY ' '
class KeyHandle
{
public:
    KeyHandle()
    {
        struct termios tm;
        tcgetattr(0, &tm_old); // 文件描述符0 标准输入
        cfmakeraw(&tm);        // tm是输出参数用来保存将结构体属性设置为原始模式
        tcsetattr(0, 0, &tm);  // tm输入参数 设置当前的标准输入为原始模式即不回显 也不用输入回车程序直接检测到输入的字符
                               // 把具体de
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
        tcsetattr(0, 0, &tm_old); // 恢复正常输入属性
    }
    // 方向移动 ,放棋子  棋手 放一个棋子之后函数结束
    void waitPlayerPlaceChess(Player *player)
    {
        char ch;
        while (1)
        {
            ch = getchar();
            if ('q' == ch)
            {
                return;
            }
            if (PLACE_CHESS_KEY == ch)
            {
                player->placeChess(cursor.getX(), cursor.getY());
                // return;
            }
            else
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