#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define SEM_PATHNAME "."
#define SEM_PRO_ID 100
union semun
{
    int val;
};
int main(void)
{
    int semid, ret;
    union semun s;
    key_t key = ftok(SEM_PATHNAME, SEM_PRO_ID);
    if (key == -1)
    {
        perror("[ERROR] ftok() : ");
        return -1;
    }
    semid = semget(key, 1, IPC_CREAT | 0666);
    if (semid == -1)
    {
        perror("[ERROR] semget() : ");
        return -1;
    }
    s.val = 2;
    ret = semctl(semid, 0, SETVAL, s);
    if (ret == -1)
    {
        perror("[ERROR] semctl() : ");
        return -1;
    }
    return 0;
}
