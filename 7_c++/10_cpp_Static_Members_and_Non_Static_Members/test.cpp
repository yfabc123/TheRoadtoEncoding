#include <iostream>

using namespace std;

class Person
{
public:
    Person(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
   // Person(int a, int b) : a(a), b(b) {}

    int a;
    static int b;
};
int Person::b = 1;
int main()
{

      Person a(1, 2);
    cout << a.a << endl;
    return 0;
}