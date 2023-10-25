#ifndef _REALGIRL_HEAD_H
#define _REALGIRL_HEAD_H

#include "Girl.hpp"

class RealGirl : public Girl
{
public:
	RealGirl(const string &name = "cuihua") : Girl(name)
	{
	}
	void marry(int money)
	{
		cout<<"结婚"<<endl;
		cout << "Marry name:" << name << ",money " << money << endl;
	}
};

#endif
