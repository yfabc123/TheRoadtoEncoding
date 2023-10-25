#ifndef _ADAPTER_HEAD_H_
#define _ADAPTER_HEAD_H_
#include <iostream>
#include "Plug.hpp"
#include "Target.hpp"
using namespace std;
class Adapter :  public Target
{
public:
    void change(Plug *temp) // 获取到插座对象信息 然后转换
    {
        cout << "获取插座信息" << endl;
        plug = temp;
    }
    virtual int output5v()
    {
        cout << "统一转成5v" << endl;

        int div = plug->outputv() / 5;
        return plug->outputv() / div;
    }

private:
    Plug *plug;
};

#endif
