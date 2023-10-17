#include <iostream>

using namespace std;

class Parent
{
public:
    void vir_function1()
    {
        cout << "Parent virtual_function1" << endl;
    }

    virtual void vir_function2()
    {
        cout << "Parent virtual_function2" << endl;
    }

private:
    int a;
    int b;
};

class Child : public Parent
{
public:
    virtual void vir_function1()
    {
        cout << "Child virtual_function1" << endl;
    }

    virtual void vir_function2(int a)
    {
        cout << "Child virtual_function2" << endl;
    }

private:
    int c;
};

int main(void)
{
    Parent object;

    object.vir_function1(); // Parent virtual_function1
    object.vir_function2(); // Parent virtual_function2
    cout << "-----------------------" << endl;

    Child child;

    child.vir_function1(); // Child virtual_function1(隐藏了父类函数)

    // error:no matching function for call to ‘Child::vir_function2()’
    child.vir_function2(1); //(隐藏了父类函数)
    // maybe you must child.Parent::vir_function2();

    cout << "-----------------------" << endl;
    Parent *p = &child; // behavior depends on type of the pointer
    p->vir_function1(); // Parent virtual_function1

    //
    ((Child *)p)->vir_function2(1); // Parent virtual_function2

    return 0;
}
