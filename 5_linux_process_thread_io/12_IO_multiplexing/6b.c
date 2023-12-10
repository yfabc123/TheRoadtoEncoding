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
    char buffer[32] = {0};
    ssize_t wsize;
    while (1)
    {
        memset(buffer, 0, 32);
        fgets(buffer, 32, stdin);            // 标准输入数据读到自定义缓冲区
        wsize = write(ret_open, buffer, 32); // 缓冲区数据放到管道
    }
    return 0;
}