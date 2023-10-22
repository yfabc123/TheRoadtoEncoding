#include <iostream>
#include <string.h>
#include <memory>
using namespace std;
class String
{
public:
    String(const char *str)
    {
        cout << "String(const char *str)" << endl;
        if (str)
        {
            m_ptr = new char[strlen(str) + 1];
            strcpy(m_ptr, str);
        }
        else
        {
            m_ptr = (char *)str;
        }
    }

    ~String()
    {
        cout << "~String()" << endl;
        if (m_ptr)
        {
            delete[] m_ptr;
        }
    }

    void show(void) const
    {
        cout << m_ptr << endl;
    }

private:
    char *m_ptr;
};

int main(void)
{
    // String *obj = new String("hello world");
    // obj->show();
    // delete obj;
    unique_ptr<String> ptr(new String("hello"));
    ptr->show();
    unique_ptr<String> other(new String("world"));
    ptr = move(other);
    other->show();
    // ptr->show();
    return 0;
}
