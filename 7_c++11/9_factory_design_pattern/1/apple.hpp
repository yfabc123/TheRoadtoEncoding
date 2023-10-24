#ifndef _APPLE_H__
#define _APPLE_H__
#include "phone.hpp"
#include <iostream>
using namespace std;
class Apple : public Phone
{
public:
    void call()
    {
        cout << "Apple call" << endl;
    }
    void message()
    {
        cout << "Apple message" << endl;
    }
};

#endif
