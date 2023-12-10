#include "shmfifo.h"
#include <string.h>

static int g_shmid;

shm_fifo_t *shmfifo_init(int blocks,int blksz)
{
	int shm_sz = 0;
	enum shm_creat_status s_creat_status;
	unsigned short values[] = {0,blocks,1};
	shm_fifo_t *p_shm_fifo = malloc(sizeof(shm_fifo_t))	;
	if (!p_shm_fifo)
		return NULL;
	shm_sz = blocks * blksz + sizeof(shm_head_t);

	s_creat_status = shm_create(shm_sz,&g_shmid);
	if (s_creat_status != SHM_CREAT_ERROR){
		p_shm_fifo->p_head = (shm_head_t *)shm_at(g_shmid);
		if (s_creat_status == SHM_CREAT_NEW){

			p_shm_fifo->p_head->rpos = 0;
			p_shm_fifo->p_head->wpos = 0;
			p_shm_fifo->p_head->blocks = blocks;
			p_shm_fifo->p_head->blksz = blksz;
			p_shm_fifo->p_head->semid = sem_create(3,values);

		}

		p_shm_fifo->p_payload = (char *)(p_shm_fifo->p_head + 1);


		return p_shm_fifo;
	}

	return NULL;
}

void shmfifo_destroy(shm_fifo_t *fifo)
{
	sem_del(fifo->p_head->semid);
	shm_dt(fifo->p_head);
	shm_del(g_shmid);
	free(fifo);
}

void shmfifo_put(shm_fifo_t *fifo,const void *buf)
{
	int pos = 0;

	sem_p(fifo->p_head->semid,SEM_FULL_ID);// 占用判满的信号量
	sem_p(fifo->p_head->semid,SEM_MUTEX_ID);

	pos = fifo->p_head->wpos * fifo->p_head->blksz;// 计算偏移量

	memcpy(fifo->p_payload + pos,buf,fifo->p_head->blksz);//拷贝数据到环形队列中
	fifo->p_head->wpos = (fifo->p_head->wpos + 1) % (fifo->p_head->blocks);// 更新偏移
	sem_v(fifo->p_head->semid,SEM_MUTEX_ID);
	sem_v(fifo->p_head->semid,SEM_EMPTY_ID);
}

void shmfifo_get(shm_fifo_t *fifo, void *buf)
{
	int pos = 0;

	sem_p(fifo->p_head->semid,SEM_EMPTY_ID);// 占用判空的信号量
	sem_p(fifo->p_head->semid,SEM_MUTEX_ID);

	pos = fifo->p_head->rpos * fifo->p_head->blksz;// 计算偏移量

	memcpy(buf,fifo->p_payload + pos,fifo->p_head->blksz);//从环形队列中拷贝数据
	fifo->p_head->rpos = (fifo->p_head->rpos + 1) % (fifo->p_head->blocks);// 更新偏移
	sem_v(fifo->p_head->semid,SEM_MUTEX_ID);
	sem_v(fifo->p_head->semid,SEM_FULL_ID);
}


