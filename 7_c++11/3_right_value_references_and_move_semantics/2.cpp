#include <iostream>
#include <string.h>

using namespace std;

class String
{
public:
    String(const char *str = NULL);
    String(const String &obj);
    String(String &&a);
    void show(void);
    ~String();
    String &operator=(const String &other);

private:
    char *str;
};
String &String::operator=(const String &other)
{
    cout << "String &operator=(const String &other)" << endl;
    // a = a => a.operator=(a)
    if (this == &other)
    {
        return *this;
    }

    // a:"123"
    // b:"123456"
    // a = b
    if (this->str)
    {
        delete[] this->str;
    }

    if (other.str)
    {
        int len = strlen(other.str) + 1;
        this->str = new char[len];
        strcpy(this->str, other.str);
    }
    else
    {
        this->str = NULL;
    }

    return *this;
}

String::String(const String &obj)
{
    cout << "拷贝构造" << endl;
    if (obj.str)
    {
        int len = strlen(obj.str) + 1;
        this->str = new char[len];
        strcpy(this->str, obj.str);
    }
    else
    {
        this->str = NULL;
    }
}

String::String(const char *str)
{
    cout << "String(const char *str)" << endl;
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

String::~String()
{
    cout << "~String() : " << endl;
    if (str)
    {
        delete[] str;
    }
}
void String::show(void)
{
    //'\0' ->ascii 0
    for (char *p = str; p && *p; p++)
    {
        cout << *p << ",ascii : " << (int)*p << endl;
    }

    return;
}
String GetString(const char *pStr)
{
    String strTemp(pStr);
    return strTemp;
}
String::String(String &&a) : str(a.str)
{
    cout << "移动构造" << endl;
    //   this->str = a.str;
    a.str = nullptr;
}

int main()
{
    String s1("hello");
    String s2(move(GetString("world")));
    String s3(s2);//拷贝
    String s4(move(s2));//移动构造

    return 0;
}
