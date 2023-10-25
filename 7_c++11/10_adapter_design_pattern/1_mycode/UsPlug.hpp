#ifndef _USPLUG_HEAD_H_
#define _USPLUG_HEAD_H_
#include "Plug.hpp"

class UsPlug : public Plug
{
public:
    virtual int outputv()
    {
        return 280;
    }
};

#endif
