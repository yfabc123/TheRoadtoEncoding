#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
void fun(int sig)
{
    printf("child process %d Receive %s \n", getpid(), strsignal(sig)); // 将信号编号转换成字符串形式
}
int main()
{
    pid_t cpid1 = fork();
    if (cpid1 == 0)
    {
        printf("child process %d start\n", getpid());
        signal(SIGUSR2, SIG_DFL);
        pause();
        printf("child process %d end\n", getpid());
        exit(EXIT_SUCCESS);
    }
    else if (cpid1 > 0)
    {
        pid_t cpid2 = fork();
        if (cpid2 == 0)
        {
            printf("child process %d start\n", getpid());
            signal(SIGUSR2, fun);
            pause();
            printf("child process %d end\n", getpid());
            exit(EXIT_SUCCESS);
        }
        else if (cpid2 > 0)
        {
            sleep(4);
            kill(cpid1, SIGUSR1);
            kill(cpid2, SIGUSR2);
            wait(NULL);
            wait(NULL);
            printf("child process over\n");
            exit(EXIT_SUCCESS);
        }
    }
    return 0;
}