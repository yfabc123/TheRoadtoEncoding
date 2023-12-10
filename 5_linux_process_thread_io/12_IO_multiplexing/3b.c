#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#define fifo_file "/home/fifo_file"
int main()
{
    int ret_mkfifo = access(fifo_file, F_OK);
    if (ret_mkfifo == -1)
    {
        mkfifo(fifo_file, 777); // 创建有名管道文件
    }
    int ret_open = open(fifo_file, O_RDWR);
    char buffer[32];
    while (1)
    {
        memset(buffer, 0, 32);
        fgets(buffer, sizeof(buffer), stdin);
        ssize_t write_size = write(ret_open, buffer, 32);
    }
    return 0;
}