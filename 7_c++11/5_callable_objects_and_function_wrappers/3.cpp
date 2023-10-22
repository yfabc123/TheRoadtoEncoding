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
    // lambda表达式
    auto mod = [](int a, int b)
    { return a % b; };

    auto a = bind(add, 10, 20);
    cout << a() << endl;

    auto c = bind(mod, 10, 20);
    cout << c() << endl;

    Calc object;
    auto d = bind(&Calc::add, &object, std::placeholders::_1, std::placeholders::_2);
    cout << d(4, 4) << endl;
    cout << std_function(bind(&Calc::add, &object, std::placeholders::_1, std::placeholders::_2), 3, 4) << endl;
    cout << std_function(d, 1, 2) << endl;

    return 0;
}
