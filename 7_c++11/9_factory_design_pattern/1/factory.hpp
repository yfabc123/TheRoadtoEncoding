#ifndef _FACTORY_H__
#define _FACTORY_H__
#include "phone.hpp"
#include "apple.hpp"
#include "android.hpp"
#include <iostream>
using namespace std;
class Factory
{
public:
    static Phone *get(string name)
    {
        if (name == "android")
        {
            return new Android();
        }
        else if (name == "apple")
        {
            return new Apple();
        }
    }
};

#endif
