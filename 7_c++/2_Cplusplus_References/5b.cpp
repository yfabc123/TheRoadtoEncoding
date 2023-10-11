#include <iostream>
using namespace std;

void my_swap(int &a, int &b)
{
    a ^= b;
    b ^= a;
    a ^= b;
}

int main()
{
    int a = 1, b = 2;

    cout << "a:" << a << " b:" << b << endl;
    my_swap(a, b);
    cout << "a:" << a << " b:" << b << endl;
    return 0;
}
