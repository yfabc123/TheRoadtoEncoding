#include <iostream>
using namespace std;
int main()
{
    int *p = new int[3];
    for (int i = 0; i < 3; i++)
    {
        *p = i;
        p++;
    }
    for (int i = 0; i < 3; i++)
    {
        cout << *p << endl;
        p++;
    }
    delete[] p;

    return 0;
}
