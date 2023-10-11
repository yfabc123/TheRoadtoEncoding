#include <iostream>
using namespace std;

int main(void)
{
    int data = 100;
    const char *str = "hello world";
    int a[] = {1, 2, 3, 4, 5};
    cout << data << endl;
    cout << str << endl;

    for (unsigned int i = 0; i < sizeof(a) / sizeof(int); i++)
    {
        cout << a[i] << endl;
    }

    return 0;
}
