#include <iostream>
using namespace std;

int calc(int a, int b=1, int c=1)
{
    return (a + b + c);
}

int main(void)
{
    cout << calc(100, 200, 1) << endl;
    return 0;
}
