#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
    int cpid = fork();
    if (cpid > 0)
    {
        exit(0);
    }
    else
    {
        while (1)
        {
            sleep(1);
            printf("我是孤儿\n");
        }
    }
    return 0;
}