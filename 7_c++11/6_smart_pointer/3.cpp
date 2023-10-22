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
        cout << "~String():" << m_ptr << endl;
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
    shared_ptr<String> ptr1(new String("yefan"));
    ptr1->show();
    cout << ptr1.use_count() << endl;

    return 0;
}
