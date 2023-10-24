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

    shared_ptr<String> pt1(str);
    shared_ptr<String> pt2(str);
    cout << pt1.use_count() << endl;
    cout << pt2.use_count() << endl;
    pt1->show();

    return 0;
}
