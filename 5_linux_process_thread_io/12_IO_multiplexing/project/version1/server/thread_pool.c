#include "thread_pool.h"
#include "server.h"

#define DEBUG

tpool_t *thread_pool_init(int cnt,int queuesize)
{
	int ret;

	// 给线程池数据结构分配空间
	tpool_t *pool  = (tpool_t *)malloc(sizeof(tpool_t));
	if (!pool)
		goto err;	
	
	//分配保存线程ID的空间
	pool->tp_work_thread_ids = (pthread_t *)malloc(sizeof(pthread_t) * cnt);
	if (!pool->tp_work_thread_ids)
		goto err;
	
	memset(pool->tp_work_thread_ids,0,sizeof(pthread_t) * cnt);

	pool->tp_number_of_threads = cnt;
	
	
	ret = pthread_mutex_init(&pool->tp_mutex_pool,NULL);
	if (ret != 0)
		goto err;

	ret = pthread_cond_init(&pool->tp_cond_empty,NULL);
	if (ret != 0)
		goto err;

	ret = pthread_cond_init(&pool->tp_cond_full,NULL);
	if (ret != 0)
		goto err;

	pool->tp_qcapacity = queuesize;

	pool->tp_task = (tpool_task_t *)malloc(sizeof(tpool_task_t) * pool->tp_qcapacity);
	if (!pool->tp_task)
		goto err;

	pool->tp_qsize = 0;
	pool->tp_qfront = 0;
	pool->tp_qrear = 0;

	pool->tp_shutdown = false;

	for (int i = 0;i < pool->tp_number_of_threads;i++){
		ret = pthread_create(&pool->tp_work_thread_ids[i],NULL,tp_worker,pool);
		if (ret != 0){
			fprintf(stderr,"pthread_create(): %s\n",strerror(ret));
			goto err;
		}

		pthread_detach(pool->tp_work_thread_ids[i]);
	}

	return pool;

err:
	if (pool && pool->tp_task)
		free(pool->tp_task);
	if (pool && pool->tp_work_thread_ids)
		free(pool->tp_work_thread_ids);
	if (pool)
		free(pool);
	return NULL;	
}

void *tp_worker(void *arg)
{
	//获取线程池数据结构对象	
	tpool_t *pool = (tpool_t *)arg;
	tpool_task_t task;

	for(;;){
		pthread_mutex_lock(&pool->tp_mutex_pool);
		//判断任务队列是否为空，如果为空，则会让工作线程进入阻塞状态
		while(pool->tp_qsize == 0&& !pool->tp_shutdown){
			pthread_cond_wait(&pool->tp_cond_empty,&pool->tp_mutex_pool);
		}

		// 判断销毁标志是否为真
		if (pool->tp_shutdown){
			pthread_mutex_unlock(&pool->tp_mutex_pool);
			pthread_exit(NULL);
		}
		
		task.function = pool->tp_task[pool->tp_qfront].function;
		task.arg = pool->tp_task[pool->tp_qfront].arg;
		pool->tp_qfront = (pool->tp_qfront + 1) % pool->tp_qcapacity;
		pool->tp_qsize--;

		pthread_cond_signal(&pool->tp_cond_full);
		pthread_mutex_unlock(&pool->tp_mutex_pool);
		printf("[DEBUG] Thread %ld start working...\n",pthread_self());
			
		task.function(task.arg);// 执行任务
		free(task.arg);
		printf("[DEBUG] Thread %ld end working...\n",pthread_self());
	}

}

 void thread_pool_add_task(tpool_t *pool,void (*task)(void *arg),void *arg)
{
	// 获取线程池互斥锁
	pthread_mutex_lock(&pool->tp_mutex_pool);

	//判断任务队列是否已满，如果已满，则阻塞用户线程
	while(pool->tp_qcapacity == pool->tp_qsize && !pool->tp_shutdown){
		pthread_cond_wait(&pool->tp_cond_full,&pool->tp_mutex_pool);
	}

	//判断线程池是否销毁
	if (pool->tp_shutdown){
		pthread_mutex_unlock(&pool->tp_mutex_pool);
		return;
	}
	
	// 将任务添加到任务队列中
	pool->tp_task[pool->tp_qrear].function = task;
	pool->tp_task[pool->tp_qrear].arg = arg;



	pool->tp_qrear = (pool->tp_qrear + 1) % pool->tp_qcapacity;
	pool->tp_qsize++;

	pthread_cond_signal(&pool->tp_cond_empty);// 唤醒工作线程执行任务
	pthread_mutex_unlock(&pool->tp_mutex_pool);
}

int thread_pool_destroy(tpool_t *pool)
{
	if (!pool)
		return -1;
	
	pool->tp_shutdown = true;

	for (int i = 0;i < pool->tp_number_of_threads;i++){
		pthread_cond_signal(&pool->tp_cond_empty);
	}

	if (pool->tp_task)
		free(pool->tp_task);
	
	if (pool->tp_work_thread_ids)
		free(pool->tp_work_thread_ids);
	
	pthread_mutex_destroy(&pool->tp_mutex_pool);
	pthread_cond_destroy(&pool->tp_cond_empty);
	pthread_cond_destroy(&pool->tp_cond_full);

	free(pool);

	pool = NULL;
	return 0;
	
}

