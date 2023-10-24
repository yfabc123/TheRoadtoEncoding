#include "factory.hpp"
#include <iostream>
using namespace std;

int main()
{
    Phone *Phone1 = Factory::get("apple");
    Phone1->call();
    Phone1->message();

    Phone *phone2 = Factory::get("android");
    phone2->call();
    phone2->message();
    return 0;
}
