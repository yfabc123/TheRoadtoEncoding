#include <iostream>
using namespace std;

class A
{
public:
    A(int a)
    {
        age = a;
        cout << "构造" << endl;
    }
    A(const A &a)
    {
        cout << "拷贝" << endl;
    }
    int age;
};
int main(int argc, char const *argv[])
{
    A a(1);
    A b = A(3);

    return 0;
}
