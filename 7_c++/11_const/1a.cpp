#include <iostream>
#include <string.h>
using namespace std;
class Test
{

public:
    Test(int a, int bb) : b(bb)
    {
        this->a = a;
    }
    void show()
    {
        cout << a << endl;
        cout << b << endl;
    }
    void function(void) const;
    void static const fun();

private:
    int a;
    static int b;
};
int Test::b = 1;
void Test::function() const
{
    //  a++;
}
int main()
{

    Test a(1, 4);
    a.show();
    a.function();
    a.show();
    const Test other(1, 2);
    other.function();
    //  other.show();

    return 0;
}