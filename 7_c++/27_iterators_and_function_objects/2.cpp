#include <iostream>

using namespace std;
class A
{
public:
    int operator()(int a, int b)
    {
        return a > b;
    }
};
int main()
{
    A a;
    cout << a(4, 2) << endl;
    cout << A()(1,2) << endl;

    return 0;
}