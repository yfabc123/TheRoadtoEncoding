#include <iostream>
#include <set>
using namespace std;

int main()
{

    set<int> s;
    s.insert(1);
    s.insert(1);
    s.insert(2);
    s.insert(3);
    for (set<int>::iterator itr = s.begin(); itr != s.end(); itr++)
    {
        cout << *itr << endl;
    }
    multiset<int> s1;
    s1.insert(1);
    s1.insert(1);
    s1.insert(2);
    s1.insert(3);
    for (multiset<int>::iterator itr = s1.begin(); itr != s1.end(); itr++)
    {
        cout << *itr << endl;
    }

    return 0;
}