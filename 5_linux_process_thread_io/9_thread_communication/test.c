#include "head.h"
void fun(int * b)
{
    *b = 4;
    // printf("%d\n", b);
}
int main()
{
    int a = 3;
    fun(&a);
    printf("%d\n", a);
    return 0;
}