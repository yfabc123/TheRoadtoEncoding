#ifndef _ADAPTER_HEAD_H_
#define _ADAPTER_HEAD_H_
#include <iostream>
#include "Plug.hpp"
#include "ChinaPlug.hpp"
#include "Target.hpp"
using namespace std;
class Adapter : public Target, public ChinaPlug
{
public:
    virtual int output5v()
    {
        cout << "统一转成5v" << endl;

        int div = outputv() / 5;
        return outputv() / div;
    }
};

#endif
