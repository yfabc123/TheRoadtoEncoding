#include <iostream>
#include <string>
using namespace std;

template <double d>
double process(double v)
{
    return v * d;
};

// template <string name>
// class MyClass
// {
// };

template <char const *name>
class MyClass
{
};

char const s[] = "hello";
MyClass<s> obj;

template <char const *name>
class MyClass
{
};

extern char const s[] = "hello";
MyClass<s> obj;
