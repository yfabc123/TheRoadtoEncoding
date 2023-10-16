#include <iostream>

using namespace std;

class A
{
public:
    virtual void function1(void)
    {
        cout << "A::function1" << endl;
    }

private:
    int a;
    int b;
};

class B : public A
{

public:
    virtual void function2(void)
    {
        cout << "A::function1" << endl;
    }

private:
    int c;
    int d;
};
int main()
{
    A a;
    B b;
    cout << sizeof(a) << endl;
    cout << sizeof(b) << endl;

    return 0;
}
