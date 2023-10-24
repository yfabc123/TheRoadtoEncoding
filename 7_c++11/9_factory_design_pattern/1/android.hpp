#ifndef _ANDROID_H__
#define _ANDROID_H__
#include "phone.hpp"
#include <iostream>
using namespace std;
class Android : public Phone
{
public:
    void call()
    {
        cout << "Android call" << endl;
    }
    void message()
    {
        cout << "Android message" << endl;
    }
};

#endif
