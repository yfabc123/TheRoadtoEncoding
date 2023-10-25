#ifndef _APPLE_PHONE_
#define _APPLE_PHONE_
#include "PhoneFactory.hpp"
#include "phone.hpp"
#include <iostream>
using namespace std;
class ApplePhone : public Phone
{
public:
    void call()
    {

        cout << "ApplePhone call" << endl;
    }
    void message()
    {

        cout << "ApplePhone message" << endl;
    }
};
#endif
