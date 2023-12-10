#include <stdio.h>
#include <string.h>
int factorial(int i)
{
    if (1 == i)
    {
        return i;
    }
    return i * factorial(i - 1);
}

int main()
{
    printf("%d\n", factorial(10));
    return 0;
}