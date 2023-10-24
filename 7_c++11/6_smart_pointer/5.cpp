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

    String *str = new String("hello");
    shared_ptr<String> s_ptr(str);
    weak_ptr<String> w_ptr = s_ptr;
    s_ptr->show();
    if (!w_ptr.expired())
    {
        shared_ptr<String> s_ptr1 = w_ptr.lock();
        cout << s_ptr.use_count() << endl;
    }
    cout << s_ptr.use_count() << endl;
    
    return 0;
}
