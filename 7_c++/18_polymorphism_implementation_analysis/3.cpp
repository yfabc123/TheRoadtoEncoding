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
    static int b;
};

int A::b = 0;

class B
{
public:
    void function2(void)
    {
        cout << "B::function2" << endl;
    }

    virtual void function(void)
    {
        cout << "B::function" << endl;
    }

private:
    int b;
};

class C : public A, public B
{
public:
    virtual void function1(void)
    {
        cout << "C:function1" << endl;
    }

    virtual void function2(void)
    {
        cout << "C:function2" << endl;
    }
    virtual void function3(void)
    {
        cout << "C:function2" << endl;
    }

private:
    int c;
};

void function1(A &obj)
{
    obj.function1();
}
void function2(B &obj)
{
    obj.function2();
}
int main(void)
{
    C obj;
    cout << "sizeof(obj) : " << sizeof(obj) << endl;

    function1(obj);
    function2(obj);

    return 0;
}
