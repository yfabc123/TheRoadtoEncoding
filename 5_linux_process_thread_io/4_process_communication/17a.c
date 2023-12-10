#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define PATHNAME "."
#define PRO_ID 100
#define SZ 256
int main(void)
{
    key_t key;
    int shmid, ret;
    key = ftok(PATHNAME, PRO_ID);
    if (key == -1)
    {
        perror("[ERROR] key(): ");
        exit(EXIT_FAILURE);
    }
    shmid = shmget(key, SZ, IPC_CREAT | 0666);
    if (shmid == -1)
    {
        perror("shmid(): ");
        exit(EXIT_FAILURE);
    }
    printf("shmid = %d\n", shmid);
    return 0;
}
