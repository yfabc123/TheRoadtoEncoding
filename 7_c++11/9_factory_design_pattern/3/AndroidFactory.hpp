#ifndef _ANDROID_FACTORY_
#define _ANDROID_FACTORY_
#include "PhoneFactory.hpp"
#include "AndroidPhone.hpp"
#include "AndroidShell.hpp"
class AndroidFactory : public PhoneFactory
{
public:
    virtual AndroidPhone *getPhone()
    {
        return new AndroidPhone();
    }
    virtual AndroidShell *getShell()
    {
        return new AndroidShell();
    }
};
#endif
