#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
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
        sleep(2);
        exit(88);
    }
    else if (cpid > 0)
    {
        int rpid, status = 0; // 记录状态值
        rpid = wait(&status);
        if (rpid == -1)
        {
            perror("[ERROR] wait() : ");
            exit(EXIT_FAILURE);
        }
        printf("The Child Process < %d > has exited,exit code < %d >.\n", rpid, status); // 通过 WEIXTSTATUS() 宏定义获取
    }
        
    return 0;
}
