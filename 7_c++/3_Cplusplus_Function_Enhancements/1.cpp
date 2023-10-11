#include <stdio.h>

int add(int a, int b=1)
{

    return (a + b);
}

int add(int a, int b, int c)
{

    return (a + b + c);
}
float add(double a, double b)
{

    return (a + b);
}
int main(void)
{

    printf("%d\n", add(1));
    printf("%d\n", add(1, 2, 3));
    printf("%f\n", add((double)1, 2.22));

    return 0;
}
