#ifndef _TARGET_HEAD_H_
#define _TARGET_HEAD_H_
// 我有需求但是我实现不了 交给适配器实现
class Target
{
public:
    virtual int output5v() = 0;
};
#endif