#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
int count = 1;
void handle_alarm(int sig)
{
    if (count > 2)
    {
        exit(EXIT_SUCCESS);
    }
    else
    {
        printf("超时 提醒%d次\n", count);
        count++;
        alarm(2);
    }
}
int main()
{
    char input[100];
    signal(SIGALRM, handle_alarm);
    alarm(2);
    while (1)
    {
        if (fgets(input, sizeof(input), stdin) != NULL)
        {
            alarm(2);  // 刷新超时时间
            count = 1; // 刷新提醒次数
            printf("你输入了: %s", input);
        }
    }
    return 0;
}
