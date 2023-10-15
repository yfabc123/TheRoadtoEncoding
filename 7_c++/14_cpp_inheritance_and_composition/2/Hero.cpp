#include "Hero.h"

Hero::Hero(const string &name)
{
    cout << "hero(const string &name)" << endl;
    this->name = name;
}
Hero::~Hero()
{
    cout << "~Hero" << endl;
}
void Hero::skill(void)
{
    cout << "skill" << endl;
}