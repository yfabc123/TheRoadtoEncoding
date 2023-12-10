#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define PATHNAME "."
#define PRO_ID 10
#define MSG_TYPE 101
#define MSG_SZ 64
struct msgbuf
{
    long mtype;
    char mtext[MSG_SZ];
};
int main(void)
{
    key_t key;
    int msgid, ret;
    ssize_t rbytes;
    struct msgbuf msg;
    key = ftok(PATHNAME, PRO_ID);
    if (key == -1)
    {
        perror("[ERROR] fotk(): ");
        exit(EXIT_FAILURE);
    }
    msgid = msgget(key, IPC_CREAT | 0666);
    if (msgid == -1)
    {
        perror("msgget(): ");
        exit(EXIT_FAILURE);
    }
    rbytes = msgrcv(msgid, (void *)&msg, MSG_SZ, MSG_TYPE, 0);
    if (rbytes == -1)
    {
        perror("[ERROR] msgrcv(): ");
        exit(EXIT_FAILURE);
    }
    printf("msgid:%d,msg.mtype:%d,msg.mtext:%s\n", msgid, MSG_TYPE, msg.mtext);

    ret = msgctl(msgid, IPC_RMID, NULL);
    if (ret == -1)
    {
        perror("msgctl(): ");
        exit(EXIT_FAILURE);
    }
    return 0;
}
