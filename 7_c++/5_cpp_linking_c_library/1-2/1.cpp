#include "my.h"
#include <iostream>

int main(void)
{
    char a[32] = "hello 1234";
    char b[32] = "world";
    strcat_my(a, b);
    printf("%s\n", a);
    char c[32] = "hello";
    char d[32] = "world";
    strcpy_my(a, b);
    printf("%s\n", a);
    return 0;
}
