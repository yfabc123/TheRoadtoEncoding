#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<string> q;
    q.push("hello");
    q.push("i");
    q.push("love");
    q.push("cpp");
    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }

    return 0;
}