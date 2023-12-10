#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
void* do_thread1(void *a)
{
    printf("child1:\n");
}
void* do_thread2(void *a)
{
    printf("child2:\n");
}
int main()
{
    int errno;
    pthread_t thread1;
    pthread_t thread2;
    pthread_create(&thread1, NULL, do_thread1, NULL);
    pthread_create(&thread2, NULL, do_thread2, NULL);
    printf("%ld-%ld\n", thread1, thread2);
    sleep(1);
}
