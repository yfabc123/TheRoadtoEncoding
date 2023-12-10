#include "head.h"
int global = 0;
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // 定义互斥锁
void *sum(void *para)
{
    for (int i = 0; i < 1000000000; i++)
    {
        pthread_mutex_lock(&mutex);
        global++;
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}
int main()
{
    // 创建线程
    pthread_t pid[2];
    int ret = 0;
    for (int i = 0; i < 2; i++)
    {
        ret = pthread_create(&pid[i], NULL, sum, NULL);
        if (ret != 0)
        {
            printf("%s", strerror(ret));
            exit(EXIT_FAILURE);
        }
    }
    pthread_join(pid[0], NULL);
    pthread_join(pid[1], NULL);
    printf("%d", global);
    return 0;
}