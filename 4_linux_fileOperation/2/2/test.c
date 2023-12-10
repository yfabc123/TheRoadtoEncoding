#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
int main()
{

    int fd;
    ssize_t rbytes = 0; // int 类型
    ssize_t wbytes = 0; // 写入数据
    char wbuffer[] = "ABCDE12345";
    char buffer[64] = {0};
    fd = open("2.txt", O_RDWR | O_CREAT);

    if (fd == -1)
    {
        perror("Open(): ");
        return -1;
    }

    wbytes = write(fd, wbuffer, strlen(wbuffer));
    if (wbytes == -1)
    {
        perror("write: ");
        return -1;
    }

    lseek(fd, -10, SEEK_CUR);
    rbytes = read(fd, buffer, 10);
    if (-1 == rbytes)
    {
        perror("read:");
        return -1;
    }

    printf("buffer: %s\n", buffer);
    close(fd);
    return 0;
}
