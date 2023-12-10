#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

void *do_thread_one(void *arg)
{
    int i;
    pthread_t tid = pthread_self(); // 获取当前线程的ID
    for (i = 0; i < 5; i++)
    {
        printf("Thread ID %lu: i = %d\n", tid, i); // 打印线程ID
        sleep(1);
    }
    pthread_exit(NULL);
}

int main(void)
{
    int err, i;

    pthread_t tid[2] = {0};

    for (i = 0; i < 2; i++)
    {
        err = pthread_create(&tid[i], NULL, do_thread_one, NULL);
        if (err != 0)
        {
            fprintf(stderr, "[ERROR] pthread_create : < %s >\n", strerror(err));
            exit(EXIT_FAILURE);
        }
        sleep(1);
    }
    sleep(10);
   
    printf("%d", pthread_join(tid[0], NULL));
    printf("%d", pthread_join(tid[1], NULL));

    return 0;
}
