// 自己思路的代码

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>
#include <sys/stat.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#define pathname "."
#define proj_id 2

typedef struct shm_attr
{
    int flag;  // 判断是否占用标签 0表示正在被其他进程占用 1表示无进程占用
    int flag2; // 判断是否能进行读写 0表示可读入共享内存 1表示可写出共享内存

    char data[64];
} shm_attr;
int main()
{

    // 创建ipc key
    key_t key_shm = ftok(pathname, proj_id);
    // 创建共享内存
    int shmid = shmget(key_shm, sizeof(shm_attr), IPC_CREAT);

    // 创建子进程
    pid_t cpid = fork();
    if (cpid > 0)
    {
        // 父进程映射共享内存和进程虚拟内存 并将共享内存数据重置
        struct shm_attr *shm_attr1 = (shm_attr *)shmat(shmid, NULL, 0);
        shm_attr1->flag = 1;
        shm_attr1->flag2 = 0;
        memset(shm_attr1->data, 0, sizeof(shm_attr1->data));

        // 打开文件
        FILE *fp1 = NULL;
        fp1 = fopen("./test.png", "r+");

        while (1)
        {
            if (shm_attr1->flag == 1 && shm_attr1->flag2 == 0)
            {
                shm_attr1->flag = 0; // 抢占资源设置不可读写
                memset(shm_attr1->data, 0, sizeof(shm_attr1->data));

                printf("占用资源开始读入\n");

                size_t size_ret = fread(shm_attr1->data, 1, 64, fp1); // 我其实不理解为什么引入数据块的概念
                shm_attr1->flag = 1;                                  // 释放资源
                shm_attr1->flag2 = 1;                                 // 设置为可写出
                printf("读入成功释放资源可写出\n");

                if (size_ret == 0)
                {
                    break;
                }
            }
        }
        shmdt(shm_attr1);
        shmctl(shmid, IPC_RMID, NULL);
    }
    else if (cpid == 0)
    {
        // 子进程映射共享内存和进程虚拟内存 并将共享内存数据重置
        struct shm_attr *shm_attr2 = (shm_attr *)shmat(shmid, NULL, 0);
        printf("%d-%d\n", shm_attr2->flag, shm_attr2->flag2);
        // 父进程已经重置 所以子进程不需要重复操作
        //  shm_attr1->flag = 1;
        //  shm_attr1->flag2 = 0;
        //  memset(shm_attr1->data, 0, sizeof(shm_attr1->data));

        // 打开文件
        FILE *fp1 = NULL;
        fp1 = fopen("./test_copy.png", "w+");
        while (1)
        {
            if (shm_attr2->flag == 1 && shm_attr2->flag2 == 1)
            {

                shm_attr2->flag = 0; // 抢占资源设置不可读写
                printf("占用资源开始写出\n");

                size_t size_ret = fwrite(shm_attr2->data, 1, 64, fp1); // 我其实不理解为什么引入数据块的概念
                if (size_ret == -1)
                {
                    perror("fwrite");
                }
                shm_attr2->flag = 1;  // 释放资源
                shm_attr2->flag2 = 0; // 设置为可读入
                printf("写出成功释放资源可读入\n");
                if (size_ret == 0)
                {
                    break;
                }
            }
        }
        shmdt(shm_attr2);
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}