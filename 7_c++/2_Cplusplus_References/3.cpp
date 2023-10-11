#include <iostream>
using namespace std;
string &function(void)
{
    static string str = "hello world";
    return str;
}
int main(void)
{
    string str = function();
    cout << str << endl;
    return 0;
}
