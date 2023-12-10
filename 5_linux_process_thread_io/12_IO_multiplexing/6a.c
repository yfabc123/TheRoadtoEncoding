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
    struct pollfd p1;
    p1.fd = ret_open;
    p1.events = POLLIN;
    int ret;
    while (1)
    {
        ret = poll(&p1, 1, 1000); // 监控p1结构体中的文件描述符是否可读
        if (ret == 0)
        {
            printf("no data\n");
        }
        else if (ret > 0)
        {
            if (p1.revents == POLLIN)
            {
                char buffer[32] = {0};      // 自定义缓冲区
                read(ret_open, buffer, 32); // 将管道数据读到缓冲区然后输出
                printf("%s", buffer);
            }
        }
    }
    return 0;
}