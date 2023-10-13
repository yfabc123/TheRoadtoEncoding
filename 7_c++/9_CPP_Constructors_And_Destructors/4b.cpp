#include <iostream>
#include <string.h>
using namespace std;

class String
{
public:
    String(const char *str = nullptr);
    void show(void);
    void myFree();

private:
    char *m_str = nullptr;
};
void String::myFree()
{
    cout << "调用myfree函数释放" << m_str << endl;
    // cout.clear();
    //  printf("调用析构函数释放%p\n", m_str);

    if (m_str)
    {
        delete[] m_str;
    }
}
String::String(const char *str)
{
    cout << "调用构造" << endl;
    if (str)
    {

        size_t len = strlen(str) + 1;
        this->m_str = new char[len];

        strcpy(this->m_str, str);

        show();
    }
    else
    {
        this->m_str = NULL;
        cout << "没有输入 无法调用show函数" << endl;
    }
}
void String::show(void)
{

    cout << "测试" << endl;
    for (size_t i = 0; i < strlen(m_str); i++)
    {

        cout << m_str[i] << " ascii:" << endl;
    }
}

int main()
{
    String a;
    a.myFree();
    cout << "------------------------" << endl;
    String *c = new String("abcd");
    c->myFree();
    cout << "------------------------" << endl;
    String b("yefan");
    b.myFree();

    return 0;
}