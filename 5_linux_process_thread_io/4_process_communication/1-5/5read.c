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
    char buffer[64] = {0};
    int ret_open = open(fifo_file, O_RDWR);
    if (ret_open == -1)
    {
        perror("open");
        return -1;
    }
    ssize_t read_size = read(ret_open, buffer, 64);
    if (read_size == -1)
    {
        perror("read");
        return -1;
    }
    printf("%s", buffer);
    return 0;
}