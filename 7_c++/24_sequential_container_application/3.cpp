#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    vector<string> v;
    v.push_back("i");
    v.push_back("love");
    v.push_back("linux");
    vector<string>::iterator itr;
    for (itr = v.begin(); itr < v.end(); itr++)
    {
        cout << *itr << endl;
    }

    return 0;
}
