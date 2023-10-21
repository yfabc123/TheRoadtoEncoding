#include <functional>
#include <iostream>
using namespace std;
// 普通函数形式
int add(int a, int b)
{
    return a + b;
}

// 类对象调用形式
class Add
{
public:
    int operator()(int a, int b)
    {
        return a + b;
    }
};
// 类成员函数调用 把类对象转成函数指针形式调用
class Calc
{
public:
    using ftype = int (*)(int a, int b);
    operator ftype()
    {
        return ::add;
    }
    int add(int a, int b)
    {
        return a + b;
    }
    // int sub(int a, int b)
    // {
    //     return a - b;
    // }
};
// 类成员函数指针形式
int calc(Calc *obj, int (Calc::*fun)(int a, int b), int a, int b)
{
    return (obj->*fun)(a, b);
}

int std_function(function<int(int, int)> func_ojb, int a, int b)
{
    return func_ojb(a, b);
}
int main()
{
    cout << add(1, 2) << endl;

    Add a;
    cout << Add()(1, 2) << endl;

    Calc b;
    cout << b.add(1, 2) << endl;

    cout << b(1, 2) << endl;

    cout << calc(&b, &Calc::add, 1, 2) << endl;

    auto lambda = [](int a, int b)
    {
        return a + b;
    };
    cout << lambda(1, 2) << endl;
    cout << "---------------------------" << endl;
    function<int(int, int)> fun1 = add;
    function<int(int, int)> fun2 = Add();
    function<int(int, int)> fun3 = b;
    function<int(int, int)> fun4 = lambda;
    cout << fun4(1, 2) << endl;

    return 0;
}
