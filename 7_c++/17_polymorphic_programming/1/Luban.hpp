#ifndef _LUBAN_H__
#define _LUBAN_H__

#include <iostream>
#include <string.h>
#include "Hero.hpp"
#include "Shooter.hpp"
#include "Skin.hpp"
using namespace std;

class Luban : public Hero, public Shooter
{
public:
    Luban(const string &name, int distance, int leglen, string color) : Hero(name), Shooter(distance), skin(color)

    {
        cout << "Luban(const string &name, int distance, int leglen)" << endl;
        this->leglen = leglen;
    }

    void show() const
    {
        cout << "luban name:" << getName() << endl;
        cout << "luban distance:" << getDistance() << endl;
        cout << "luban leglen:" << leglen << endl;
        cout << "luban skin:" << skin.getColor() << endl;
    }
    ~Luban()
    {
        cout << "~Luban()" << endl;
    }
    void skill(void) 
    {
        cout << "时间结界" << endl;
    }

private:
    int leglen;
    Skin skin;
};

#endif