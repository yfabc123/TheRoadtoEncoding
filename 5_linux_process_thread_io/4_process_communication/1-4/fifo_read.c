#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define FIFO_NAME "/fifo"
int main(int argc, char *argv[])
{
    int fd;
    char rbuffer[64];
    fd = open(FIFO_NAME, O_RDWR);
    if (fd == -1)
    {
        perror("[ERROR] open():");
        exit(EXIT_FAILURE);
    }
    int rbytes;
    rbytes = read(fd, rbuffer, sizeof(rbuffer));
    if (rbytes > 0)
    {
        printf("rbytes : %d rbuffer : %s\n", rbytes, rbuffer);
    }
    close(fd);
    return 0;
}
