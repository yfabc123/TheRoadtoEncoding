#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/stat.h>
#include <fcntl.h>
#define FILENAME "/fifo1"
#define PROJECTID 1
int main()
{
    int ret = access(FILENAME, F_OK);
    if (ret == -1)
    {
        perror("mkfifo:");
        return -1;
    }
    int fd = open(FILENAME, O_RDWR);
    if (fd < 0)
    {
        perror("open:");
        return -1;
    }
    // select 监控管道数据
    fd_set readList, readListTemp;
    FD_ZERO(&readList);
    FD_ZERO(&readListTemp);
    FD_SET(fd, &readList);
    struct timeval t1, t2;
    t1.tv_sec = 1;
    t1.tv_usec = 0;
    while (1)
    {
        t2 = t1;
        readListTemp = readList;
        ret = select(fd + 1, &readListTemp, NULL, NULL, &t2);
        if (ret == -1)
        {
            perror("select");
            return -1;
        }
        else if (ret == 0)
        {
            printf("没读取到数据 监听结束\n");
        }
        else if (ret > 0)
        {
            printf("管道有数据\n");
            if (FD_ISSET(fd, &readListTemp)) // 我监听的文件描述符存在返回的集合中
            {
                char buf[32] = {0};
                read(fd, buf, 32);
                write(0, buf, 32);
            }
        }
    }
    return 0;
}