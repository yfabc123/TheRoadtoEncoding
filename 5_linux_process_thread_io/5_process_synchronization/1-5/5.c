
#include "sem.h"

#define SEM_CONTROL_P 0
#define SEM_CONTROL_C 1

int main(void)
{

    pid_t cpid;
    int semid;
    unsigned short values[2] = {1, 0};

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
            time_t t;
            struct tm *p_datetime;
            t = time(NULL);
            p_datetime = localtime(&t);
            sem_p(semid, SEM_CONTROL_C);
            printf("%d-%d-%d %d:%d:%d", p_datetime->tm_year + 1900, p_datetime->tm_mon + 1,
                   p_datetime->tm_mday, p_datetime->tm_hour, p_datetime->tm_min, p_datetime->tm_sec);
            fflush(stdout);
            sem_v(semid, SEM_CONTROL_P);
        }
    }
    else
    {
        int i = 1;
        while (i < 111)
        {
            sem_p(semid, SEM_CONTROL_P);
            printf("%d,<", i);
            fflush(stdout);
            sem_v(semid, SEM_CONTROL_C);
            sem_p(semid, SEM_CONTROL_P);
            printf(">\n");
            fflush(stdout);
            i++;
            sem_v(semid, SEM_CONTROL_P);
            sleep(1);
        }

        wait(NULL);
    }

    return 0;
}
