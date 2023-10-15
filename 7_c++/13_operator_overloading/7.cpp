#include <iostream>
#include <string.h>
#include <ostream>
using namespace std;
class String
{
public:
    String(const char *str = NULL);
    String(const String &other); // 拷贝构造
    ~String();
    friend String operator+(const String &op1, const String &op2);
    void show();

    String operator+(const String &op2);
    String &operator++();   // 前置自增运算符重载
    String operator++(int); // 后置自增运算符重载
    String &operator=(const String &op2);
    String &operator<<(const char *op);

private:
    char *str;
};

String &String::operator<<(const char *op)
{
    if (strlen(op) == 0)
    {
        return *this;
    }

    if (this->str)
    {
        cout << "原字符串不为空" << endl;
        size_t len = strlen(op) + strlen(this->str) + 1;
        char *temp = new char[len];
        strcpy(temp, this->str);
        delete[] this->str;
        strcat(temp, op);
        this->str = temp;
        this->str[len - 1] = '\0';
    }
    else
    {
        cout << "原字符串为空" << endl;

        size_t len = strlen(op) + 1;
        this->str = new char[len];
        strcpy(this->str, op);
        this->str[len - 1] = '\0';
    }
    return *this;
}

String &String::operator=(const String &op2)
{
    if (this == &op2)
    {
        cout << "两对象相同无需赋值" << endl;
        return *this;
    }
    if (this->str)
    {
        delete[] this->str;
    }
    if (op2.str)
    {
        size_t len = strlen(op2.str) + 1;
        this->str = new char[len];
        strcpy(this->str, op2.str);
    }
    else
    {
        this->str = NULL;
    }
    return *this;
}

String &String::operator++()
{
    cout << "前置++" << endl;
    // 逻辑:所有字符+1 在返回
    if (this->str == NULL)
    {
        return *this;
    }
    size_t len = strlen(this->str);

    for (size_t i = 0; i < len; i++)
    {
        this->str[i] = this->str[i] + 1;
    }
    return *this;
}
String String::operator++(int)
{
    cout << "后置++" << endl;

    // 逻辑:先返回后+1
    String old(*this);
    if (this->str == NULL)
    {
        return *this;
    }
    size_t len = strlen(this->str);

    for (size_t i = 0; i < len; i++)
    {
        this->str[i] = this->str[i] + 1;
    }
    return old;
}

String::String(const char *str)
{
    cout << "普通构造" << endl;
    if (str)
    {
        int len = strlen(str) + 1;
        this->str = new char[len];
        strcpy(this->str, str);
    }
    else
    {
        this->str = NULL;
    }
}

String::String(const String &other)
{
    cout << "拷贝构造" << endl;

    if (other.str)
    {
        int len = strlen(other.str);
        this->str = new char[len];
        strcpy(this->str, other.str);
    }
    else
    {

        this->str = NULL;
    }
}
String::~String()
{
    cout << "析构" << endl;

    if (this->str)
    {
        delete[] this->str;
    }
}
void String::show()
{
    if (this->str)
    {
        for (size_t i = 0; i < strlen(this->str); i++)
        {
            cout << str[i] << endl;
        }
    }
}

String String::operator+(const String &op2)
{
    cout << "成员+重载函数" << endl;

    String temp;

    if (op2.str == NULL)
    {
        cout << "有字符串为空 无法拼接" << endl;
        return temp;
    }

    size_t len = strlen(this->str) + strlen(op2.str) + 1;
    temp.str = new char[len];
    strcpy(temp.str, this->str);
    strcat(temp.str, op2.str);
    return temp;
}

String operator+(const String &op1, const String &op2)
{
    cout << "非成员+重载函数" << endl;
    String temp;

    if (op1.str == NULL || op2.str == NULL)
    {
        cout << "有字符串为空 无法拼接" << endl;
        return temp;
    }

    size_t len = strlen(op1.str) + strlen(op2.str) + 1;
    temp.str = new char[len];
    strcpy(temp.str, op1.str);
    strcat(temp.str, op2.str);
    return temp;
}
int main()
{
    String str1;

    str1.show();

    return 0;
}