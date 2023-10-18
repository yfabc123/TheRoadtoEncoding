#include <iostream>
#include <deque>
#include <vector>
#include <list>
using namespace std;
int main(int argc, char const *argv[])
{

    deque<string> d;
    d.push_back("hello");
    d.push_back("world");
    d.push_front("i");
    d.push_front("love");
    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << endl;
    }
    d.pop_back();
    cout << "=================================" << endl;
    deque<string>::iterator itr;
    for (itr = d.begin(); itr < d.end(); itr++)
    {
        cout << *itr << endl;
    }
    return 0;
}
