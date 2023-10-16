#include <iostream>
#include <string.h>
using namespace std;

class A
{
public:
    virtual void fun()
    {
        cout << "A" << endl;
    }

private:
    int a;
};

class B : public A
{
public:
    virtual void fun()
    {
        cout << "B" << endl;
    }

private:
    int a;
};
class C : public A
{
public:
    virtual void fun()
    {
        cout << "C" << endl;
    }

private:
    int a;
};
void test(A *a)
{
    a->fun();
}
int main()
{
    B b;
    C c;
    test(&b);
    test(&c);

    return 0;
}
