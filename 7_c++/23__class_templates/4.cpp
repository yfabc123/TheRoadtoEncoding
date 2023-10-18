#include <iostream>
#include <string>
using namespace std;

template <char const *name>
class MyClass
{
public:
    int a;
};
char const s[] = "hello";
int main()
{
    MyClass<s> obj;
    obj.a = 1;
    cout << obj.a << endl;

    return 0;
}
