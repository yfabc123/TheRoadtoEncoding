#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;
class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};
int main()
{
    vector<int> v;

    v.push_back(10);
    v.push_back(30);
    v.push_back(40);
    v.push_back(20);
    v.push_back(50);

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

#if 0
	template< class RandomIt, class Compare >
	void sort( RandomIt first, RandomIt last, Compare comp );
#endif
    // 方法一：自己实现仿函数
     sort(v.begin(), v.end(), MyCompare());

    // 方法二：使用STL内建仿函数  大于仿函数
   // sort(v.begin(), v.end(), greater<int>());

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
