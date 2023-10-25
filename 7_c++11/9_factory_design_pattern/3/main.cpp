#include "AndroidFactory.hpp"
#include "AppleFactory.hpp"
#include <iostream>

using namespace std;
int main()
{
    AndroidFactory *android_factory = new AndroidFactory();
    AndroidPhone *android_phone = android_factory->getPhone();
    AndroidShell *android_shell = android_factory->getShell();
    android_phone->call();
    android_phone->message();
    android_shell->protect();
    cout << "===========================" << endl;
    AppleFactory *apple_factory = new AppleFactory();
    ApplePhone *apple_phone = apple_factory->getPhone();
    AppleShell *apple_shell = apple_factory->getShell();
    apple_phone->call();
    apple_phone->message();
    apple_shell->protect();

    return 0;
}
