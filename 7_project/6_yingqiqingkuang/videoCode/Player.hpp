#ifndef _PLAYER_HEAD_H_
#define _PLAYER_HEAD_H_
#include <iostream>
using namespace std;
class Player
{
public:
    Player(const string &name, const string &color) : name(name), color(color) {}
    string getName() const
    {
        return name;
    }
    string getColor() const
    {

        return color;
    }
    virtual bool placeChess(int x, int y) = 0;

private:
    string name;
    string color;
};

#endif