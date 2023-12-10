#include "head.h"

#define MSG_PATHNAME "."
#define MSG_PRO_ID 44

int main()
{

    key_t key;
    int msg_id, ret;

    key = ftok(MSG_PATHNAME, MSG_PRO_ID);
    if (-1 == key)
    {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    msg_id = msgget(key, IPC_CREAT | 777);
    if (msg_id == -1)
    {
        perror("msgget");
    }
    printf("msgid:%d\n", msg_id);

    return 0;
}
