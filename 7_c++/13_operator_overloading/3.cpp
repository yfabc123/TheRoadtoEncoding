#include <iostream>
#include <string.h>
using namespace std;

class String
{
private:
    char *str;

public:
    String(const char *str = NULL);
    ~String();
    void show();
    char &operator[](size_t num);
};
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
// 实现修改字符串
char &String::operator[](size_t num)
{
    if (num > strlen(this->str) - 1)
    {
        cout << "下标越界" << endl;
        // return '\0';
        exit(EXIT_FAILURE);
    }
    return *(this->str + num);
}
String::String(const char *str)
{
    cout << "普通构造" << endl;
    if (str)
    {
        size_t len = strlen(str) + 1;
        this->str = new char[len];
        strcpy(this->str, str);
        this->str[len] = '\0';
    }
    else
    {
        this->str = NULL;
    }
}

String::~String()
{
    if (this->str)
    {
        delete[] this->str;
    }
}

int main()
{
    String str("hello");

    str[0] = 'w';
    str[1] = 'x';

    str.show();

    return 0;
}
