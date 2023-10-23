#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // srand((unsigned)time(NULL));
    int a = random();
    int b = random();

    printf("%d %d", a, b);
    return 0;
}