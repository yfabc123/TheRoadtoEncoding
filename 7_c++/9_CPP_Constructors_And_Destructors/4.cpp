#include <iostream>
#include <string.h>
using namespace std;

class String
{
public:
    String(const char *str = nullptr);
    void show(void);
    ~String();

private:
    char *str = nullptr;
};

String::~String()
{

    cout << "调用析构函数释放" << str << endl;
    // printf("调用析构函数释放%p\n", str);

    if (str)
    {
        delete[] str;
    }
}
String::String(const char *str)
{
    cout << "调用构造" << endl;
    if (str)
    {
        size_t len = strlen(str) + 1;
        this->str = new char[len];
        strcpy(this->str, str);
        show();
    }
    else
    {
        this->str = NULL;
        cout << "没有输入 无法调用show函数" << endl;
    }
}
void String::show(void)
{

    for (size_t i = 0; i < strlen(str); i++)
    {

        cout << str[i] << " ascii:" << endl;
    }
}

int main()
{
    String a;
    cout << "------------------------" << endl;
    String *c = new String("abcd");
    delete c;
    cout << "------------------------" << endl;
    String b("yefan");

    return 0;
}