// #ifndef _ADD_H__
// #define _ADD_H__

// extern int add(int a, int b);
// extern int sub(int a, int b);

// #endif

#ifndef _AS_HEAD_H
#define _AS_HEAD_H

#ifdef __cplusplus // 问了下gpt:这个预处理器指令检查是否正在编译c++代码 如果是,则宏定义值为正,否则为0
extern "C"         // 这是C++的一种特性，用于指示编译器按照C语言的方式来处理函数 也就是告诉编译器不要对这个块中的函数进行名称修饰
{
#endif

    extern int add(int a, int b);
    extern int sub(int a, int b);

#ifdef __cplusplus
}
#endif

#endif
