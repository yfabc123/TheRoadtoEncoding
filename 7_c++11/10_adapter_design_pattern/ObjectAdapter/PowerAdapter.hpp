#ifndef _POWERADAPTER_HEAD_H
#define _POWERADAPTER_HEAD_H
#include <iostream>
#include "Plug.hpp"
#include "Target.hpp"

using namespace std;

class PowerAdapter:public Target
{
public:
	void setPlug(Plug *plug)
	{
		this->plug = plug;
	}
	int getOutput5V(void)
	{
		int v = plug->outputV();
		int div = v/5;

		cout << v << " change " << v/div << endl;

		return v/div;
	}

private:
	Plug *plug;
};

#endif
