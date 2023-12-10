#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main(void)
{
    int flags, ret;
    char buffer[16] = {0};
    flags = fcntl(0, F_GETFL);      // 获取文件状态标志
    flags |= O_NONBLOCK;            // 增加非阻塞标志
    flags &= ~O_NONBLOCK;           // 取消非阻塞标志
    ret = fcntl(0, F_SETFL, flags); // 设置文件状态标志
    if (ret == -1)
    {
        perror("[ERROR] fcntl(): ");
        exit(EXIT_FAILURE);
    }
    // 非阻塞io会不断检测用户输入 比较消耗cpu资源
    while (1)
    {
        fgets(buffer, sizeof(buffer), stdin);
        if (strlen(buffer) > 0)
        {
            break;
        }
        printf("等待用户输入\n");
        sleep(1);
    }
    return 0;
}
