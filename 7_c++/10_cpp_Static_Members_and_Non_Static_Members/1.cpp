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
    static int memoryUsed;

private:
    char *str = nullptr;
};
int String::memoryUsed = 0;
// 析构
String::~String()
{
    if (str)
    {
        cout << "析构" << endl;
        int len = strlen(str) + 1;
        memoryUsed -= len;
        delete[] str;
    }
}
// 普通构造
String::String(const char *str)
{
    cout << "普通构造" << endl;

    if (str)
    {
        size_t len = strlen(str) + 1;
        this->str = new char[len];
        strcpy(this->str, str);
        memoryUsed += len;
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
        memoryUsed += len;
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

String fun(String obj)
{
    String temp = obj;
    return temp;
}
int main()
{
    String a("hello");
    cout << String::memoryUsed << endl;
    fun(a);
    cout << String::memoryUsed << endl;

    String b = a;
    cout << String::memoryUsed << endl;

    return 0;
}