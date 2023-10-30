#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a = "white";
    fprintf(stderr, "%s", a.c_str());
    return 0;
}
