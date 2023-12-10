#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
void do_alarm(int sig)
{
    printf("Recieve signal < %s >\n", strsignal(sig));
}
int main(void)
{
    __sighandler_t sigret;
    sigret = signal(SIGALRM, do_alarm);
    if (sigret == SIG_ERR)
    {
        perror("[ERROR] signal(): ");
        exit(EXIT_FAILURE);
    }
    alarm(3);
    pause();
    return 0;
}
