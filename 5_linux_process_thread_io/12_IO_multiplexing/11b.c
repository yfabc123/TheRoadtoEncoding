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
    char buffer[32];
    while (1)
    {
        memset(buffer, 0, 32);
        fgets(buffer, 32, stdin);
        write(ret_open, buffer, 32);
    }
    return 0;
}