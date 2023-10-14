#include <iostream>
#include <string.h>
using namespace std;

class Test;
class A
{
public:
    void fun1(Test &obj);
};

class Test
{
public:
    Test(int a, int b) : a(a), b(b) {}
    friend void fun(Test &obj);
    //  friend void A::fun1(Test &obj);
    friend A;

private:
    int a;
    int b;
};

// 友元函数
void fun(Test &obj)
{
    cout << obj.a << endl;
    cout << obj.b << endl;
}
void A::fun1(Test &obj)
{
    cout << obj.a << endl;
    cout << obj.b << endl;
}

int main(void)
{
    Test test(1, 3);
    A a;
    a.fun1(test);
    fun(test);

    return 0;
}
