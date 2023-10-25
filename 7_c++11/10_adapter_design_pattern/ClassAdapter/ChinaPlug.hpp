#ifndef _CHINAPLUG_HEAD_H
#define _CHINAPLUG_HEAD_H

#include "Plug.hpp"

class ChinaPlug:public Plug
{
	public:
		int outputV(void)
		{
			return getOutput220V();
		}

		int getOutput220V(void)
		{
			return 220;
		}
};

#endif
