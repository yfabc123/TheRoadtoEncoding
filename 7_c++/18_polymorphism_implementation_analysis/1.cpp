#include <iostream>
#include <string.h>
using namespace std;

class A
{
public:
    virtual void fun()
    {
        cout << 1 << endl;
    }
    virtual void fun1()
    {
        cout << 1 << endl;
    }

private:
    int a;
};

int main()
{
    A a;
    cout << sizeof(a) << endl;

    return 0;
}
