#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>
#include <sys/stat.h>
#include <signal.h>

void do_alarm(int sig)
{
    printf("Recieve signal < %s >\n", strsignal(sig));
}
int main(void)
{
    unsigned int ret;
    signal(SIGALRM, do_alarm);
    ret = alarm(1);
    pause();
    printf(" main process end .\n");

    return 0;
}