#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define FIFO_NAME "/fifo"
int main(int argc, char *argv[])
{
    int fd;
    char wbuffer[64] = "fifo pipe.";
    int ret;
    ret = access(FIFO_NAME, F_OK); // 判断有名管道文件是否存在
    if (ret == -1)
        mkfifo(FIFO_NAME, 0777);  // 创建管道
    fd = open(FIFO_NAME, O_RDWR); // 打开有名管道
    if (fd == -1)
    {
        perror("[ERROR] open():");
        exit(EXIT_FAILURE);
    }
    int wbytes;
    wbytes = write(fd, wbuffer, strlen(wbuffer) + 1);
    if (wbytes < 0)
        perror("write():");
    close(fd);
    return 0;
}
