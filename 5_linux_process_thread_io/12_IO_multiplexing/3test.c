#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    char buf[32] = {0};
    read(0, buf, 32);
    printf("%s", buf);

    return 0;
}