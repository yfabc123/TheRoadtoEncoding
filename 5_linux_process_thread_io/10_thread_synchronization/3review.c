#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
int global;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
// 三个生产者 分别最多生产 2 3 4件商品
void *produce(void *a)
{
    int count = (int)a;
    while (1)
    {
        sleep(1);
        pthread_mutex_lock(&mutex);
        for (int i = 0; i < count && global < 6; i++)
        {
            printf("%ld生产了1个,当前产品总数是:%d\n", pthread_self(), ++global);
        }
        pthread_mutex_unlock(&mutex);
    }
}
void *consume(void *a)
{
    while (1)
    {
        pthread_mutex_lock(&mutex);
        if (global > 0)
        {
            printf("%ld消费了1个,当前产品总数是:%d\n", pthread_self(), --global);
        }
        pthread_mutex_unlock(&mutex);
    }
}
int main()
{
    int ret;
    pthread_t tids[4];
    for (int i = 0; i < 3; i++)
    {
        ret = pthread_create(&tids[i], NULL, produce, (void *)(i + 1));
        if (ret < 0)
        {
            perror("");
            return -1;
        }
    }
    ret = pthread_create(&tids[3], NULL, consume, NULL);
    if (ret < 0)
    {
        perror("");
        return -1;
    }
    for (int i = 0; i < 4; i++)
    {
        pthread_join(tids[i], NULL);
    }
    return 0;
}