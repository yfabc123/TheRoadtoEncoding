#ifndef _LUBAN_H__
#define _LUBAN_H__
#include <iostream>
#include <string.h>
#include "Hero.h"
#include "Shooter.hpp"
using namespace std;

class Luban : public Hero, public Shooter
{
public:
    Luban(const string &name, int distance, int leglen) : Hero(name), Shooter(distance)

    {
        cout << "Luban(const string &name, int distance, int leglen)" << endl;
        this->leglen = leglen;
    }

    void show() const
    {
        cout << "luban name:" << getName() << endl;
        cout << "luban distance:" << getDistance() << endl;
        cout << "luban leglen:" << leglen << endl;
    }
    ~Luban()
    {
        cout << "~Luban()" << endl;
    }
    void skill(void);

private:
    int leglen;
};

#endif