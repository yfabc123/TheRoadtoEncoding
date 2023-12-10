#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
    int fd[2];
    int ret = pipe(fd);
    int pid = fork();
    if (pid == 0)
    {
        while (1)
        {
            close(fd[1]);
            char buf[64] = {0};
            size_t rbyte = read(fd[0], buf, sizeof(buf));
            if (strncmp(buf, "quit", 4) == 0)
            {
                close(fd[0]);
                exit(EXIT_SUCCESS);
            }
            printf("子进程读取:");
            printf("%s\n", buf);
        }
    }
    else
    {
        int id;
        while (!(id = waitpid(-1, NULL, WNOHANG)))
        {
            printf("id:%d\n", id);
            if (id > 0)
            {
                printf("读端结束 写端也应该结束\n");
                break;
            }
            close(fd[0]);
            printf("父进程写入:");
            char buf[64] = {0};
            fgets(buf, 64, stdin);
            buf[strlen(buf) - 1] = 0;
            size_t wbyte = write(fd[1], buf, strlen(buf));
            sleep(1);
        }
        printf("子进程离开%d\n", id);
        close(fd[1]);
    }
    return 0;
}