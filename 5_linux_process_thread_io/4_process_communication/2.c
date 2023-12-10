#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
// 0 读
int main()
{
    int pipefd[2];
    pipe(pipefd);
    printf("%d-%d-%d\n", pipefd[0], pipefd[1], getpid());
    pid_t cpid = fork();
    if (cpid == -1)
    {
        perror("fork");
    }
    else if (cpid == 0)
    {
        char rbuffer[32] = {0};
        close(pipefd[1]);
        read(pipefd[0], rbuffer, 32);
    }
    else if (cpid > 0)
    {
        char wbuffer[32] = {0};
        close(pipefd[0]);
        write(pipefd[1], wbuffer, 32);
    }
    return 0;
}