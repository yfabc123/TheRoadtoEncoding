#include <iostream>
#include "space.h"
using namespace std;
int calc(int a, int b);

int main()
{

    cout << "a.cpp 全局函数:" << ::calc(2, 2) << endl;
    cout << "b.cpp:" << B_SPACE::calc(1, 2) << endl;

    return 0;
}
