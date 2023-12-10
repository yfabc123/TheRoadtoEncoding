#include "head.h"
int main()
{

    pid_t cpid1 = fork();

    if (cpid1 == 0)
    {
        fprintf(stdout, "child %d wait..\n", getpid());
        pause();
        exit(EXIT_SUCCESS);
    }
    if (cpid1 > 0)
    {
        pid_t cpid2 = fork();
        if (cpid2 > 0)
        {
            sleep(3);
            kill(cpid2, SIGKILL);
            kill(cpid1, SIGKILL);
            pid_t temp;
            while ((temp=wait(NULL))!=-1)
            {
               printf("%d child is kill\n",temp);
            }
            
        }
        else
        {
            fprintf(stdout, "child %d wait..\n", getpid());
            pause();
            exit(EXIT_SUCCESS);
        }
    }
    return 0;
}