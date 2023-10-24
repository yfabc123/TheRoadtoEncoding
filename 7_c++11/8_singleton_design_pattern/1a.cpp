#include <iostream>
using namespace std;

class A
{
public:
    static A *get()
    {
        cout << "获取唯一对象方式" << endl;
        return a;
    }
    void show()
    {
        cout << "show()" << endl;
    }

private:
    A()
    {
        cout << "私有构造" << endl;
    }
    static A *a;
};
A *A::a = new A;
int main()
{
    A *one = A::get();
    one->show();

    return 0;
}
