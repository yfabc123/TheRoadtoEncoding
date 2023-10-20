#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<string> s;
    s.push("hello");
    s.push("i");
    s.push("love");
    s.push("cpp");
    while (!s.empty())
    {
        cout << s.top() << endl;
    }

    return 0;
}