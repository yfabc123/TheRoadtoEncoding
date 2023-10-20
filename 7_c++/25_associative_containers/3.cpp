#include <iostream>
#include <map>
using namespace std;

int main()
{
    multimap<string, int> m;
    m.insert(pair<string, int>("hello", 1));
    m.insert(pair<string, int>("hello", 2));
    m.insert(pair<string, int>("hi", 3));

    multimap<string, int>::iterator i = m.find("1234"); // find只能找一个数据
    if (i == m.end())
    {
        cout << "没找到" << endl;
    }
    else
    {
        cout << i->first << " " << i->second << endl;
    }
    cout << "==================" << endl;
    pair<multimap<string, int>::iterator, multimap<string, int>::iterator>
        p = m.equal_range("hi1");
    if (p.first ==m.end())
    {
        cout << "没找到" << endl;
    }
    else
    {
        for (multimap<string, int>::iterator itr = p.first; itr != p.second; itr++)
        {
            cout << itr->first << " " << itr->second << endl;
        }
    }

    cout << "==================" << endl;

    for (multimap<string, int>::iterator itr = m.begin(); itr != m.end(); itr++)
    {
        cout << itr->first << " " << itr->second << endl;
    }
    return 0;
}