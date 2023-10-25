#ifndef _APPLE_FACTORY_HEAD_H
#define _APPLE_FACTORY_HEAD_H

#include "PhoneFactory.hpp"
#include "ApplePhone.hpp"

class AppleFactory:public PhoneFactory
{
	public:
		AbstractPhone *getPhone(void)
		{
			return new ApplePhone;
		}
};

#endif
