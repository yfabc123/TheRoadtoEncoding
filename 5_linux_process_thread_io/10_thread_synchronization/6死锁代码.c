//原则:仓库满时生产者抢到锁则阻塞并唤醒子进程  仓库为空时消费者抢到锁则阻塞等待生产者唤醒
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
int global = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
// 三个生产者一次最多生产 1 2 3件商品
void *produce(void *a)
{
    int count = (int)a;
    while (1)
    {
        sleep(3);
        int i = 0;
        printf("生产者%ld准备枪锁\n", pthread_self());
        pthread_mutex_lock(&mutex);
        for (; (i < count) && (global < 6); i++)
        {
            printf("%ld生产了1个,当前产品总数是:%d\n", pthread_self(), ++global);
        }
        if (global == 6)
        {
            printf("仓库满了生产者%ld阻塞\n", pthread_self());
            pthread_cond_broadcast(&cond);    // 唤醒消费者
            pthread_cond_wait(&cond, &mutex); // 释放锁
        }
        else
        {
            pthread_mutex_unlock(&mutex);
        }
    }
}
// 消费者商品0个时阻塞
void *consume(void *a)
{
    while (1)
    {
        sleep(1);
        printf("消费者%ld准备枪锁\n", pthread_self());
        pthread_mutex_lock(&mutex);
        if (global > 0)
        {
            printf("%ld消费了1个,当前产品总数是:%d\n", pthread_self(), --global);
            pthread_mutex_unlock(&mutex); // 释放锁
        }
        else if (global == 0)
        {
            printf("仓库空了消费者%ld阻塞\n", pthread_self());
            pthread_cond_broadcast(&cond);    // 唤醒生产者
            pthread_cond_wait(&cond, &mutex); // 阻塞自己同时释放锁
            printf("%ld被唤醒后又抢到锁了继续执行\n", pthread_self());
        }
    }
}
int main()
{
    int ret;
    pthread_t tids[6];
    for (int i = 0; i < 3; i++)
    {
        ret = pthread_create(&tids[i + 3], NULL, consume, NULL);
        if (ret < 0)
        {
            perror("");
            return -1;
        }
        ret = pthread_create(&tids[i], NULL, produce, i + 1);
        if (ret < 0)
        {
            perror("");
            return -1;
        }
    }
    for (int i = 0; i < 6; i++)
    {
        pthread_join(tids[i], NULL);
    }
    return 0;
}
