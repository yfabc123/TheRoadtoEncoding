#include <iostream>
#include <string.h>
using namespace std;
// 模拟智能指针
template <typename T>
class my_shared_ptr
{
public:
    /* 有参构造 */
    my_shared_ptr(T *obj = nullptr) : ptr(obj), count(new int(1))
    {
        cout << "有参构造" << endl;
        if (obj == nullptr)
        {
            *count = 0;
            ptr = nullptr;
        }
    }
    /* 拷贝构造 */

    my_shared_ptr(my_shared_ptr<T> &obj) : ptr(obj.ptr), count(obj.count)
    {
        cout << "拷贝构造" << endl;
        (*count)++;
    }
    /* 重载赋值符号 */
    my_shared_ptr<T> &operator=(my_shared_ptr<T> &obj)
    {
        cout << "调用重载=" << endl;
        if (this != &obj)
        {
            this->release();
            this->ptr = obj.ptr;
            this->count = obj.count;
            (*count)++;
        }
        return *this;
    }

    /* 重载 * */
    T &operator*()
    {
        return *ptr;
    }
    /* 重载 -> */ // 此处有点迷糊...比起*因为不是对自身操作 不知道返回值是什么..
    T *operator->()
    {
        return ptr;
    }
    /* 控制引用计数器 */
    void release()
    {
        (*count)--;
        if (*count == 0)
        {
            if (ptr != nullptr)
            {
                delete ptr;
                cout << "my_shared_ptr析构" << endl;
            }
            else
            {
                cout << "ptr 为空 my_shared_ptr不析构" << endl;
            }
            delete count;
        }
    }

    /* 析构 */
    ~my_shared_ptr()
    {
        release();
    }

    T *ptr;
    int *count;
};

// 模拟string类
class Test
{
public:
    Test(const char *str = nullptr)
    {
        size_t len = sizeof(str);
        this->str = new char[len];
        strcpy(this->str, str);
    }
    ~Test()
    {
        if (str != nullptr)
        {
            cout << "Test析构" << endl;

            delete[] str;
        }
        else
        {
            cout << "Test为空不用析构" << endl;
        }
    }
    void show()
    {
        cout << str << endl;
    }

private:
    char *str;
};
int main()
{
    my_shared_ptr<Test> test1(new Test("hello"));
    my_shared_ptr<Test> test2;
    cout << *(test2.count) << endl;
    test2 = test1;
    (*test2).show();
    test2->show();
    test2.operator->()->show();

    return 0;
}
