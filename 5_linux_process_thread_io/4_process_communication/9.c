#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
void do_sig_usr(int sig)
{
    printf(" Receive %s \n", strsignal(sig)); // 将信号编号转换成字符串形式
}
int main(void)
{
    pid_t cpid;
    // 设置信号处理方式
    if (signal(SIGUSR1, do_sig_usr) == SIG_ERR)
    {
        perror("[ERROR] signal(): ");
        exit(EXIT_FAILURE);
    }
    cpid = fork();
    if (cpid == -1)
    {
        perror("fork(): ");
        exit(EXIT_FAILURE);
    }
    else if (cpid == 0)
    {
        printf("Child Process < %d > start.\n", getpid());
        pause(); // 等待信号唤醒,这里需要信号到达之前进入睡眠状态
        printf("Child Process < %d > end.\n", getpid());
        exit(EXIT_SUCCESS);
    }
    else if (cpid > 0)
    {
        sleep(1);            // 延时 1s,让子进程先执行
        kill(cpid, SIGUSR1); // 给子进程发送 SIGUSR1 信号
        wait(NULL);          // 等待子进程退出
    }
    return 0;
}
