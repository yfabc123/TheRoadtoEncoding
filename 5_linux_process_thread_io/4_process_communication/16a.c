// 父进程指定子进程 然后发消息
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define PATHNAME "."
#define PROJID 1
#define MSGTYPE1 1
#define MSGTYPE2 2
#define MSGSIZE 64
typedef struct msg
{
    long msgType;
    char msg[64];
} msg_t;
int main()
{
    key_t key = ftok(PATHNAME, PROJID);
    if (-1 == key)
    {
        perror("ftok");
    }
    int mqid = msgget(key, IPC_CREAT | 0666);
    if (-1 == mqid)
    {
        perror("msgget");
    }
    msg_t m;
    int ret;
    int ch; // 清除标准输入的变量
    memset(&m, 0, sizeof(m));
    pid_t pid = fork();
    if (pid > 0)
    {
        pid = fork();
        if (pid > 0)
        {
            while (1)
            {
                memset(m.msg, 0, sizeof(m.msg));
                int n;
                printf("请输入你要发给哪个进程:");
                scanf("%d", &n);
                while ((ch = getchar()) != '\n') // 清除输入缓冲区的空格
                {
                }
                int right = 1;
                if (n == 1)
                {
                    m.msgType = 1;
                }
                else if (n == 2)
                {
                    m.msgType = 2;
                }
                else
                {
                    right = 0;
                    printf("不对\n");
                }
                if (right)
                {
                    printf("请输入你要发给该进程的数据:");
                    fgets(m.msg, 64, stdin);
                    m.msg[strlen(m.msg) - 1] = 0;
                    ret = msgsnd(mqid, (const void *)&m, MSGSIZE, 0);
                    if (ret == -1)
                    {
                        perror("msgsnd");
                        break;
                    }
                    if (strncmp(m.msg, "exit", 4) == 0)
                    {
                        printf("结束发送\n");
                        break;
                    }
                }
                sleep(1);
            }
        }
        else
        {
            while (1)
            {
                memset(m.msg, 0, sizeof(m.msg));
                m.msgType = 1;
                size_t size = msgrcv(mqid, (void *)&m, MSGSIZE, 1, 0);
                printf("进程1接收了消息:%s\n", m.msg);
                if (size < 0)
                {
                    perror("msgrcv");
                    break;
                }
                if (strcmp(m.msg, "exit") == 0)
                {
                    printf("发送端结束 接收端也结束\n");
                    break;
                }
            }
        }
    }
    else
    {
        while (1)
        {
            memset(m.msg, 0, sizeof(m.msg));
            m.msgType = 2;
            size_t size = msgrcv(mqid, (void *)&m, MSGSIZE, 2, 0);
            printf("进程2接收了消息:%s\n", m.msg);
            if (size < 0)
            {
                perror("msgrcv");
                break;
            }
            if (strcmp(m.msg, "exit") == 0)
            {
                printf("发送端结束 接收端也结束\n");
                break;
            }
        }
    }
    return 0;
}