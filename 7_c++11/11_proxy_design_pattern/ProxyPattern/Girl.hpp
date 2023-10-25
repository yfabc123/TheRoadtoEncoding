#ifndef _GIRL_HEAD_H
#define _GIRL_HEAD_H

#include <iostream>

using namespace std;

class Girl
{

public:
	Girl(const string &name) : name(name)
	{
	}
	virtual void marry(int money) = 0;

protected:
	string name;
};

#endif
