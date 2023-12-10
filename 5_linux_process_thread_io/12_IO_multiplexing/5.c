#include <stdio.h>
#include <stdlib.h>
#include <poll.h>
int main(void)
{
    int ret, maxfd = 0;
    struct pollfd pfds; // 也可以定义成数组 只是我们现在只有一个文件描述符
    char buffer[64] = {0};
    pfds.fd = 0;
    pfds.events = POLLIN;
    maxfd = pfds.fd;
    for (;;)
    {
        ret = poll(&pfds, 1, 1000);
        if (ret == -1)
        {
            perror("[ERROR] poll(): ");
            exit(EXIT_FAILURE);
        }
        else if (ret == 0)
        {
            printf("Timeout.\n");
        }
        else if (ret > 0)
        {
            if (pfds.revents & POLLIN)                // 判断指定结构体的revent结果  如果有多个描述符 需要进行遍历
            {                                         // 判断返回的就绪事件是否为 POLLIN
                fgets(buffer, sizeof(buffer), stdin); // 如果是 POLLIN,则表示有用户输入
                printf("buffer :  %s ", buffer);
            }
        }
    }
    return 0;
}
