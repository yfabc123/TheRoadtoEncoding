#ifndef _PHONE_HEAD_H
#define _PHONE_HEAD_H

class AbstractPhone
{
	public:
		virtual void call(void) = 0;
		virtual void message(void) = 0;
};

#endif
