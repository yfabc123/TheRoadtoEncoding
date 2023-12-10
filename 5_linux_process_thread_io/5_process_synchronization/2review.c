#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define PATHNAE "."
#define PROID 1
union sem
{
    int val;
};

int main()
{
    key_t key = ftok(PATHNAE, PROID);
    int semid = semget(key, 2, IPC_CREAT | 0777);
    union sem s1, s2;
    s1.val = 1;
    semctl(semid, 0, SETVAL, s1);
    s2.val = 2;
    semctl(semid, 1, SETVAL, s2);

    return 0;
}