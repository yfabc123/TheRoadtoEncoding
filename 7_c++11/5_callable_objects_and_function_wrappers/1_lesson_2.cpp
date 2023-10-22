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
    void sub(int a, int b)
    {
        a - b;
    }
};
// 类成员函数指针形式
// int calc(Calc *obj, int (Calc::*fun)(int a, int b), int a, int b)
// {
//     return (obj->*fun)(a, b);
// }

int calc(Calc *obj, int (Calc::*fun_name)(int, int), int a, int b)
{
    return (obj->*fun_name)(a, b);
}
int main()
{
    cout << "直接调用函数形式:" << add(1, 2) << endl;
    cout << "重载()形式:" << Add()(1, 2) << endl;
    Calc b;
    cout << "类对象调用形式:" << b.add(1, 2) << endl;
    cout << "把类对象转成函数指针的形式" << b(1, 2) << endl;
    cout << "类成员函数指针形式:" << calc(&b, &Calc::add, 2, 2) << endl;
    auto lambda = [](int a, int b)
    {
        return a + b;
    };
    cout << "lambda形式:" << lambda(1, 2) << endl;
    return 0;
}
