#ifndef _LUBAN_H__
#define _LUBAN_H__
#include <iostream>
#include <string.h>
#include "Hero.h"
#include "Shooter.hpp"
#include "Skin.hpp"
#include "Computer.hpp"
using namespace std;

class Luban : public Hero, public Shooter
{
public:
    Luban(const string &name, int distance, int leglen, string color, string brand)
        : Hero(name), Shooter(distance), skin(color), computer("apple")

    {
        cout << "Luban(const string &name, int distance, int leglen)" << endl;
        this->leglen = leglen;
    }

    void show() const
    {
        cout << getName() << "有" << computer.getBrand() << "电脑" << endl;
    }
    ~Luban()
    {
        cout << "~Luban()" << endl;
    }
    void skill(void);

private:
    int leglen;
    Skin skin;
    Computer computer;
};

#endif