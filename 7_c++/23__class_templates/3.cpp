#include <iostream>

using namespace std;

template <typename T, int m, int n>
int function(const T (&ra1)[m], const T (&ra2)[n])
{
    cout << m << "," << n << endl;
    return 0;
}
int main(void)
{
    int a[10];
    int b[20];
    function(a, b);
    function<int, 10, 20>(a, b);

    return 0;
}
