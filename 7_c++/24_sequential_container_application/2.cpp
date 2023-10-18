#include <iostream>
#include <vector>

using namespace std;

int main(void)

{
    vector<string> v;
    v.push_back("i");
    v.push_back("love");
    v.push_back("linux");
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    v.pop_back();
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    return 0;
}
