#ifndef __PA_H__
#define __PA_H__
#include <iostream>
#include "Hero.hpp"
#include "Melee.hpp"
using namespace std;

class Pa : public Hero, public Melee
{
public:
    Pa(const string name, const int speed, const int id) : Hero(name), Melee(speed)
    {
        cout << "Pa(const string name, const int speed, const int id) " << endl;
        this->id = id;
    }
    ~Pa()
    {
        cout << "~Melee" << endl;
    }
    int getId()
    {
        return id;
    }
    void show()
    {

        cout << "name:" << getName() << endl;
        cout << "speed:" << getSpeed() << endl;
        cout << "id:" << getId() << endl;
    }

private:
    int id;
};

#endif
