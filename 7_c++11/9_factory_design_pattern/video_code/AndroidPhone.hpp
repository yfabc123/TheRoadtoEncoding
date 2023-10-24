#ifndef _ANDROID_PHONE_HEAD_H
#define _ANDROID_PHONE_HEAD_H

#include "Phone.hpp"
#include <iostream>

using namespace std;

class AndroidPhone:public AbstractPhone
{
	public:
		void call(void)
		{
			cout << "Android Call" << endl;
		}

		void message(void)
		{
			cout << "Android Message" << endl;
		}
};

#endif
