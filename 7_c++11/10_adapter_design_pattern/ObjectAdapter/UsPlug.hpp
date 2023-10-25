#ifndef _US_HEAD_H
#define _US_HEAD_H

#include "Plug.hpp"

class UsPlug : public Plug
{
public:
	int outputV(void)
	{
		return 100;
	}
};

#endif
