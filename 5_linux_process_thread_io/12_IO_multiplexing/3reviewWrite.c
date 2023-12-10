#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/stat.h>
#include <fcntl.h>
#define FILENAME "/fifo"
#define PROJECTID 1
// 往管道写输入数据
int main()
{
    int ret;
    if (access(FILENAME, F_OK) != 0)
    {
        ret = mkfifo(FILENAME, 0777);
        if (ret == -1)
        {
            perror("mkfifo:");
            return -1;
        }
    }
    int fd = open(FILENAME, O_RDWR);
    printf("%d\n", fd);
    if (fd < 0)
    {
        perror("open:");
        return -1;
    }
    char buf[64] = {0};
    size_t rbyte;
    while (1)
    {
        rbyte = read(0, buf, sizeof(buf));
        printf("%s\n", buf);
        write(fd, buf, rbyte);
    }
    return 0;
}