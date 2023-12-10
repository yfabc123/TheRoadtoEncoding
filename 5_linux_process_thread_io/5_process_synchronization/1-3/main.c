#include "sem.h"
int main(void)
{
	pid_t cpid;
	int semid;
	unsigned short values[] = {1}; // 如果有多个信号量 填入数组即可
	semid = sem_create(1, values);
	if (semid == -1)
		return -1;
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
			sem_p(semid, 0); // 参数0表示抢占编号为0的信号量资源
			printf("------------------------\n");
			printf("C Start.\n");
			sleep(1);
			printf("C End.\n");
			printf("------------------------\n");
			sem_v(semid, 0); // 释放资源再次争抢资源
		}
	}
	else if (cpid > 0)
	{
	//	sleep(1);
		while (1)
		{
			sem_p(semid, 0);
			printf("------------------------\n");
			printf("P Start.\n");
			sleep(1);
			printf("P End.\n");
			printf("------------------------\n");
			sem_v(semid, 0);
			sleep(1);
		}
		wait(NULL);
		sem_del(semid);
	}
	return 0;
}
