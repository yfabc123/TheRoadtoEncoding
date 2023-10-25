#ifndef _ANDROID_PHONE_
#define _ANDROID_PHONE_
#include "PhoneFactory.hpp"
#include "phone.hpp"
#include <iostream>
using namespace std;
class AndroidPhone : public Phone
{
public:
    void call()
    {

        cout << "AndroidPhone call" << endl;
    }
    void message()
    {

        cout << "AndroidPhone message" << endl;
    }
};
#endif
