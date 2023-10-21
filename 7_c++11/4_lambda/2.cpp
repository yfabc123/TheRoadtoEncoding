#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    int b = 20;
    auto lambda = [a, b]
    {
        cout << "a:" << a << endl;
        cout << "b:" << b << endl;
        return (a + b);
    };

    cout << "lamda result:" << lambda() << endl;
    cout << "lamda result:" << lambda() << endl;
    return 0;
}