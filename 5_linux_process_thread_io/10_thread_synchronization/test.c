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

static int global = 0; // 最大值不超过6个
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *produce1(void *para)
{
    for (int i = 0; i < 1; i++)
    {
        pthread_mutex_lock(&mutex);
        global++;
        printf("produce1 生产了第%d个\n", i + 1);

        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    pthread_exit;
}
void *produce2(void *para)
{
    for (int i = 0; i < 2; i++)
    {
        pthread_mutex_lock(&mutex);
        global++;
        printf("produce2 生产了第%d个\n", i + 1);

        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    pthread_exit;
}
void *produce3(void *para)
{
    for (int i = 0; i < 3; i++)
    {
        pthread_mutex_lock(&mutex);
        global++;
        printf("produce3 生产了第%d个\n", i + 1);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    pthread_exit;
}
void consume()
{
    int produced = 0;
    while (produced < 6)
    {
        pthread_mutex_lock(&mutex);
        if (global == 0)
        {
            pthread_mutex_unlock(&mutex); // 如果没有产品，释放锁，让子线程生产
            continue;
        }
        global--;
        produced++;
        printf("消费者消费了第 %d 个产品\n", produced);
        pthread_mutex_unlock(&mutex);
    }
}

int main()
{
    pthread_t tid[3];
    pthread_create(&tid[0], NULL, produce1, NULL);
    pthread_create(&tid[1], NULL, produce2, NULL);
    pthread_create(&tid[2], NULL, produce3, NULL);

    int ret1 = pthread_detach(tid[0]);
    int ret2 = pthread_detach(tid[1]);
    int ret3 = pthread_detach(tid[2]);
    consume();
    //资源释放  
    
    return 0;
}