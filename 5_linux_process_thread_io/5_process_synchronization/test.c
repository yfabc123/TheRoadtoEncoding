#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define TEXT_SIZE 64

int main(int argc, const char *argv[])
{
    pid_t cpid;
    int ret;
    int pipefd[2];
    char test_buffer[100] = {0};

    ret = pipe(pipefd);
    if (ret == -1)
    {
        perror("pipe() ");
        return -1;
    }

    cpid = fork();
    if (cpid == -1)
    {
        perror("fork() ");
        return -1;
    }
    else if (cpid == 0)
    {
        close(pipefd[1]);
        while (1)
        {

            char receicetxt[TEXT_SIZE] = {0};
            ssize_t readbytes;
            readbytes = read(pipefd[0], receicetxt, TEXT_SIZE);
            if (strncmp(receicetxt, "quit", 4) == 0)
            {
                close(pipefd[0]);
                exit(EXIT_SUCCESS);
            }
            printf("receive: %s\n", receicetxt);
        }
    }
    else if (cpid > 0)
    {
        close(pipefd[0]);
        while (1)
        {
            char keyin[TEXT_SIZE] = {0};
            fgets(keyin, TEXT_SIZE, stdin);
            keyin[strlen(keyin) - 1] = '\0';
            ssize_t writebytes;
            writebytes = write(pipefd[1], keyin, strlen(keyin));

            if (strncmp(keyin, "quit", 4) == 0)
            {
                break;
            }
        }
        lseek(pipefd[0], 0, SEEK_SET); // 测试代码 好像管道数据被读取后就会清零？
        printf("%ld\n", read(pipefd[0], test_buffer, 100));//结果-1

        printf("%s\n", test_buffer);
        close(pipefd[1]);
        wait(NULL);
        exit(EXIT_SUCCESS);
    }
    return 0;
}
