#ifndef _KEYHANDLE_HEAD_H
#define _KEYHANDLE_HEAD_H
#include <iostream>
#include <termio.h>
#include <unistd.h>
#include "Cursor.hpp"
struct termios tm_old;

class KeyHandle
{
public:
    KeyHandle()
    {
        struct termios tm;
        tcgetattr(0, &tm_old); // 文件描述符0 标准输入
        cfmakeraw(&tm);        // tm是输出参数用来保存将结构体属性设置为原始模式
        tcsetattr(0, 0, &tm);  // tm输入参数 设置当前的标准输入为原始模式即不回显 也不用输入回车程序直接检测到输入的字符
    }
    ~KeyHandle()
    {
        tcsetattr(0, 0, &tm_old); // 恢复正常输入属性
    }
    void control()
    {

        while (1)
        {
            char ch = getchar();
            switch (ch)
            {
            case 'i':
            case 'I':
                cursor.move(cursor.UP);
                break;
            case 'j':
            case 'J':
                cursor.move(cursor.LEFT);
                break;

            case 'k':
            case 'K':
                cursor.move(cursor.DOWN);
                break;

            case 'l':
            case 'L':
                cursor.move(cursor.RIGHT);
                break;
            case ' ':
                return;
            }
        }
    }

private:
    Cursor cursor;
};

#endif