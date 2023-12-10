#include "head.h"
int main(void)
{
    pid_t cpid;
    cpid = fork();
    printf("%d\n", cpid);
    if (cpid < 0)
    {
        perror("[ERROR]  fork() : \n");
        exit(0);
    }
    else if (cpid == 0)
    {
        fprintf(stdout, "\tchild %d running.\n", getpid());
        // SIGSTOP:暂停一个进程 不能阻塞 处理或忽略 只能采用默认操作：
        raise(SIGSTOP);
        fprintf(stdout, "\t child %d exit \n", getpid());
        exit(EXIT_SUCCESS);
    }
    else if (cpid > 0)
    {
        int status, ret;
        sleep(3);
        ret = kill(cpid, SIGKILL); // 给指定进程发送 SIGKILL 信号，只能采用默认操作：结束进程
        if (ret == 0)
        {
            fprintf(stdout, "Father %d Killed child %d\n", getpid(), cpid);
        }
        waitpid(cpid, NULL, 0); // 阻塞等待子进程退出
        fprintf(stdout, "father %d exit\n", getpid());
        exit(EXIT_SUCCESS);
    }
    return 0;
}
