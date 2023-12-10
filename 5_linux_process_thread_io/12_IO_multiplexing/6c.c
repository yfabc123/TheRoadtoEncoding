#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <poll.h>

#define FILENAME "/fifo"
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
    // poll 监控管道数据
    struct pollfd fds = {0, POLLIN};
    while (1)
    {
        int ret = poll(&fds, 1, 500);
        if (ret == 0)
        {
            printf("超时没读取到数据\n");
        }
        else
        {
            if (fds.revents & POLLIN)
            {
                char buf[64] = {0};
                fgets(buf, 64, stdin);
                printf("buf:%s", buf);
            }
        }
    }

    return 0;
}