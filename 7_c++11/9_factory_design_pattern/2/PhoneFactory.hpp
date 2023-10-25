#ifndef _PHONE_FACTORY_HEAD_H
#define _PHONE_FACTORY_HEAD_H

#include "Phone.hpp"

class PhoneFactory
{
	public:
		 virtual AbstractPhone *getPhone(void) = 0;
};

#endif
