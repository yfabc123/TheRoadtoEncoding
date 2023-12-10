#include <stdio.h>
#include <stdlib.h>
#include <sys/epoll.h>
int main(void)
{
    int epfd; 
    epfd = epoll_create(1);
    if (epfd == -1)
    {
        perror("[ERROR] epoll_create(): ");
    }
    printf("epfd = %d\n", epfd);
    return 0;
}
