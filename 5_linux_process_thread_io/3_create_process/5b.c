#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
int main(void)
{
    pid_t cpid;

    cpid = fork();
    if (cpid == -1)
    {
        perror("[ERROR] fork(): ");
        exit(EXIT_FAILURE);
    }
    else if (cpid == 0)
    {
        printf("The Child process < %d > running...\n", getpid());
        sleep(3);
    }
    else if (cpid > 0)
    {
        cpid = fork();
        if (cpid > 0)
        {

            int rpid, status = 0;
            // rpid = waitpid(-1, &status, 0); // 阻塞型, -1 表示任意进程
            while ((rpid = waitpid(-1, &status, WNOHANG)) != -1)
            {
                printf("%d\n", rpid);
                if (rpid > 0)
                {
                    printf("子进程%d退出,退出状态码:%d\n", rpid, WEXITSTATUS(status));
                }
                sleep(1);
            }
        }
        else
        {
            printf("The Child process < %d > running...\n", getpid());
            sleep(5);
            exit(8);
        }
    }
    return 0;
}
