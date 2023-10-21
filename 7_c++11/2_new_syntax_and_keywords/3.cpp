#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    vector<int> v{1, 2, 3};
    map<string, int> m{{"b", 1}, {"bb", 2}, {"c", 3}};
    for (auto p : v)
    {
        cout << p << endl;
    }

    return 0;
}