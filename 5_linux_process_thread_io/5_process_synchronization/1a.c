#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int main(void)
{
    pid_t cpid;
    cpid = fork();
    if (cpid == -1)
    {
        perror("[ERROR] fork(): ");
        exit(EXIT_FAILURE);
    }
    else if (cpid == 0)
    {
        while (1)
        {
            printf("------------------------\n");
            printf("C Start.\n");
            sleep(1);
            printf("C End.\n");
            printf("------------------------\n");
        }
    }
    else if (cpid > 0)
    {
        while (1)
        {
            printf("------------------------\n");
            printf("P Start.\n");
            sleep(1);
            printf("P End.\n");
            printf("------------------------\n");
        }
        wait(NULL);
    }
    return 0;
}
