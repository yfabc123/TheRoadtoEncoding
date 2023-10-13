#include <iostream>
#include <string.h>
using namespace std;

class String
{
public:
    String(const char *str = NULL);
    void show(void);

private:
    char *str;
};

String::String(const char *str)
{
    cout << "调用构造" << endl;
    if (str)
    {
        size_t len = strlen(str);
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
    String b("yefan");
}