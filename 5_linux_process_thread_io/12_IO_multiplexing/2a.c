#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
int main(void)
{
    int ret;
    int maxfd = 0; // 我们现在要监控的是标准输入的文件描述符
    fd_set readfds;
    fd_set readfds_tmp;
    char buffer[64] = {0};
    FD_ZERO(&readfds);     // 将文件描述符集合清0
    FD_ZERO(&readfds_tmp); // 将文件描述符集合清0
    FD_SET(0, &readfds);   // 将标准输入的文件描符加到集合中
    struct timeval tv = {3, 0};
    /*
1.struct timeval tv 设置超时时间是3s  如果3s之后 文件描述符集合没有任何描述就绪就会超时返回
2.tv时间会被select修改 一旦超时 时间就被使用完成 是被赋值了
3.select 每次将就绪文件描述符直接拷贝到原集合中 相当于将没有就绪的文件描述符从集合中删除
如果是超时返回 相当于原集合清空
*/
    struct timeval tv_tmp;
    for (;;)
    {
        tv_tmp = tv;
        readfds_tmp = readfds;
        ret = select(maxfd + 1, &readfds_tmp, NULL, NULL, &tv_tmp);
        if (ret == -1)
        {
            perror("[ERROR] select(): ");
            exit(EXIT_FAILURE);
        }
        else if (ret == 0)
        { //  超时返回
            printf("Timeout.\n");
        }
        else if (ret > 0) // 有文件描述符就绪 但是是哪个文件描述符就绪还需要判断
        {
            printf("%d\n", ret);
            if (FD_ISSET(0, &readfds_tmp)) // 判断标准输入的文件描述符是否在集合中 如果在则表示就绪
            {

                fgets(buffer, sizeof(buffer), stdin);
                printf("buffer : %s\n", buffer);
            }
        }
    }
    return 0;
}
