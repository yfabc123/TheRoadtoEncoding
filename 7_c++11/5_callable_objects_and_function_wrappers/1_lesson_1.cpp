#include <iostream>

using namespace std;

// 普通函数
int add(int a, int b)
{
    return a + b;
}
// 函数对象类
class divide
{
public:
    int operator()(int denominator, int divisor)
    {
        return denominator / divisor;
    }
};

// 此类包含:类成员函数和类对象转成函数指针形式调用
class Calc
{
public:
    // 类对象转换成函数指针类型
    using ftype = int (*)(int, int); // 给类型重命名
    operator ftype()                 // ftype要和下面return 的类型一直
    {
        return ::add; // 返回一个函数类型
    };

    int add(int a, int b)
    {
        return (a + b);
    }
};

// 类成员函数指针:int (Calc::*func)(int a,int b)
int calc_function(Calc *obj, int (Calc::*func)(int a, int b),
                  int data1, int data2)
{
    return (obj->*func)(data1, data2);
}

int main()
{
    // lambda表达式
    auto mod = [](int a, int b)
    {
        return a % b;
    };

    cout << add(10, 20) << endl;
    cout << divide()(40, 20) << endl;
    cout << mod(10, 3) << endl;

    Calc object;
    cout << object(10, 20) << endl;
    cout << calc_function(&object, &Calc::add, 100, 200) << endl;

    return 0;
}
