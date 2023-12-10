#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
    pid_t pid = wait(NULL);
    printf("%d", pid);
    return 0;
}