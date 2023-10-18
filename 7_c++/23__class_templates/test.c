#include <stdio.h>
#include <stdlib.h>
extern char const s[] = "hello";

extern int a = 4;
int main()
{
    printf("%d", a);
    return 0;
}