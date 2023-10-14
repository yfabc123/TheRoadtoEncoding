#include <iostream>
#include <string.h>
using namespace std;

class String
{
public:
    String(const char *str = nullptr);
    void show(void);
    void myFree();
    ~String();

    // private:
    char *str = nullptr;
    char *a;
};
String::~String()
{

    cout << "析构" << endl;
    if (str)
    {
        delete[] str;
    }
}
void String::myFree()
{
    // cout << "myfree" << str << endl;
    // cout.clear();
    //  printf("调用析构函数释放%p\n", str);
}
String::String(const char *str)
{
    cout << "普通构造" << endl;
    if (str)
    {

        size_t len = strlen(str) + 1;
        this->str = new char[len];
        this->a = new char[len];
        strcpy(this->str, str);

        //  show();
    }
    else
    {
        this->str = NULL;
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
    String a("1");
    cout << "------------------------" << endl;
    String *c = new String("2");
    delete c;
    cout << "------------------------" << endl;
    String b("3");
    String d("4");
    return 0;
}