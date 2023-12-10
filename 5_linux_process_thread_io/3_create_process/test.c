#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
// 创建两个子进程，子进程A 与 子进程 B ,A 进程延时 2s 后退出, B 进程延时 5s 后退出，父进程分别等待两个子进程退出
int main()
{
    pid_t fork_result_A = 0; // 接收创建进程的返回值
    pid_t fork_result_B = 0; // 接收创建进程的返回值
    pid_t wait_A = 0;
    pid_t wait_B = 0;
    pid_t wait_AB = 0;
    int status = 0;
    fork_result_A = fork(); // 默认创建进程成功
    if (0 == fork_result_A)
    {
        printf("A %d running\n", getpid());
        sleep(2);
        printf("A exit\n");
        exit(EXIT_SUCCESS);
    }
    else if (fork_result_A > 0)
    {
        sleep(1);
        fork_result_B = fork();
        if (fork_result_B == 0)
        {
            printf("B %d running\n", getpid());
            sleep(5);
            printf("B exit\n");
            exit(EXIT_SUCCESS);
        }
        else
        {
            while ((wait_AB = wait(NULL)) != -1)
            {
                printf("wait %d  exit \n", wait_AB);
            }
            printf("parent:  exit \n");
        }
    }
    return 0;
}