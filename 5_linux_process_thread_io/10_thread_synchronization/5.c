#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>
static int number = 0; // 共享变量
static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
void *thread_handler(void *arg)
{
    int cnt = atoi((char *)arg);
    int i, tmp;
    for (i = 0; i < cnt; i++)
    {
        pthread_mutex_lock(&mtx);
        printf("线程 [%ld] 生产一个产品,产品数量为:%d\n", pthread_self(), ++number);
        pthread_mutex_unlock(&mtx); // 解锁后其他生产者进程可能会再次争抢资源
        pthread_cond_signal(&cond); // 唤醒在cond阻塞的消费者线程
        sleep(1);
    }
    pthread_exit((void *)0);
}
int main(int argc, char *argv[])
{
    pthread_t tid;
    int i;
    int err;
    int total_of_produce = 0; // 总的生产产品的数量
    int total_of_consume = 0; // 总的消费产品的数量
    bool done = false;
    for (i = 1; i < argc; i++)
    {
        total_of_produce += atoi(argv[i]); // 生产数量的总和
        err = pthread_create(&tid, NULL, thread_handler, (void *)argv[i]);
        if (err != 0)
        {
            perror("[ERROR] pthread_create(): ");
            exit(EXIT_FAILURE);
        }
    }
    for (;;)
    {
        pthread_mutex_lock(&mtx);
        while (number == 0) // 当产品数量为 0时,让线程阻塞,并释放锁,这里一般设置循环，防止没有重新获取到锁
        {
            pthread_cond_wait(&cond, &mtx); // 1.解锁 2.让线程阻塞  当收到唤醒后 会再次争抢锁
        }
        while (number > 0)
        {
            total_of_consume++; // 消费产品总数
            printf("消费一个产品,产品数量为:%d\n", --number);
            done = total_of_consume >= total_of_produce; // 判断消费者数量与产品数量
        }
        pthread_mutex_unlock(&mtx); // 消费者消费完成之后，释放锁
        if (done)
            break;
    }
}