#ifndef _ANDROID_FACTORY_HEAD_H
#define _ANDROID_FACTORY_HEAD_H

#include "PhoneFactory.hpp"
#include "AndroidPhone.hpp"

class AndroidFactory:public PhoneFactory
{
	public:
		AbstractPhone *getPhone(void)
		{
			return new AndroidPhone;
		}
};

#endif
