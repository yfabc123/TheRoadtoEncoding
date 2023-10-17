#include <iostream>

using namespace std;

template <typename T>
void my_swap(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 1;
    int b = 2;
    my_swap<int>(a, b);
    cout << a << " " << b << endl;

    string c = "123";
    string d = "abc";
    my_swap(c, d);
    cout << c << " " << d << endl;
    return 0;
}
