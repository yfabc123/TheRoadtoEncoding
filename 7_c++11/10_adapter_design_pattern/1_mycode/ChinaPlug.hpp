#ifndef _CHINAPLUG_HEAD_H_
#define _CHINAPLUG_HEAD_H_
#include "Plug.hpp"

class ChinaPlug : public Plug
{
public:
    virtual int outputv()
    {
        return 220;
    }
};

#endif
