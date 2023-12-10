#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include "mysem.h"
int main(void)
{
    pid_t cpid;
    cpid = fork();

    unsigned short array[] = {1};
    int semListId = sem_create(1, array);
    sleep(3);
    if (cpid == -1)
    {
        perror("[ERROR] fork(): ");
        exit(EXIT_FAILURE);
    }
    
    else if (cpid == 0)
    {
        while (1)
        {

            sem_p(semListId, 0);
            printf("------------------------\n");
            printf("C Start.\n");
            sleep(1);
            printf("C End.\n");
            printf("------------------------\n");
            sem_v(semListId, 0);
        }
    }
    else if (cpid > 0)
    {
        while (1)
        {
            sem_p(semListId, 0);
            printf("------------------------\n");
            printf("P Start.\n");
            sleep(1);
            printf("P End.\n");
            printf("------------------------\n");
            sem_v(semListId, 0);
        }
        wait(NULL);
    }
    return 0;
}
