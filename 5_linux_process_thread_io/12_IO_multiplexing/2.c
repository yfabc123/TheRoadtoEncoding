#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
int main(void)
{
    int ret;
    int maxfd = 0; // 我们现在要监控的是标准输入的文件描述符
    fd_set readfds, tmpfds;
    struct timeval tv = {3, 0}, tmp_tv;
    FD_ZERO(&readfds);   // 将文件描述符集合清0
    FD_SET(0, &readfds); // 将标准输入的文件描符加到集合中
    for (;;)
    {
        tmp_tv = tv;
        tmpfds = readfds;
        ret = select(maxfd + 1, &tmpfds, NULL, NULL, &tmp_tv);
        if (ret == -1)
        {
            perror("[ERROR] select(): ");
            exit(EXIT_FAILURE);
        }
        else if (ret == 0)
        { //  超时返回
            printf("Timeout.\n");
        }
        else if (ret > 0)
        {
            if (FD_ISSET(0, &tmpfds))
            { // 判断是否在集合中
                char buffer[64] = {0};
                fgets(buffer, sizeof(buffer), stdin);// fgets也会调用read 所以大大减少了系统调用的次数
                printf("buffer : %s", buffer);
            }
        }
        printf("第一轮结束\n");
    }
    return 0;
}
