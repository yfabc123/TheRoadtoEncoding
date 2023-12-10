#include "head.h"
int main(void)
{
    pid_t cpid;
    cpid = fork();
    if (cpid == -1)
    {
        perror("[ERROR] fork():");
        exit(EXIT_FAILURE);
    }
    else if (cpid == 0)
    {
        fprintf(stdout, "Child Process Start.\n");
        sleep(3);
        kill(getppid(), SIGUSR2);
        exit(EXIT_SUCCESS);
    }
    else if (cpid > 0)
    {
        sleep(1);
        fprintf(stdout, "Main Process Start..\n");
        pause(); // 等待信号,让进程阻塞直到收到信号
        // 不会打印,SIGUSR1 信号的默认动作是终止进程
        fprintf(stdout, "Main Process End.\n");
    }
    return 0;
}
