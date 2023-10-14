#include <iostream>
#include <string.h>
using namespace std;

class A;
class B
{
public:
    void change(A *obj);
    void show(A *obj);
};
class A
{
public:
    void fun()
    {
        cout << "测试" << endl;
    }

private:
    friend class B;
    int age;
};
void B::change(A *obj)
{
    obj->age = 10;
    cout << obj->age << endl;
}
void B::show(A *obj)
{
    cout << obj->age << endl;
}

int main()
{
    B b;

    A a;
    b.show(&a);
    b.change(&a);
    b.show(&a);

    return 0;
}
