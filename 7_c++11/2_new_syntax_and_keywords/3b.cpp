#include <iostream>
#include <assert.h>
using namespace std;

int main()
{

    int *p = nullptr;
    static_assert(p != nullptr, "不满足条件 终止");

    return 0;
}