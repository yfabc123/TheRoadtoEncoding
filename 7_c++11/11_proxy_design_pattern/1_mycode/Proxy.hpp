#ifndef _PROXY_HEAD_H_
#define _PROXY_HEAD_H_
#include "Girl.hpp"
class Proxy
{

public:
    Proxy(Girl *girl) : girl(girl)
    {
    }
    void marry(int money)
    {
        if (money < 1000000)
        {
            cout << "钱不够单着吧" << endl;
        }
        else
        {
            girl->marry(money);
        }
    }

private:
    Girl *girl;
};

#endif