#include <iostream>
using namespace std;

class A
{

public:
    static A *get()
    {
        if (a == nullptr)
        {
            a = new A();
        }
        return a;
    }

private:
    A()
    {
        cout << "唯一一次构造" << endl;
    }
    static A *a;
};
A *A::a = nullptr;

int main()
{
    A *one = A::get();
    cout << one << endl;
    A *two = A::get();
    cout << two << endl;

    return 0;
}
