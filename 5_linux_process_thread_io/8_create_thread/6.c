#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
void *do_thread_one(void *arg)
{
    printf("Thread one start.\n");
    pthread_exit(NULL);
}
void *do_thread_two(void *arg)
{
    printf("Thread two start.\n");
    pthread_exit(NULL);
}
int main(void)
{
    int err;
    pthread_t tid_one = 0, tid_two = 0;
    err = pthread_create(&tid_one, NULL, do_thread_one, NULL);
    if (err != 0)
    {
        fprintf(stderr, "[ERROR] pthread_create : < %s >\n", strerror(err));
        exit(EXIT_FAILURE);
    }
    err = pthread_create(&tid_two, NULL, do_thread_two, NULL);
    if (err != 0)
    {
        fprintf(stderr, "[ERROR] pthread_create : < %s >\n", strerror(err));
        exit(EXIT_FAILURE);
    }
    pthread_join(tid_one, NULL);
    pthread_join(tid_two, NULL);
    return 0;
}
