#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(void)
{
    int global = 0;
    pid_t cpid;
    cpid = fork();
    if (cpid == -1)
    {
        perror("fork(): ");
        return -1;
    }
    if (0 == cpid)
    {
        global = 100;
    }
    else
    {
        printf("global:%d\n", global);
    }
    return 0;
}
