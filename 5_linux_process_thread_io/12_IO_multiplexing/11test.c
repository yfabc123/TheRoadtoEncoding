#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
void fun2(int a, int b)
{
    printf("%d", a + b);
}
void fun1(int a, int b, void (*fun2)(int, int))
{
    fun2(a, b);
}
int main()
{
    fun1(1,2,fun2);
    return 0;
}