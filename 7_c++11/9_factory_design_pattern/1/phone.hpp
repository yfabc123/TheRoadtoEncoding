#ifndef _PHONE_H__
#define _PHONE_H__
#include <iostream>
class Phone
{
public:
    virtual void call() = 0;
    virtual void message() = 0;
};

#endif
