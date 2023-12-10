#ifndef SEM_HEAD_H
#define SEM_HEAD_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/wait.h>
#define PATHNAME "."
#define PROJECTID 2
union semun
{
    int val;               /* Value for SETVAL */
    struct semid_ds *buf;  /* Buffer for IPC_STAT, IPC_SET */
    unsigned short *array; /* Array for GETALL, SETALL */
    struct seminfo *__buf; /* Buffer for IPC_INFO
                              (Linux-specific) */
};
extern int sem_create(int n, short parray[]); // 创建几个信号量
extern void sem_p(int semListId, int pSemNum);
extern void sem_v(int semListId, int pSemNum);
extern void sem_del(int semListId);
#endif