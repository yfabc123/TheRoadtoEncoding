#include <iostream>
#include <string.h>
using namespace std;

class String
{
public:
    String(const char *str = nullptr);
    void show(void);
    ~String();
    String(const String &obj);

private:
    char *str = nullptr;
};
// 析构
String::~String()
{
    if (str)
    {
        cout << "调用析构函数释放堆空间内存" << endl;
        delete[] str;
    }
}
// 构造
String::String(const char *str)
{
    if (str)
    {
        size_t len = strlen(str) + 1;
        this->str = new char[len];
        strcpy(this->str, str);
    }
    else
    {
        this->str = NULL;
    }
}

// 拷贝构造
String::String(const String &obj)
{
    cout << "拷贝构造" << endl;
    if (obj.str)
    {
        int len = strlen(obj.str) + 1;
        this->str = new char[len];
        strcpy(this->str, obj.str);
    }
}
void String::show(void)
{
    if (this->str)
    {
        for (size_t i = 0; i < strlen(str); i++)
        {
            cout << str[i] << " ascii:" << (int)str[i] << endl;
        }
    }
    else
    {
        cout << "空指针无法调用show" << endl;
    }
}
void fun(String *obj)
{
    obj->show();
}
String f()
{
    String obj("f()");
    return obj;
}
int main()
{
    String a("hello");
    a.show();
    // String b = String(a);
    // b.show();
    // fun(&a);
    String test = f();

#ifdef MY_MACRO_NAME
    String a("hello");
    a.show();
    cout << "------------------------" << endl;
    String *b = new String("world");
    b->show();
    b->fun(a);
    //  b->show();

    // delete b;
    cout << "------------------------" << endl;
    // String c = String(*b);
    String c = String(a);
#endif
    return 0;
}