#include <stdio.h>
#include <sys/sem.h>
#include <errno.h>
#define pathname "."
#define proj_id 1
union semun
{
    int val;               /* Value for SETVAL */
    struct semid_ds *buf;  /* Buffer for IPC_STAT, IPC_SET */
    unsigned short *array; /* Array for GETALL, SETALL */
    struct seminfo *__buf; /* Buffer for IPC_INFO
                              (Linux-specific) */
};
int main()
{
    key_t key = ftok(pathname, proj_id);
    int semid = semget(key, 2, IPC_CREAT | 0777);
    union semun semun1, semun2;
    semun1.val = 1;
    semun2.val = 2;
    int ret = semctl(semid, 0, SETVAL, semun1);
    if (ret == -1)
    {
        perror("[ERROR] semctl() : ");
        return -1;
    }
    ret = semctl(semid, 1, SETVAL, semun2);
    if (ret == -1)
    {
        perror("[ERROR] semctl() : ");
        return -1;
    }
    return 0;
}
