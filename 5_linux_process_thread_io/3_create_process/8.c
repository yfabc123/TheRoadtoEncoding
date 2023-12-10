#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
// 实现minishell 执行不同的命令
int main()
{
    char cmd[64] = {0};
    int cpid;
    char *argv[3] = {0};
    char buf[32] = {0}; // 拼接命令头
    while (1)
    {
    lable:
        printf("minishell:");
        fflush(stdout);
        fgets(cmd, sizeof(cmd) / sizeof(cmd[0]), stdin);
        cmd[strlen(cmd) - 1] = '\0';
        if (strcmp(cmd, "exit") == 0)
        {
            printf("bye!\n");
            break;
        }
        // 拆分字符串为命令
        argv[0] = strtok(cmd, " "); // 有可能为0
        int i = 1;
        while (argv[i] = strtok(NULL, " "))
        {
            i++;
        }
        if (argv[0] != NULL)
        {
            strcpy(buf, "/bin/");
            strcat(buf, argv[0]);

            cpid = fork();
            if (cpid == 0)
            {
                execv(buf, argv);
                exit(EXIT_SUCCESS);
            }
            else
            {
                printf("子进程:%d结束清理资源\n", wait(NULL));
            }
        }
    }
    return 0;
}