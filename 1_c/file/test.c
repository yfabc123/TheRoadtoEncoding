#include <stdio.h>
#include <stdlib.h>
int main()
{

    printf("\033[%d;%dH", 10, 10);
    printf("\033[%dm[]", 43);
    printf("\033[0m");
    printf("\033[%d;%dH", 10, 12);
    printf("\033[%dm[]", 43);
    printf("\033[%d;%dH", 10, 14);
    printf("\033[%dm[]", 43);
    printf("\033[%d;%dH", 11, 10);
    printf("\033[%dm[]", 43);

    printf("\033[0m");

    return 0;
}
