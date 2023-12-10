#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    fprintf(stdin, "Linux std io .\n");    // 使用 stdout 输出
    fprintf(stderr, "can't open file.\n"); // 使用 stderr 输出

    char buf[10000] = {0};

    for (int i = 0; i < sizeof(buf) / sizeof(buf[0]); i++)
    {
        buf[i] = 'a';
    }
    printf("%s", buf);
    return 0;
}
