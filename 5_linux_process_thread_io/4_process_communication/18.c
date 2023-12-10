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
#define proj_id 23
int main()
{
    key_t key = ftok(pathname, proj_id);
    int shmid = shmget(key, 256, IPC_CREAT | 0777);
    printf("%d", shmid);
    int shmctl_result = shmctl(shmid, IPC_RMID, NULL);
    return 0;
}