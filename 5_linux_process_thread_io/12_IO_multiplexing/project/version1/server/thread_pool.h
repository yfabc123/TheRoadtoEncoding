#ifndef __THREAD_H_
#define __THREAD_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>

typedef struct tpool_task{
	void (*function)(void *arg);
	void *arg;
}tpool_task_t;

typedef struct tpool{
	tpool_task_t *tp_task;

	int tp_qcapacity;// 容量
	int tp_qsize;//长度

	int tp_qfront;// 队头
	int tp_qrear;// 队尾
	pthread_t *tp_work_thread_ids;// 指向存储线程id空间的指针

	int tp_number_of_threads;// 总的线程数量

	pthread_mutex_t tp_mutex_pool;// 线程池互斥锁

	pthread_cond_t tp_cond_empty;
	pthread_cond_t tp_cond_full;

	bool tp_shutdown;


}tpool_t;

extern tpool_t *thread_pool_init(int cnt,int queuesize);
extern void thread_pool_add_task(tpool_t *pool,void (*task)(void *arg),void *arg);
extern int thread_pool_destroy(tpool_t *pool);
void *tp_worker(void *arg);

#endif
