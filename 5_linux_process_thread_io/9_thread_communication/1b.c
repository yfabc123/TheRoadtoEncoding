#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
// 线程执行函数
void *do_thread(void *arg)
{
    static int retval = 1000;
    pthread_exit(&retval); // 子线程的返回值
}
int main(void)
{
    pthread_t tid; // 保存线程id
    int err;
    void *pret = NULL;
    err = pthread_create(&tid, NULL, do_thread, NULL);
    if (err != 0)
    {
        fprintf(stderr, "[ERROR] pthread_create(): %s \n", strerror(err));
        exit(EXIT_FAILURE);
    }
    pthread_join(tid, &pret);
    printf("ret = %d\n", *(int *)pret);
    return 0;
}
