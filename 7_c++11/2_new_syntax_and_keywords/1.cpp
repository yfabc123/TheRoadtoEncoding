#include <iostream>
#include <vector>

using namespace std;


int main(int argc, const char *argv[])
{
    auto a = 10;
    auto b = 12.8;
    auto c = &a;
    auto str = "hello world";
    int data = 100;

    vector<string> v;

    v.push_back("hello1");
    v.push_back("hello2");
    v.push_back("hello3");

    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }

    return 0;
}
