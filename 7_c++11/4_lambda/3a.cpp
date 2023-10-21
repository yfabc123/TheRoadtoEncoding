#include <iostream>
using namespace std;
int main()
{
    int a = 1;
    int b = 2;
    auto lambda = [&]
    {
        int result = a + b;
        return result;
    };
    auto lambda2 = [=]
    {
        int result = a + b;
        return result;
    };
    a = 2;
    b = 3;
    int c = lambda();
    int d = lambda2();
    cout << c << endl;
    cout << d << endl;

    return 0;
}
