#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
void *do_thread(void *arg)
{
    while (1)
    {
        printf("1\n");
        sleep(1);
    }
    pthread_exit(NULL);
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
    printf(" tid = %ld\n", tid);
    pthread_detach(tid);

    return 0;
}
