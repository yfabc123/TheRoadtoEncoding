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
#include <pthread.h>
void *do_pid1(void *para)
{
    printf("thread1\n");
}
void *do_pid2(void *para)
{
    printf("thread2\n");
}
int main()
{
    pthread_t pid1, pid2;
    pthread_create(&pid1, NULL, do_pid1, NULL);
    pthread_create(&pid2, NULL, do_pid2, NULL);
    pthread_detach(pid1);
    sleep(3);
    printf("main thread\n");
    // 验证进程是被系统回收资源的
    int ret = pthread_join(pid1, NULL);
    printf("thread1:%d: %s\n", ret, strerror(ret));
    ret = pthread_join(pid2, NULL);
    printf("thread2:%d: %s\n", ret, strerror(ret));
    return 0;
}