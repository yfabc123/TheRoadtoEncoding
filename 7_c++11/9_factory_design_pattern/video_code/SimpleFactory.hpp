#ifndef _SIMPLE_FACTORY_HEAD_H
#define _SIMPLE_FACTORY_HEAD_H

#include "AndroidPhone.hpp"
#include "ApplePhone.hpp"

class SimpleFactory
{
public:
	static AbstractPhone *getPhone(const string &name)
	{
		if (name == "Android")
		{
			return new AndroidPhone;
		}
		else if (name == "Apple")
		{
			return new ApplePhone;
		}
	}
};

#endif
