#include "mysem.h"
// 信号量创建 抢占 释放 删除
int sem_create(int n, short parray[]) // 创建几个信号量
{
    key_t key = ftok(PATHNAME, PROJECTID);
    
    if (key < 0)
    {
        perror("");
        exit(EXIT_FAILURE);
    }
    int semListId = semget(key, n, IPC_CREAT | 0777);
    if (semListId < 0)
    {
        perror("");
        exit(EXIT_FAILURE);
    }
    union semun s;
    s.array = parray;
    int ret = semctl(semListId, 0, SETALL, s);
    if (ret < 0)
    {
        perror("");
        exit(EXIT_FAILURE);
    }
    return semListId;
}
// 抢占资源 确定信号量集合 以及具体哪个信号量编号
void sem_p(int semListId, int pSemNum)
{
    struct sembuf a;
    a.sem_flg = 0;
    a.sem_num = pSemNum;
    a.sem_op = -1;
    int ret = semop(semListId, &a, 1);
    if (ret == -1)
    {
        perror("");
        exit(EXIT_FAILURE);
    }
}
// 释放资源
void sem_v(int semListId, int pSemNum)
{
    struct sembuf a;
    a.sem_flg = 0;
    a.sem_num = pSemNum;
    a.sem_op = 1;
    int ret = semop(semListId, &a, 1);
    if (ret == -1)
    {
        perror("");
        exit(EXIT_FAILURE);
    }
}
void sem_del(int semListId)
{
    semctl(semListId, 0, IPC_RMID);
}