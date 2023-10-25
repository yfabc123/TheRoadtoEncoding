#ifndef _REALGIRL_HEAD_H
#define _REALGIRL_HEAD_H
#include "Girl.hpp"
#include <iostream>
using namespace std;
class RealGirl : public Girl
{
public:
    RealGirl(const string name) : name(name)
    {
    }

private:
     void marry(int money)
    {
        cout << "money:" << money << "可以娶" << name << endl;
    }

    string name;
};
#endif