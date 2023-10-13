#include <iostream>
#include <string.h>
using namespace std;

class Test
{
public:
    Test(int size) // 构造
    {
        cout << "Test(int size)" << endl;
        data = new int[size];
    }

    Test(const Test &obj) // 拷贝构造
    {
        cout << "Test(const Test obj)" << endl;
        //   *this = obj;                                         // 把参数对象地址直接复制给调用对象 是浅拷贝
        size_t len = sizeof(obj.data) / sizeof(obj.data[0]); // 数组长度
        this->data = new int[len];
        // 数组拷贝:
        for (size_t i = 0; i < len; i++)
        {
            data[i] = obj.data[i];
        }

        // Test *test = new Test();
    }

    ~Test(void) // 析构
    {
        cout << "~Test()" << endl;
        delete[] data; // 需要修改为delete[] data;
    }

private:
    int *data;
};

Test function(Test obj)// 调用拷贝构造1
{
    Test tmp = obj;  // 调用拷贝构造2

    return tmp; // 调用拷贝构造3
} 

int main(void)
{
    Test obj1(3);
    Test obj2 = function(obj1); // 调用拷贝构造4
    //一共五次构造 自然对应5次析构
    return 0;
}
