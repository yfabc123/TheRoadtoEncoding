#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include "mysem.h"
int main(void)
{
    pid_t cpid;
    unsigned short array[2] = {1, 1}; // 0控制  1 二次控制
    int semListId = sem_create(2, array);
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
            sem_p(semListId, 0);
             sleep(1);
            printf("A\n");
            sem_v(semListId, 0);
            sem_p(semListId, 1); // 占用1 阻塞
        }
    }
    else if (cpid > 0)
    {
        while (1)
        {
            sem_p(semListId, 0);
             sleep(1);
            printf("B\n");
            sem_v(semListId, 0);
            sem_v(semListId, 1); // 释放1
        }
        wait(NULL);
    }
    return 0;
}
