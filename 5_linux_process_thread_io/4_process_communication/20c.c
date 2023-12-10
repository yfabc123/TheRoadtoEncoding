#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sem.h>
#include <signal.h>

#define PATHNAME "."

struct file_mem{
	
	int magic_no;/*数据块的编号*/
	int size;/*数据块的大小*/
	char buffer[1024];/*数据块缓冲区*/
};

/*共享内存创建标志*/
int g_shm_created = 1;

/*
 *获取共享内存key
 * 
 * */
key_t getkey(void)
{
	return ftok(PATHNAME,1);
}

/*
 *创建共享内存
 * 
 *返回struct file_mem 指针
 * */
struct file_mem *open_shm(void)
{
	key_t key;
	int shm;

	key = getkey();
	shm = shmget(key,sizeof(struct file_mem),0666);
	if (shm < 0){
		shm = shmget(key,sizeof(struct file_mem),0666|IPC_CREAT);	
		if (shm < 0){
			return NULL;
		}
		/*创建标志设置为共享内存的id*/
		g_shm_created = shm;
	}
	/*进程映射到共享内存中*/
	return (struct file_mem *)shmat(shm,NULL,0);
}

/*
 *解除映射，并删除共享内存 
 * */
void close_shm(struct file_mem *p)
{
	shmdt(p);
	if (g_shm_created)
		shmctl(g_shm_created,IPC_RMID,NULL);
		
}

/*等待文件传输
 *
 * */
void wait_for_file(void)
{
	struct file_mem *p = open_shm();	
	if (p != NULL){
		int times = 0;
		/*last_no 记录最后一次数据块的编号*/
		int last_no = p->magic_no;

		/*当last_no 等于数据块编号时，则表示没有开始传输*/
		while(last_no == p->magic_no)
		{
			usleep(100000);
		}
		printf("[Server is online!]\n");

		/*当last_no 与p->magic_no编号不一致时，赋值给last_no*/
		last_no = p->magic_no;
		while(1){

			/*当last_no与数据块编号不相等时，更新last_no*/
			if (last_no != p->magic_no){
				times = 0;
				last_no = p->magic_no;
			}else{
				times++;	
				if (times > 1000){
					printf("[Server is down.]\n");
					break;
				}
			}
			
			/*当size >0 则表示有数据*/
			if (p->size > 0){
				p->buffer[p->size] = 0;/*将数据块尾添加'\0'*/
				printf(p->buffer);/*打印到stdout*/
				fflush(stdout);
				p->size = 0;/*将数据块的大小置为0，等待下一个数据块*/
			
			}else{
				usleep(1000);/*没有数据则睡眠*/
			}
		}

		close_shm(p);
	}
}

int main(int argc,char *argv[])
{
	struct file_mem *p;
	FILE *fp;
	size_t reads;

	if (argc < 2){
		wait_for_file();
		exit(0);
	}
	if ((fp = fopen(argv[1],"r+")) == NULL){
		perror("fopen failed.\n");
		exit(0);
	}
	p = open_shm();/*创建共享内存并映射到共享内存上*/
	if (p != NULL){
		p->size = 0;/*将size设置为0*/
		while(!feof(fp)){
			p->magic_no++;/*数据块编号加1*/

			/*将size = 0时，在将数据写入到共享内存中*/
			if (p->size == 0){
				/*数据缓冲区添加'\0'*/
				p->buffer[sizeof(p->buffer) -1] = 0;
				/*从文件中读取数据到buffer中，并留一个位置给'\0'*/
				reads = fread(p->buffer,1,sizeof(p->buffer) - 1,fp);
				if(reads > 0){
					p->size = reads;/*读取成功，则更新size的值*/
				}
			
			}
		}

		printf("send over.\n");
		close_shm(p);
	}
	fclose(fp);
}
