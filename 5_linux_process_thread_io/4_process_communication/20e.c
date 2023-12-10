/*  两个进程实现拷贝数据  一个把文件数据读取共享内存 另一个从共享内存读出到文件
实现思路:flag 1表示只写 0表示只读 初始设为1 读端先读取到缓冲区看看第一个字段是不是可读
是的话后面全读入文件 不是的话继续循环直到可读
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define PATH "."
#define PROJID 1
#define FILENAME "copy.png"
typedef struct
{
    int flag;
    int finish; // 结束标志
    char msg[1024];
} Data;
int main()
{
    FILE *file = fopen(FILENAME, "w+");
    if (file == NULL)
    {
        perror("fopen");
        return -1;
    }
    key_t key = ftok(PATH, PROJID);
    int shmid = shmget(key, sizeof(Data), IPC_CREAT | 0666);
    Data *data = (Data *)shmat(shmid, NULL, 0);
    if (data == NULL)
    {
        perror("shmat");
        return -1;
    }
    data->flag = 1;
    while (1)
    {
        //  printf("等待读取\n");
        if (data->flag == 0)
        {
            printf("开始读出共享内存\n");
            size_t witem = fwrite(data->msg, 1, 1024, file); // 照片数据读取到共享内存
            if (data->finish == 1)
            {
                printf("写端结束了 读取结束\n");
                break;
            }
            data->flag = 1;
        }
        //   sleep(1);
    }
    shmdt(data);
    return 0;
}