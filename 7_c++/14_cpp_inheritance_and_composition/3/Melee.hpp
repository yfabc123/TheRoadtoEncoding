#ifndef _REMOTE_H__
#define _REMOTE_H__
#include <iostream>

using namespace std;

class Melee
{
public:
    Melee(const int speed)
    {
        cout << "Melee(const int speed)" << endl;
        this->speed = speed;
    }
    ~Melee()
    {
        cout << "~Melee" << endl;
    }
    int getSpeed()
    {
        return speed;
    }

private:
    int speed;
};

#endif
