#include <iostream>
#include <string.h>
using namespace std;
class A
{
public:
    A()
    {
        cout << "A()" << endl;
        aptr = new char[100];
        strcpy(aptr, "ab");
    }

  virtual  ~A()
    {
        cout << "~A()" << endl;
        delete[] aptr;
    }

    char *aptr;
};

class B : public A
{
public:
    B()
    {
        cout << "B()" << endl;
        bptr = new char[100];
        strcpy(bptr, "cd");
    }

    ~B()
    {
        cout << "~B()" << endl;
        delete[] bptr;
    }

    char *bptr;
};

void free_function(A *p)
{
    delete p;
}
int main(void)
{
    A *aobject = new A;
    free_function(aobject); // 触发析构
    cout << "--------------------------" << endl;
    B *bobject = new B;
    free_function(bobject);
    return 0;
}
