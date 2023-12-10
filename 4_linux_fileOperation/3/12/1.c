#include <stdio.h>
#include <stdlib.h>
int main(int a, char *b[])
{
    char buffer[64];               // 缓冲区
    FILE *fp1 = fopen(b[1], "r+"); // 原文件
    FILE *fp2 = fopen(b[2], "w+"); // 目标文件
    size_t witem = 0;
    size_t ritem = 0;

    if (fp1 == NULL)
    {
        perror("fopen_read");
    }

    if (fp2 == NULL)
    {
        perror("fopen_write");
    }
    ritem = fread(buffer, sizeof(char), 64, fp1);
    while (ritem != 0)
    {
        fwrite(buffer, sizeof(char), 64, fp2);
        ritem = fread(buffer, sizeof(char), 64, fp1);
    }
    fclose(fp1);
    fclose(fp2);

    return 0;
}