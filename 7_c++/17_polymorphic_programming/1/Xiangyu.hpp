#ifndef __XIANGYU_H__
#define __XIANGYU_H__
#include <iostream>
#include <string.h>
#include "Hero.hpp"
#include "Shooter.hpp"
#include "Skin.hpp"
using namespace std;

class Xiangyu : public Hero, public Shooter
{
public:
    Xiangyu(const string &name, int distance, int speed, string color) : Hero(name), Shooter(distance), skin(color)

    {
        cout << "Xiangyu(const string &name, int distance, int speed, string color)" << endl;
        this->speed = speed;
    }

    void show() const
    {
        cout << "Xiangyu name:" << getName() << endl;
        cout << "Xiangyu distance:" << getDistance() << endl;
        cout << "Xiangyu speed:" << speed << endl;
        cout << "Xiangyu skin:" << skin.getColor() << endl;
    }
    ~Xiangyu()
    {
        cout << "~Xiangyu()" << endl;
    }
    void skill()
    {
        cout << "恩赐解脱" << endl;
    }

private:
    int speed;
    Skin skin;
};

#endif