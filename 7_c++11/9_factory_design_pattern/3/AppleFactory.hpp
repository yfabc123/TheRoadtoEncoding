#ifndef _APPLE_FACTORY_
#define _APPLE_FACTORY_
#include "PhoneFactory.hpp"
#include "ApplePhone.hpp"
#include "AppleShell.hpp"
class AppleFactory : public PhoneFactory
{
public:
    virtual ApplePhone *getPhone()
    {
        return new ApplePhone();
    }
    virtual AppleShell *getShell()
    {
        return new AppleShell();
    }
};
#endif
