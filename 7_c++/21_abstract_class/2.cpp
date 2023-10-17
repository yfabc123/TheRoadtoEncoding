#include <iostream>

using namespace std;

class A
{
public:
    virtual void function(void) = 0;
};

class B : public A
{
public:
    void show(void)
    {
        cout << "B::show()" << endl;
    }
    virtual void function(void)
    {
        cout << "实现父类的抽象函数" << endl;
    }
};

int main(void)
{
    B obj;
    obj.show();
    return 0;
}
