#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

char buffer[64] = {0}; // 缓冲区
int i = 0;             // 提醒测试
void do_sig()
{
    if (i <= 2)
    {
        i++;
        printf("请尽快输入 已提醒%d次:\n", i);
        alarm(3);
    }
    else
    {
        printf("结束\n");
        exit(EXIT_SUCCESS);
    }
}

int main()
{
    char buffer[64] = {0};
    signal(SIGALRM, do_sig);
    alarm(3);
    scanf("%s", buffer);

    return 0;
}