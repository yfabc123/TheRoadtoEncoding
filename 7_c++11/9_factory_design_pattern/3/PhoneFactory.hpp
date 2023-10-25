#ifndef _PHONE_FACTORY_
#define _PHONE_FACTORY_
#include "phone.hpp"
#include "Shell.hpp"
class PhoneFactory
{
public:
    virtual Phone *getPhone() = 0;
    virtual Shell *getShell() = 0;
};
#endif
