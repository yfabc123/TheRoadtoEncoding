#ifndef _PROXY_HEAD_H
#define _PROXY_HEAD_H

#include "Girl.hpp"

class Proxy
{

public:
	void setMarryGirl(Girl *girl)
	{
		this->girl = girl;
	}

	void marry(int money)
	{
		if(money < 1000){
			cout << "No money no marry" << endl;
			return;
		}

		girl->marry(money);
	}

private:
	Girl *girl;
};

#endif
