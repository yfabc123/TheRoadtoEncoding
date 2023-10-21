#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    int b = 20;
    auto result = [ a, b ](int c, int d) mutable throw(int)->int
    {
        if (d == 0)
        {
            throw int(1);
        }
        a++;
        b++;
        cout << "a:" << a << endl;
        cout << "b:" << b << endl;
        return (a + b + c / d);
    };
    try
    {
        result(2, 0);
    }
    catch (int error)
    {
        cout << "error:" << error << endl;
    }
    try
    {
        cout << "lamda result:" << result(12, 4) << endl;
    }
    catch (int error)
    {
        cout << "error:" << error << endl;
    }
    return 0;
}