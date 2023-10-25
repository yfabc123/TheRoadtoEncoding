#ifndef _POWERADAPTER_HEAD_H
#define _POWERADAPTER_HEAD_H
#include <iostream>
#include "Target.hpp"
#include "ChinaPlug.hpp"
#include "Plug.hpp"

using namespace std;

class PowerAdapter : public Target, public ChinaPlug
{
public:
	int getOutput5V(void)
	{
		int v = outputV();
		int div = v / 5;

		cout << v << " change " << v / div << endl;

		return v / div;
	}
};

#endif
