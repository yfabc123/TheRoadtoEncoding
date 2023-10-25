#ifndef _APPLE_PHONE_HEAD_H
#define _APPLE_PHONE_HEAD_H

#include "Phone.hpp"
#include <iostream>

using namespace std;

class ApplePhone:public AbstractPhone
{
	public:
		void call(void)
		{
			cout << "Apple Call" << endl;
		}

		void message(void)
		{
			cout << "Apple Message" << endl;
		}
};

#endif
