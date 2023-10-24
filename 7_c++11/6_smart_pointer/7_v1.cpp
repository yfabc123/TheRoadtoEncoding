#include <iostream>
#include <string.h>
using namespace std;
// 模拟智能指针
template <typename T>
class my_shared_ptr
{
public:
    /* 有参构造 */
    my_shared_ptr(T *obj) : ptr(obj), count(new int[1])
    {
        *count = 1;
    }
    /* 拷贝构造 */

    my_shared_ptr(my_shared_ptr<T> &obj) : ptr(obj.ptr), count(obj.count)
    {
        (*count)++;
    }
    /* 重载赋值符号 */
    my_shared_ptr<T> &operator=(my_shared_ptr<T> &obj)
    {
        if (&obj == this)
        {
            return *this;
        }
        else
        {
            this.release();
            this->ptr = obj.ptr;
            this->count = obj.count;
        }
        return *this;
    }
    /* 重载 * */
    T &operator*()
    {
        return *this->ptr;
    }
    /* 重载 -> */ // 此处有点迷糊... 到底难在哪里?因为不是对自身操作 不知道返回值是什么

    /* 控制引用计数器 */
    void release()
    {
        (*count)--;
        if (*count == 0)
        {
            if (ptr)
            {
                delete ptr;
            }
            delete count;
        }
    }

    /* 析构 */
    ~my_shared_ptr()
    {
        cout << "~my_shared_ptr()" << endl;
        release();
    }

    T *ptr;
    int *count;
};

// 模拟string类
class Test
{
public:
    Test(const char *str)
    {
        size_t len = sizeof(str);
        this->str = new char[len];
        strcpy(this->str, str);
    }
    ~Test()
    {
        if (str)
        {
            delete[] str;
        }
    }
    void show()
    {
        for (size_t i = 0; i < strlen(str); i++)
        {
            cout << str[i] << endl;
        }
    }

private:
    char *str;
};

int main()
{
    Test t("hello");
    // t.show();
    my_shared_ptr<Test> ptr(new Test("hello"));
    cout << *(ptr.count) << endl;

    my_shared_ptr<Test> ptr2(ptr);
    cout << *ptr.count << endl;
   // ptr->show();
    return 0;
}
