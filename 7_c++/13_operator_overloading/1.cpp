#include <iostream>
#include <string.h>
using namespace std;
class String
{
public:
    String(const char *str = NULL);
    String(const String &other); // 拷贝构造
    ~String();
    friend String operator+(const String &op1, const String &op2);
    void show();

private:
    char *str;
};
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

String operator+(const String &op1, const String &op2)
{
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
    String str1("hello");
    String str2("world");
    String str3 = str1 + str2;

    str3.show();

    return 0;
}