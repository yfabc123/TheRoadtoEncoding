#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
void *do_thread(void *arg)
{
    sleep(3);
    printf("Thread start.\n");
   // pthread_exit(NULL);
}
int main(void)
{
    int err;
    pthread_t tid = 0;
    err = pthread_create(&tid, NULL, do_thread, NULL);
    pthread_join(tid, NULL);
    printf(" tid = %ld\n", tid);
    return 0;
}
