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
// 使用 select 监听有名管道，当有名管道有数据时，读取数据并打印
/* 逻辑：输入数据到有名管道 然后打印有名管道数据
 */
#define fifo_file "/home/fifo_file"
int main()
{
    int ret_mkfifo = access(fifo_file, F_OK);
    if (ret_mkfifo == -1)
    {
        mkfifo(fifo_file, 777); // 创建有名管道文件
    }
    // 获取管道文件描述符
    int ret_open = open(fifo_file, O_RDWR);
    fd_set read_list; // 定义一个监控集合
    fd_set read_temp;
    FD_ZERO(&read_list);          // 重置集合
    FD_SET(ret_open, &read_list); // 把要监控文件描述符放到集合
    int ret;
    struct timeval __timeout = {3, 0};
    struct timeval __timeout_temp;
    // 循环写入数据
    while (1)
    {
        __timeout_temp = __timeout;
        read_temp = read_list;
        ret = select(ret_open + 1, &read_temp, NULL, NULL, &__timeout_temp);
        if (ret == 0)
        {
            printf("no data\n");
        }
        else if (ret > 0)
        {
            // 当我们输入数据到管道后 打印数据
            char buffer[32] = {0};
            read(ret_open, buffer, 32);
            printf("%s", buffer);
        }
    }
    return 0;
}