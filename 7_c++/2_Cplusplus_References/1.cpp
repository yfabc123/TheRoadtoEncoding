#include <iostream>
using namespace std;
void change(int &a)
{
    a = 3;
}
int main(void)
{
    int a = 1;
    cout << a << endl;
    change(a);
    cout << a << endl;
    return 0;
}
