#include <iostream>
#include <string.h>

using namespace std;

class String
{
public:
    String(const char *str = NULL);
    ~String();
    void show(void);

private:
    char *str;
};

String::String(const char *str)
{
    cout << "构造" << endl;
    if (str == NULL)
    {
        this->str = NULL;
    }
    else
    {
        int len = strlen(str) + 1;
        this->str = new char[len];
        strcpy(this->str, str);
    }
}

void String::show(void)
{
    for (char *p = str; p && *p; p++)
    {
        cout << *p << ",ascii code:" << (int)*p << endl;
    }
}

String::~String()
{
    cout << "析构" << endl;
    if (str)
    {
        delete[] str;
    }
}

int main()
{
    String str1("abc");
    String str2 = str1;
    str1.show();
    cout << "-------------------------------" << endl;
    str2.show();
    return 0;
}
