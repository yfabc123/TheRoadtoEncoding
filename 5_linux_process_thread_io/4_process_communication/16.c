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
#define pathname "."
#define proj_id 8
#define bufsize 64
// 存放消息的结构体
struct msgbuf
{
    long mtype;
    char mtext[bufsize];
};
int main()
{
    // 得到一个key
    key_t key_mq = ftok(pathname, proj_id);
    // 创建一个队列
    int msqid = msgget(key_mq, IPC_CREAT | 0777);
    struct msgbuf msgp; // 父进程用于存放发送数据的结构体
    ssize_t size;
    char temp1[64] = {0}; // 定义一个缓冲区
    char temp2[64] = {0}; // 定义一个缓冲区
    // 控制台获取数据 遇到quit退出循环
    pid_t cpid1 = fork();
    if (cpid1 == 0)
    {
        struct msgbuf msgp; // 子进程1用于存放接收据的结构体
        while (1)
        {
            ssize_t size = msgrcv(msqid, (void *)&msgp, bufsize, 100, 0);
            if (-1 == size)
            {
                perror("msgrcv");
                break;
            }
            printf("子进程1收到的数据是:%s", msgp.mtext);
        }
    }
    else if (cpid1 > 0)
    {
        pid_t cpid2 = fork();
        if (cpid2 == 0)
        {
            struct msgbuf msgp; // 子进程2用于存放接收据的结构体
            while (1)
            {
                ssize_t size = msgrcv(msqid, (void *)&msgp, bufsize, 200, 0);
                if (-1 == size)
                {
                    perror("msgrcv");
                    break;
                }
                printf("子进程2收到的数据是:%s", msgp.mtext);
            }
        }
        else
        {
            while (1)
            {
                printf("请输入传给进程1的数据:");
                fgets(temp1, bufsize, stdin);
                if (strncmp("quit", temp1, 4) == 0)
                {
                    break;
                }
                printf("请输入传给进程2的数据:");
                fgets(temp2, bufsize, stdin);
                if (strncmp("quit", temp2, 4) == 0)
                {
                    break;
                }
                else
                {
                    // 写给进程1的数据
                    strcpy(msgp.mtext, temp1);
                    msgp.mtype = 100;
                    size = msgsnd(msqid, (const void *)&msgp, bufsize, 0); // 循环往队列里面写数据
                    // 写给进程1的数据
                    strcpy(msgp.mtext, temp2);
                    msgp.mtype = 200;
                    size = msgsnd(msqid, (const void *)&msgp, bufsize, 0); // 循环往队列里面写数据
                }
                sleep(1);
            }
        }
        // kill(cpid1, SIGKILL);
        // kill(cpid2, SIGKILL);
        // wait(NULL);
        // wait(NULL);
    }
    return 0;
}