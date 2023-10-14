#include <iostream>
#include <string.h>
using namespace std;

class A;
class B
{
public:
    void change(A *obj);
};
    
class A
{
public:
    friend void B::change(A *obj);

private:
    int age;
};
void B::change(A *obj)
{
    obj->age = 10;
    cout << obj->age << endl;
}
int main()
{
    B b;
    A a;
    b.change(&a);

    return 0;
}
