#ifndef _SKIN_H_
#define _SKIN_H_

#include <iostream>
using namespace std;
class Skin
{

public:
    Skin(string color)
    {
        cout << "Skin(const string color)" << endl;
        this->color = color;
    }
    ~Skin()
    {
        cout << "~Skin()" << endl;
    }
    string getColor() const
    {
        return color;
    }

private:
    string color;
};

#endif