#include "sem.h"
#include <sys/sem.h>
#define SEM_PATHNAME "."
#define SEM_PRO_ID 99
union semun
{
    int val;               /* Value for SETVAL */ // 设置信号量资源数
    struct semid_ds *buf;  /* Buffer for IPC_STAT, IPC_SET */
    unsigned short *array; /* Array for GETALL, SETALL */
    struct seminfo *__buf; /* Buffer for IPC_INFO
                              (Linux-specific) */
};
/*
	创建信号量集合同时确定每个信号量的资源数 也就是初始化
	@param nsems : 信号量的数量
	@param values : 信号量的值
	@return :
		成功 : 0
		失败 : -1
*/
int sem_create(int nsems,  short values[])
{
	int semid, ret;
	key_t key;
	union semun s;
	key = ftok(SEM_PATHNAME, SEM_PRO_ID);
	if (key == -1)
	{
		perror("[ERROR] ftok() : ");
		return -1;
	}
	semid = semget(key, nsems, IPC_CREAT | 0666);
	if (semid == -1)
	{
		perror("[ERROR] semget() : ");
		return -1;
	}
	// 设置信号量的值(或者说信号量的资源数)
	s.array = values;
	ret = semctl(semid, 0, SETALL, s); // 第二个参数0实际上是无效的
	if (ret == -1)
	{
		perror("[ERROR] semctl() : ");
		return -1;
	}
	return semid;
}
/*
	占用信号量资源
	@param semid : 信号量集合的id
	@param semnum : 操作的信号量编号
		个人的理解：相当于内核提供了操作信号量的函数 但是你需要按规定传三个参数 信号量集合id  存放某个信号量信息的结构体
*/
int sem_p(int semid, int semnum)
{
	struct sembuf sops;
	sops.sem_num = semnum;	 // 信号量的编号
	sops.sem_op = -1;		 // 占用一个资源 总资源减少一个
	sops.sem_flg = SEM_UNDO; // 进程终止,系统会帮我们自动释放信号量
	return semop(semid, &sops, 1); // 1表示占用资源
}
/*
	释放信号量资源
	@param semid : 信号量集合的id
	@param semnum : 操作的信号量编号
*/
int sem_v(int semid, int semnum)
{
	struct sembuf sops;
	sops.sem_num = semnum;
	sops.sem_op = 1; // 释放资源
	sops.sem_flg = SEM_UNDO;
	return semop(semid, &sops, 1);
}
/*
	删除信号量集合
	@param semid : 信号量集合的id
*/
int sem_del(int semid)
{
	return semctl(semid, 0, IPC_RMID, NULL); // 第二个参数0实际上是无效的
}
