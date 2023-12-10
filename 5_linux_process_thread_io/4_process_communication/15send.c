#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define PATHNAME "."
#define PRO_ID 10
#define MSG_SZ 64
#define MSG_TYPE 101
struct msgbuf
{
    long mtype;
    char mtext[MSG_SZ];
};
int main(void)
{
    key_t key;
    int msgid, ret; // ret接收返回值
    struct msgbuf msg;
    key = ftok(PATHNAME, PRO_ID); // 创建队列key
    if (key == -1)
    {
        perror("fotk(): ");
        exit(EXIT_FAILURE);
    }
    msgid = msgget(key, IPC_CREAT | 0666); // 创建消息队列
    if (msgid == -1)
    {
        perror("msgget(): ");
        exit(EXIT_FAILURE);
    }
    // 给消息结构体赋值
    msg.mtype = MSG_TYPE;
    strcpy(msg.mtext, "测试");
    // 发送消息到队列中
    ret = msgsnd(msgid, (const void *)&msg, strlen(msg.mtext), 0);
    if (ret == -1)
    {
        perror("msgsnd(): ");
        exit(EXIT_FAILURE);
    }
    printf("msgid:%d,msg.mtype:%d,msg.mtext:%s\n", msgid, MSG_TYPE, msg.mtext);
    return 0;
}
