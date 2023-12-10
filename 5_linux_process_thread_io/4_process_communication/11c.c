#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
void do_sig_child(int sig)
{
    printf("Receive signal < %s >\n", strsignal(sig));
    wait(NULL);
}
int main(void)
{
    pid_t cpid;
    __sighandler_t sigret;
    sigret = signal(SIGCHLD, do_sig_child);
    if (sigret == SIG_ERR)
    {
        perror("[ERROR] signal(): ");
        exit(EXIT_FAILURE);
    }
    cpid = fork();
    if (cpid == -1)
    {
        perror("[ERROR] fork(): ");
        exit(EXIT_FAILURE);
    }
    else if (cpid == 0)
    {
        printf("Child process < %d > start.\n", getpid());
        sleep(3);
        exit(EXIT_SUCCESS);
    }
    else if (cpid > 0)
    {
        while (1)
        {
            printf("父进程死循环\n");
            sleep(1);
            // 父进程做的事
        }
    }
    return 0;
}
