#ifndef _HERO_H__
#define _HERO_H__
#include <iostream>
#include <string.h>
using namespace std;

class Hero
{
public:
    Hero(const string &name)
    {
        cout << "hero(const string &name)" << endl;
        this->name = name;
    }
    ~Hero()
    {
        cout << "~Hero" << endl;
    }
    virtual void skill(void)
    {
        cout << "skill" << endl;
    }
    string getName(void) const
    {
        return name;
    }

private:
    string name;
};

#endif
