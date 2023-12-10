#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int main(void)
{
    int cpid;
    cpid = fork();
    if (cpid == -1)
    {
        perror("fork(): ");
        exit(EXIT_FAILURE);
    }
    else if (cpid == 0)
    { // first process
        printf("The child process < %d > running...\n", getpid());
        sleep(2);
        printf("The child process < %d > has exited\n", getpid());
        exit(EXIT_SUCCESS);
    }
    else if (cpid > 0)
    {
        cpid = fork();
        if (cpid == -1)
        {

            perror("fork(): ");
        }
        else if (cpid == 0)
        { // second process
            printf("The child process < %d > running...\n", getpid());
            sleep(3);
            printf("The child process < %d > has exited\n", getpid());
            exit(EXIT_SUCCESS);
        }
        else if (cpid > 0)
        {
        }
    }
    return 0;
}
