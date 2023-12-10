#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
// 线程执行函数
void *do_thread(void *arg)
{
    int num = *(int *)arg;
    printf("num = %d\n", num);
    printf("thread start.\n");
    pthread_exit(NULL); // 子线程的返回值
}
int main(void)
{
    pthread_t tid; // 保存线程id
    int err;
    int num = 100;
    err = pthread_create(&tid, NULL, do_thread, &num);
    if (err != 0)
    {
        fprintf(stderr, "[ERROR] pthread_create(): %s \n", strerror(err));
        exit(EXIT_FAILURE);
    }
    pthread_join(tid, NULL);
    return 0;
}
