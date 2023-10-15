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
class B : public A
{
    void function()
    {
        c = 1;
        b = 1;
    }
};

int main()
{
    B b;
    return 0;
}