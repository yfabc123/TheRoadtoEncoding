#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/epoll.h>
int main()
{
    int ret = 0;
    int epid = epoll_create(1);
    struct epoll_event revent;
    struct epoll_event array[10];
    revent.events = EPOLLIN;
    revent.data.fd = 0;
    ret = epoll_ctl(epid, EPOLL_CTL_ADD, 0, &revent);
    if (ret == -1)
    {
        perror("epoll_ctr()");
        exit(EXIT_FAILURE);
    }
    while (1)
    {
        ret = epoll_wait(epid, array, 10, 700);
        if (ret >= 1)
        {
            for (int i = 0; i < ret; i++)
            {
                if (array[i].data.fd == 0)
                {
                    char buf[32] = {0};
                    fgets(buf, 32, stdin);
                    printf("%s\n", buf);
                }
            }
        }
        else if (ret == 0)
        {
            printf("没输入\n");
        }
    }
    return 0;
}