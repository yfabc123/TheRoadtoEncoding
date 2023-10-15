#ifndef _HERO_H_
#define _HERO_H_
#include <iostream>
using namespace std;

class Hero
{
public:
    Hero(const string name)
    {
        cout << "Hero(const string name)" << endl;
        this->name = name;
    }
    ~Hero()
    {
        cout << "~Hero" << endl;
    }
    string getName()
    {
        return name;
    }

private:
    string name;
};

#endif
