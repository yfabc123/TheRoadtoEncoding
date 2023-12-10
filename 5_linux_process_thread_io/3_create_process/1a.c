#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
int main(void)
{
    pid_t cpid;
    int fd = open("1.txt", O_RDWR | O_CREAT);
    char buf[32] = {0};
    int a = 4;
    int *p = &a;
    cpid = fork();
    if (cpid == -1)
    {
        perror("fork(): ");
        return -1;
    }
    if (0 == cpid)
    {
        sleep(2);
        printf("%p\n", p);
        printf("%d\n", *p);

        lseek(fd, 0, SEEK_SET);
        int n = read(fd, buf, sizeof(buf) / sizeof(buf[0]));
        printf("%d", n);
        write(1, buf, n);
    }
    else
    {
        printf("%p\n", p);
        *p = 3;
        // sleep(1);
        strcpy(buf, "你好");
        write(fd, buf, strlen(buf));
       
    }
    return 0;
}
