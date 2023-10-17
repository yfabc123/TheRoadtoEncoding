#include <iostream>

using namespace std;

class A
{
public:
    void function(void)
    {
        cout << "A::function(), a = " << a << endl;
    }
    int a;
};

class B : virtual public A
{
public:
    int b;
    virtual void w() {}
};

class C : virtual public A
{
public:
    int c;
};

class D : public B, public C
{
public:
    int d;
    virtual void y() {}
};

int main()
{


    cout << "sizeof(A) : " << sizeof(A) << endl;
    cout << "sizeof(B) : " << sizeof(B) << endl;
    cout << "sizeof(C) : " << sizeof(C) << endl;
    cout << "sizeof(D) : " << sizeof(D) << endl;


    return 0;
}
