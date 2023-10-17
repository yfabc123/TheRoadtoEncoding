#include <iostream>
using namespace std;

class A
{
public:
    virtual void fun()
    {
        cout << "A:fun()" << endl;
    }
    void fun(int a)
    {
        cout << "A:fun(int a)" << a << endl;
    }
};

class B : public A
{
public:
    void fun()
    {
        cout << "B:fun()" << endl;
    }
    void fun(int a)
    {
        cout << "B:fun(int a)" << a << endl;
    }
};
int main()
{
    A a;
    B b;
    A *c = &b;
    cout << "重载:" << endl;
    a.fun();
    a.fun(1);
    cout << "多态覆盖:" << endl;
    c->fun();
    cout << "隐藏:" << endl;
    ((B *)c)->fun(); // 强转调用子类
    c->fun(3);       // 调用父类

    return 0;
}
