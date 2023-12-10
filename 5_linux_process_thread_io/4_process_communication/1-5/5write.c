#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#define fifo_file "/home/fifo_file"
int main()
{
    time_t t;
    struct tm *p_datetime;
    t = time(NULL);
    p_datetime = localtime(&t);
    char buffer[64] = {0};
    int ret_open = 0;
    sprintf(buffer, "%d-%d-%d %d:%d:%d\n", p_datetime->tm_year + 1900, p_datetime->tm_mon + 1,
            p_datetime->tm_mday, p_datetime->tm_hour, p_datetime->tm_min, p_datetime->tm_sec);
    int ret_mkfifo = access(fifo_file, F_OK);
    if (ret_mkfifo == -1)
    {
        mkfifo(fifo_file, 777); // 创建有名管道文件
    }
    ret_open = open(fifo_file, O_RDWR);
    if (ret_open == -1)
    {
        perror("open");
        return -1;
    }
    ssize_t write_size = write(ret_open, buffer, 64); // 写入时间数据
    if (write_size == -1)
    {
        perror("write");
        return -1;
    }
    return 0;
}