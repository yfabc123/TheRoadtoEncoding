#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> m;
    m["hello"] = 0; // 插入
    m["hello"] = 3; // 插入
    m["world"] = 2;
  //  m.insert(pair<string, int>("aaa", 3)); // 插入

    cout << m["world"] << endl; // 查找: 可以用来查找 但是找不到会在当前索引插入0这个数据 所以还是用 find方法
    cout << "==================" << endl;
    for (map<string, int>::iterator itr = m.begin(); itr != m.end(); itr++)
    {
        cout << itr->first << " " << itr->second << endl;
    }
    cout << "==================" << endl;

    map<string, int>::iterator itr = m.find("h1ello"); // 查找
    if (itr == m.end())
    {
        cout << "没找到" << endl;
    }
    else
    {
        cout << itr->first << " " << itr->second << endl;
    }

    return 0;
}