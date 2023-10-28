#include <iostream>
using namespace std;
class A
{
public:
    ~A()
    {
        cout << "~A()" << endl;
    }
    void change()
    {
        c = 1;
    }
    class B
    {
    public:
        int age = 13;
        void fun()
        {
            c = 4;
        }
        ~B()
        {
            cout << age;

            this->age = 4;
            cout << age;
            cout << " ~B()" << endl;
        }
    };
    static B b;
    A *a;
   static int c;
};
A::B b;
int main()
{ //  delete a;

    return 0;
}
