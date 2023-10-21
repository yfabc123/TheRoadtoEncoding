#include <iostream>
using namespace std;
int sum(int a)
{
    return a;
}
class A
{
public:
    using fun = int (*)(int); // 函数指针
    operator fun()            // fun类型要和下面return 保持一致
    {
        return ::sum; // 返回全局函数 sum
    }

private:
    int a;
};
int add(int a, int b)
{
    return a + b;
}
int main()
{
    A obj;
    cout << obj(4) << endl;

    // 类的函数指针
    using fptr = int (*)(int a, int b);
    fptr f1 = add;
    cout << f1(2, 2) << endl;
}