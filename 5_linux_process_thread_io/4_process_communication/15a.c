// 实现通过消息队列持续发送消息给另一个进程  另一端一直接收 接收到quit结束
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <pthread.h>
#define PATHNAME "."
#define PROJID 1
#define MSGTYPE 100
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
    m.msgType = 139850919417088;
    int ret;
    while (1)
    {
        memset(m.msg, 0, sizeof(m.msg)); // 把发送内容初始化!不要初始化长度!
        printf("等待发送消息:");
        fgets(m.msg, 64, stdin);
        m.msg[strlen(m.msg) - 1] = 0;
        ret = msgsnd(mqid, &m, MSGSIZE, 0);
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
    return 0;
}