#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int main()
{
    int fd;
    char *buffer = "我牛皮啊";

    // 打开文件，以二进制写入模式打开
    fd = open("example.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    // 写入数据到文件
    write(fd, buffer, 3);

    // 创建子进程
    pid_t pid = fork();

    if (pid == -1)
    {
        perror("fork");
        return 1;
    }
    else if (pid == 0)
    {
        // 子进程
        printf("Child Process: ");

        // 子进程设置文件偏移量
        lseek(fd, 0, SEEK_SET);

        // 子进程从文件描述符读取数据
        read(fd, buffer, strlen(buffer));

        // 输出读取到的数据
        write(1, buffer, strlen(buffer));

        printf("\n");

        // 关闭文件描述符
        close(fd);
    }
    else
    {
        // 父进程
        printf("Parent Process: ");

        // 父进程设置文件偏移量
        lseek(fd, 0, SEEK_SET);

        // 父进程从文件描述符读取数据
        read(fd, buffer, 12);

        // 输出读取到的数据
        write(1, buffer, 12);

        printf("\n");

        // 关闭文件描述符
        close(fd);
    }

    return 0;
}
