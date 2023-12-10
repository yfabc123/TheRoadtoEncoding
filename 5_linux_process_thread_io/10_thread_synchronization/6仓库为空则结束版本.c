#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
int global = 0;
int consumeCount = 0;
int maxCount = 6;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
// 三个生产者一次最多生产 1 2 3件商品  厂家一共生产6个产品 消费者消费6个产品产品程序结束
void *produce(void *a)
{
    int count = (int)a;
    while (1)
    {
        //  sleep(3);
        for (int i = 0; i < count; i++)
        {
            printf("生产者%ld准备抢锁\n", pthread_self());
            pthread_mutex_lock(&mutex);
            printf("%ld生产了1个,当前产品总数是:%d\n", pthread_self(), ++global);
            pthread_mutex_unlock(&mutex);
            pthread_cond_broadcast(&cond); // 唤醒消费者
        }
        pthread_exit(NULL);
    }
}
// 消费者商品0个时阻塞
void *consume(void *a)
{
    while (1)
    {
        sleep(3);
        printf("消费者%ld准备抢锁\n", pthread_self());
        pthread_mutex_lock(&mutex);
        printf("消费者%ld抢到了锁\n", pthread_self());
        while (global == 0 && consumeCount < maxCount)
        {
            printf("消费者%ld进入死循环逻辑\n", pthread_self());
            pthread_cond_wait(&cond, &mutex);
        }
        printf("消费者%ld过了死循环逻辑\n", pthread_self());
        if (consumeCount == maxCount)
        {
            pthread_mutex_unlock(&mutex);  // 释放锁
            pthread_cond_broadcast(&cond); // 唤醒最后的消费者
            pthread_exit(NULL);
        }
        else if (global > 0)
        {
            printf("%ld消费了1个,当前产品总数是:%d,当前消费总数:%d\n", pthread_self(), --global, ++consumeCount);
            pthread_mutex_unlock(&mutex); // 释放锁
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
        ret = pthread_create(&tids[i], NULL, produce, (void *)(i + 1));
        if (ret < 0)
        {
            perror("");
            return -1;
        }
    }
    for (int i = 0; i < 6; i++)
    {
        pthread_join(tids[i], NULL);
        printf("线程%ld结束\n", tids[i]);
    }
    return 0;
}
