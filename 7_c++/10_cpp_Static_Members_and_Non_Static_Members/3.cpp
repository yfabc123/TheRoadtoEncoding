// 设计一个类，只允许这个类在外部创建一个对象，提示思路如下：

// 把 构造函数私有化，外面就无法创建对象了
// 在类内部提供一个静态函数创建对象
#include <iostream>
using namespace std;
class A
{
private:
    static A *a;
    string name;
    A(const string name = NULL)
    {
        cout << "A control" << endl;
        this->name = name;
    }

public:
    static A &init_param(const string &name);

    void showName()
    {
        cout << name << endl;
    }
};
A *A::a = NULL;
A &A::init_param(const string &name)
{
    if (!A::a)
    {
        A::a = new A(name);
    }
    return *(A::a);
}

int main()
{
    A a = A::init_param("A1");
    a.showName();
    cout << "=====================================" << endl;
    A a1 = A::init_param("A2");
    a1.showName();
    return 0;
}
