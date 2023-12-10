#include <stdio.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <poll.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

#define fifo "/home/fifo"

int main()
{

    int ret_mkfifo = access(fifo, F_OK);
    if (ret_mkfifo == -1)
    {
        mkfifo(fifo, 777); // 创建有名管道文件
    }
    int ret_open = open(fifo, O_RDWR); // 得到文件描述符

    // 创建epoll实例
    int epfd = epoll_create(1);
    int ret;
    struct epoll_event event;
    event.events = EPOLLIN;
    event.data.fd = ret_open;
    ret = epoll_ctl(epfd, EPOLL_CTL_ADD, ret_open, &event); // 配置监控项
    if (ret == -1)
    {
        perror("epoll_ctl");
    }

    struct epoll_event result_event[10];
    while (1)
    {
        ret = epoll_wait(epfd, result_event, 1, 1000);

        if (ret == 0)
        {
            printf("time out\n");
        }
        else if (ret > 0)
        {
            char buffer[32];
            for (int i = 0; i < 10; i++)
            {
                if (result_event[i].events == EPOLLIN && result_event[i].data.fd == ret_open)
                {
                    // 把管道里数据读到缓冲区
                    read(ret_open, buffer, 32);
                    printf("%s", buffer);
                }
            }
        }
    }

    return 0;
}