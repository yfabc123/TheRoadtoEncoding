#include <iostream>
using namespace std;
class B1
{
public:
    int i;

protected:
    int k;
};

class B2
{
public:
    int l;

private:
    int m;

protected:
    int q;
};
class B3
{
public:
    int p1;
};
class C : public B2, protected B1, private B3
{
public:
    int c;
};
