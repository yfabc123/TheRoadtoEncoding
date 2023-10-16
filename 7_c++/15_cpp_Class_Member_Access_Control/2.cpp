#include <iostream>
using namespace std;

class A
{
private:
    int a;

public:
    int b;

protected:
    int c;
    void fun()
    {
        a--;
    }
};
class B : private A
{
    void function()
    {
        c = 1;
        b = 1;
      //  a=4;
    }
};

int main()
{
    B b;
    //b.b = 1;

    return 0;
}