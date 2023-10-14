#include <iostream>
#include <string.h>
using namespace std;

class A
{
public:
    A()
    {
    }

    static void fun()
    {
        cout << "hello" << endl;
    }
    static const int age = 1;
};

int main()
{
    A one;

    cout << one.age << endl;
    A::fun();

    return 0;
}
