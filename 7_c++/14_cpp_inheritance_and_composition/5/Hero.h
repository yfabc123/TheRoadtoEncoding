#ifndef _HERO_H__
#define _HERO_H__
#include <iostream>
#include <string.h>
using namespace std;

class Hero
{
public:
    Hero(const string &name = "hero");
    ~Hero();
    void skill(void);
    string getName(void) const
    {
        return name;
    }

private:
    string name;
};

#endif