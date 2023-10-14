#include <iostream>

using namespace std;

class Test
{
public:
    Test(int a) : a(a) {} // 修改点1 b是静态变量 不能用参数列表方式初始化
    // Test(int a, int b)
    // {
    //     this->a = a;
    //     this->b = b;
    // }
    void function(void)
    {
        a++;
        b++;
    }

    static void static_function(void)
    {
        // a++;//修改点2 静态不能调用非静态变量a
        b++;
    }

    void show(void)
    {
        cout << "a : " << a << endl;
        cout << "b : " << b << endl;
    }

    static void static_show(Test &a)
    {

        a.show(); // 修改点3 没啥思路....
    }

private:
    int a;
    static int b;
};
int Test::b = 0;
int main(void)
{
    Test obj1(1);
    Test obj2(4);
    // Test::function(); //修改点4 静态函数不能调用非静态
    Test::static_function();
    obj1.show();
    obj2.show();
    Test::static_show(obj1);

    return 0;
}
