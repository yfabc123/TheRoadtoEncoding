#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    fputs("hello\n", stdout);
    fork();
    return 0;
}
