#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    const char *a = "";
    if (a)
    {
        cout << "非空" << endl;
        cout << strlen(a) << endl;
    }
    else
    {
        cout << "空" << endl;
    }
    return 0;
}
