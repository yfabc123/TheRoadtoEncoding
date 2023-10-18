#include <iostream>
#include <deque>
#include <vector>
#include <list>
using namespace std;
int main()
{

    list<string> l;
    l.push_back("ab");
    l.push_back("cd");
    l.push_front("ef");
    l.push_front("gh");
    for (list<string>::iterator it = l.begin(); it != l.end(); it++)
    {
        cout << *it << endl;
    }

    return 0;
}
