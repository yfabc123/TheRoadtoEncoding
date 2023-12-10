#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
void *do_thread(void *arg)
{
    while (1)
    {
        sleep(1);
        printf("子线程\n");
    }
}
int main(void)
{
    int err;
    pthread_t tid = 0;
    err = pthread_create(&tid, NULL, do_thread, NULL);
    if (err != 0)
    {
        fprintf(stderr, "[ERROR] pthread_create : < %s >\n", strerror(err));
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        sleep(1);
        printf("主线程\n");
    }

    printf(" tid = %ld\n", tid);
    return 0;
}
