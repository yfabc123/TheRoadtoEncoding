#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "./1-3/sem.h"

/*
    values[0] : P
    values[1] : C


*/

#define SEM_CONTROL_P 0
#define SEM_CONTROL_C 1

int main(void)
{
    pid_t cpid;
    int semid;
     short values[2] = {1, 0};

    semid = sem_create(2, values);
    if (semid == -1)
        exit(EXIT_FAILURE);

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
            sem_p(semid, SEM_CONTROL_C);
            printf("B");
            fflush(stdout);
            sem_v(semid, SEM_CONTROL_P);
        }
    }
    else
    {
        while (1)
        {
            sem_p(semid, SEM_CONTROL_P);
            printf("A");
            fflush(stdout);
            sem_v(semid, SEM_CONTROL_C);
            sem_p(semid, SEM_CONTROL_P);
			
            printf("A");
            fflush(stdout);
            sem_v(semid, SEM_CONTROL_P);
           // sleep(1);
            putchar('\n');
        }

        wait(NULL);
    }

    return 0;
}
