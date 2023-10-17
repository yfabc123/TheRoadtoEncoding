#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int c;
    c = a;
    a = b;
    b = c;
}

int main()
{
    int a = 1;
    int b = 2;
    cout << a << " " << b << endl;
    swap(a, b);
    cout << a << " " << b << endl;   
    int &p = a;
    int c = p;
    cout << c << endl;
    return 0;
}
