#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    int ret;

    pid_t cpid = fork();
    // char *const argv[]={"ls","-l",NULL};
    if (-1 == cpid)

    {
        perror("fork");
    }
    if (cpid == 0)
    {
        sleep(2);
        ret = execl("/bin/ls", "ls", NULL);

        if (ret == -1)
        {
            perror("[ERROR] execl(): ");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        pid_t temp = wait(NULL);
        printf("parent:%d child:%d ", getpid(), temp);
    }
    return 0;
}
