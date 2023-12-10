#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char buf[32] = {0};
    strcat(buf, NULL);

    return 0;
}