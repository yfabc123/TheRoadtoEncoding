// 实现通过消息队列持续发送消息给另一个进程  另一端一直接收 接收到quit结束
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
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
    int mqid = msgget(key, IPC_CREAT | 0777);
    msg_t m;
    m.msgType =  140419204576512;
    int ret;
    while (1)
    {
        printf("等待接收消息:");
        //memset(m.msg, 0, sizeof(m.msg));
        size_t size = msgrcv(mqid,&m, MSGSIZE,  140419204576512, 0);
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
        printf("%s\n", m.msg);
    }
    return 0;
}